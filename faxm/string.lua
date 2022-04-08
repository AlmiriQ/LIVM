return {
	source = function(source)
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
			local function regexEscape(str)
				return str:gsub("[%(%)%.%%%+%-%*%?%[%^%$%]]", "%%%1")
			end
			source = source:gsub(regexEscape(ss), table.concat(r, ", "))
		end
		return source
	end
}