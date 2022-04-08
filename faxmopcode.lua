local f = io.open("opcodelist")
local opcodes, reopcodes = {}, {}
for line in f:lines() do if #line > 0 then opcodes[#opcodes + 1] = line end end
f:close()
for k, v in pairs(opcodes) do reopcodes[v] = k end
return {
	getName = function(index) return opcodes[index + 1] end,
	getIndex = function(name) return reopcodes[name] - 1 end
}