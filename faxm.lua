local date = require"date"
local opcode = require"faxmopcode"
local FX = {
	--require"faxm/fraCinize",
	require"fraxinizator/string",
	require"fraxinizator/ximplifier",
	require"fraxinizator/fraxevice",
	require"fraxinizator/freeform"
}


local source
local destination = "out.fx"

do
	local parsestate = 0
	for _, a in ipairs(arg) do
		if parsestate == 1 then parsestate = 0; destination = a;
		elseif a:sub(1, 1) == "-" then
			if a == "-o" then parsestate = 1;
			end
		elseif a then source = a end
	end
end

assert(source)


code = {}
data = {}
const = {}
ptr = {
	cptr = {},
	dptr = {}
}

function raw(x) return x end

function string.trim(s)
	local n = s:find"%S"
	return n and s:match(".*%S", n) or ""
end

function string.split(str, sep)
	if sep == nil then
		sep = "%s"
	end
	local t = {}
	for x in string.gmatch(str, "([^"..sep.."]+)") do
		table.insert(t, x)
	end
	return t
end

function string.split_8(str)
	local result = {}
	for i = 0, math.floor(#str / 8) do
		result[#result + 1] = str:sub(i * 8, (i + 1) * 8)
	end
	return result
end


function parseCode(source, code, data)
	for k, v in pairs(FX) do if v.source then source = v.source(source) end end
	print(source)
	local dminsize, cminsize, xtype = -1, -1, "8u"
	local section, segment
	local objects = {}
	for line in source:gmatch("([^;]+)") do
		for k, v in pairs(FX) do if v.any_line then line = v.any_line(line) end end
		if line:sub(1, 1) == '[' then
			for k, v in pairs(date.decode(raw(line:sub(2, #line - 1):gsub("+", ":")))) do
				if type(k) == "number" then
					if v:sub(1, 1) == 'x' then xtype = v:sub(2, #v)
					elseif v == "CODE" then section = code; 
					elseif v == "DATA" then section = data; 
					elseif k == "noalign" then
						if section == code then cminsize = -1 
						else dminsize = -1 end
					end
				elseif k == "align" then
					if section == code then cminsize = v else dminsize = v end
				end
			end
		else
			if #line > 5 and line:sub(1, 6) == "object" then
				segment = { t = "object", p = "data" }
			elseif #line > 7 and line:sub(1, 7) == "section" then
				segment = { t = "section" }
			end
			if segment and segment.t == "object" then
				if line:sub(1, 6) == "object" then
					segment.name = line:sub(8, #line - 1):trim()
					if ptr.dptr[segment.name] then error"equal pointer name" end
					ptr.dptr[segment.name] = #data
					objects[segment.name] = {}
				else
					local vdata, fields = table.unpack(line:split("?"))
					vdata = vdata:trim():gsub(",", " "):gsub("%s+", " ")
					for _, v in ipairs(vdata:split" ") do
						if v:sub(1, 1) == "|" then
							v = v:sub(2)
							if v:sub(1, 1) == "x" then v = "0" .. v end
							v = load("return " .. v)()
							if type(v) == "string" then
								for _, i in ipairs(v:split_8()) do data[#data+1] = i end
							elseif type(v) == "number" then
								data[#data+1] = v
							else error"wrong type"
							end
						end
					end
					fields = fields:trim():gsub(",", " "):gsub("%s+", " ")
					for _, v in ipairs(fields:split(" ")) do
						local k, e = table.unpack(v:split"=")
						e = load("return " .. e:sub(2, #e))()
						if type(e) == "number" then
							objects[segment.name][k] = e
						else error"object fields must be numbers"
						end
					end
				end
			elseif segment and segment.t == "section" then
				if line:sub(1, 7) == "section" then
					segment.name = line:sub(9, #line - 1):trim()
					if ptr.cptr[segment.name] then error"equal pointer name" end
					ptr.cptr[segment.name] = #code
				else
					for k, v in pairs(FX) do if v.line then line = v.line(line) end end
					for i, v in ipairs(line) do
						if i == 1 then
							code[#code + 1] = opcode.getIndex(v)
							code[#code + 1] = #line - 1
						else
							if v:sub(1, 1) == "|" then
								v = v:sub(2)
								if v:sub(1, 1) == "x" then v = "0" .. v end
								if v:gsub("-", ""):gsub("%d", ""):gsub("%.", "") == "" then
									code[#code + 1] = tonumber(v)
								elseif v:gsub("%.", "") then
									code[#code + 1] = load("return (...)." .. v)(objects)
								end
							elseif v:sub(1, 1) == "^" then
								code[#code + 1] = v:sub(1)
							elseif v:sub(1, 1) == "!" then
								code[#code + 1] = v:sub(1)
							elseif v:sub(1, 1) == "#" then
								code[#code + 1] = v:sub(1)
							else error("unknown token") end
						end
					end
				end
			end
		end
	end
	if dminsize > 0 then
		while #data < dminsize do data[#data + 1] = 0 end
	end
	for k, v in pairs(ptr.cptr) do ptr.cptr[k] = v + #data + 8 end
	for i = 1, 4 do code[#code + 1] = 0 end
	for i, v in ipairs(code) do
		if type(v) == "string" then
			if v:sub(1, 1) == "^" then
				code[i] = ptr.dptr[v:sub(2)]
			elseif v:sub(1, 1) == "!" then
				code[i] = ptr.cptr[v:sub(2)] - 8
			elseif v:sub(1, 1) == "#" then
				v = v:sub(2)
				if v:sub(1, 1) == "x" then v = "0" .. v end
				if v:gsub("-", ""):gsub("%d", ""):gsub("%.", "") == "" then
					const[#const + 1] = tonumber(v)
				elseif v:gsub("%.", "") then
					const[#const + 1] = load("return (...)." .. v)(objects)
				end
				code[i] = #data + #code + #const - 1
			else error("unknown expression") end
		end
	end
end

local file = io.open(source)
if file then
	file:seek("set", 0)
	parseCode(file:read"*a", code, data)
	file:close()
end
local loader_segment = {
	--[[
		setdp data
		goto start
		1004 - checksum
	]]--
	opcode.getIndex"setdp", 1, 
	6, opcode.getIndex"goto",
	1, ptr.cptr["start"],
	8, 1004
}
local result = {}
for i, v in ipairs(loader_segment) do result[#result + 1] = v end
for _, v in ipairs(data) do result[#result + 1] = v end
for _, v in ipairs(code) do result[#result + 1] = v end
for _, v in ipairs(const) do result[#result + 1] = v end

file = io.open(destination, "w")
if file then
	for i, v in ipairs(result) do
		if type(v) == "string" then
			for _, v_ in ipairs(v) do file:write('str2u64("'..v..'")') end
		elseif type(v) == "number" then
			file:write(v)
		else error"invalid type" end
		if i < #result then file:write(", ") end
	end
	file:close()
end
