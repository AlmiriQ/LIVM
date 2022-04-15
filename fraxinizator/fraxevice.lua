return {
	source = function(source)
		source = source:gsub("(%s*)console%.print%s+(%S+%s+%S+);", "%1console.write %2;%1console.out;")		
		source = source:gsub("(%a+)%.write", "write ____%1")
		source = source:gsub("(%a+)%.out", "out ____%1")
		source = source:gsub("(%a+)%.wait", "wait ____%1")
		source = source:gsub("(%a+)%.read", "read ____%1")
		source = source:gsub("____clock", "|0")
		source = source:gsub("____timer", "|0")
		source = source:gsub("____console", "|1")
		source = source:gsub("____rom", "|2")
		return source
	end
} 