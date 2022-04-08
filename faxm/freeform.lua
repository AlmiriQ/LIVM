return {
	source = function(source)
		return source:gsub("\n", ""):gsub("]", "];"):gsub(":", ":;")
	end,
	any_line = function(line)
		return line:trim():gsub("%s+", " ")
	end,
	line = function(line)
		return line:gsub(",", " "):gsub("%s+", " "):split" "
	end
}