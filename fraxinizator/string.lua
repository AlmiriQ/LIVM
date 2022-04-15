return {
	source = function(source)
		local tl = {}
		while source:match[[|"[^"]+"]] do
			local s = source:match[[|"[^"]+"]]
			local ss = s
			s = s:sub(3, #s - 1)
			local r = {}
			for i = 0, math.floor(#s / 8) do
				local t = s:sub(i * 8 + 1, (i + 1) * 8)
				while #t < 8 do t = t .. "\0" end
				t = {string.byte(t, 1, -1)}
				local rt = {}
				for i = 1, 8 do rt[9 - i] = t[i] end
				for i = 1, 8 do rt[i] = string.format("%02x", rt[i]) end
				if table.concat(rt, "") ~= "0000000000000000" then
					r[#r + 1] = "|x" .. table.concat(rt, "")
				end
			end
			if #(r[#r]:gsub("000", "")) == #(r[#r]) then
				r[#r + 1] = "|x0000000000000000"
			end
			local function regexEscape(str)
				return str:gsub("[%(%)%.%%%+%-%*%?%[%^%$%]]", "%%%1")
			end
			local tt = table.concat(r, ", ")
			tl[tt] = #r
			source = source:gsub(regexEscape(ss), tt)
		end
		source = source:gsub("(string%s+(%w+)%s?:(%s+)([|xa-f0-9, ]+)[^;])", function(found)
			found = "object" .. found:sub(7)
			return found .. " ? length=|" .. tostring(tl[found:gsub("object%s+%w+%s?:(%s+)", "")] * 8)
		end)
		return source
	end
}