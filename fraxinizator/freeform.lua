return {
	source = function(source)
		return source:gsub("\n", "")
	end,
	any_line = function(line)
		return line:trim():gsub("%s+", " "):gsub("%s+=%s+", "=")
	end,
	line = function(line)
		return line:gsub(",", " "):gsub("%s+", " "):split" "
	end
}