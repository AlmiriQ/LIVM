return {
	source = function(source)
		source = source:gsub("%(([^)]+)%)", " %1")
		source = source:gsub("([|%^#][%w.]+%s+)([a-z]+)", "%1;%2"):gsub(":", ":;")
		source = source:gsub("object", ";object"):gsub("section", ";section"):gsub("%[", ";["):gsub("%]", "];")
		source = source:gsub("(\n%s+);", ";%1"):gsub(";(%s+);", ";%1"):gsub("^;", "")
		return source .. ";"
	end
}