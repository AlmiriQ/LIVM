/*
(C) M. Ærþ.
*/
 
// control
case 0: break;
case 1: ip = args[0]; break;
case 2: ip = cmp * args[0]; break;
case 3: ip = cmp * args[0] + (1 - cmp) * args[1]; break;
case 4: ip = (1 - cmp) * args[0]; break;
case 5: uram64[args[0]] = ip; break;
case 6: sp = uram64[args[0]]; break;
case 7: sp = args[0]; break;
case 8: uram64[args[0]] = sp; break;
case 9: dp = uram64[args[0]]; break;
case 10: dp = args[0]; break;
case 11: uram64[args[0]] = dp; break;
case 12: goto end; break;
// math
//  u64
case 13: uram64[args[0]] += uram64[args[1]]; break;
case 14: uram64[args[0]] -= uram64[args[1]]; break;
case 15: uram64[args[0]] *= uram64[args[1]]; break;
case 16: uram64[args[0]] /= uram64[args[1]]; break;
case 17: uram64[args[0]] %= uram64[args[1]]; break;
case 18: uram64[args[0]] |= uram64[args[1]]; break;
case 19: uram64[args[0]] &= uram64[args[1]]; break;
case 20: uram64[args[0]] = uram64[args[1]] + uram64[args[2]]; break;
case 21: uram64[args[0]] = uram64[args[1]] - uram64[args[2]]; break;
case 22: uram64[args[0]] = uram64[args[1]] * uram64[args[2]]; break;
case 23: uram64[args[0]] = uram64[args[1]] / uram64[args[2]]; break;
case 24: uram64[args[0]] = uram64[args[1]] % uram64[args[2]]; break;
case 25: uram64[args[0]] = uram64[args[1]] | uram64[args[2]]; break;
case 26: uram64[args[0]] = uram64[args[1]] & uram64[args[2]]; break;
case 27: uram64[args[0]] = !uram64[args[1]]; break;
//  64
case 28: ram64[args[0]] += ram64[args[1]]; break;
case 29: ram64[args[0]] -= ram64[args[1]]; break;
case 30: ram64[args[0]] *= ram64[args[1]]; break;
case 31: ram64[args[0]] /= ram64[args[1]]; break;
case 32: ram64[args[0]] %= ram64[args[1]]; break;
case 33: ram64[args[0]] |= ram64[args[1]]; break;
case 34: ram64[args[0]] &= ram64[args[1]]; break;
case 35: ram64[args[0]] = ram64[args[1]] + ram64[args[2]]; break;
case 36: ram64[args[0]] = ram64[args[1]] - ram64[args[2]]; break;
case 37: ram64[args[0]] = ram64[args[1]] * ram64[args[2]]; break;
case 38: ram64[args[0]] = ram64[args[1]] / ram64[args[2]]; break;
case 39: ram64[args[0]] = ram64[args[1]] % ram64[args[2]]; break;
case 40: ram64[args[0]] = ram64[args[1]] | ram64[args[2]]; break;
case 41: ram64[args[0]] = ram64[args[1]] & ram64[args[2]]; break;
case 42: ram64[args[0]] = !ram64[args[1]]; break;
//  d
case 43: ramd[args[0]] += ramd[args[1]]; break;
case 44: ramd[args[0]] -= ramd[args[1]]; break;
case 45: ramd[args[0]] *= ramd[args[1]]; break;
case 46: ramd[args[0]] /= ramd[args[1]]; break;
case 47: ramd[args[0]] = ramd[args[1]] + ramd[args[2]]; break;
case 48: ramd[args[0]] = ramd[args[1]] - ramd[args[2]]; break;
case 49: ramd[args[0]] = ramd[args[1]] * ramd[args[2]]; break;
case 50: ramd[args[0]] = ramd[args[1]] / ramd[args[2]]; break;
case 51: ramd[args[0]] = !ramd[args[1]]; break;
//  u32
case 52: uram32[args[0]] += uram32[args[1]]; break;
case 53: uram32[args[0]] -= uram32[args[1]]; break;
case 54: uram32[args[0]] *= uram32[args[1]]; break;
case 55: uram32[args[0]] /= uram32[args[1]]; break;
case 56: uram32[args[0]] %= uram32[args[1]]; break;
case 57: uram32[args[0]] |= uram32[args[1]]; break;
case 58: uram32[args[0]] &= uram32[args[1]]; break;
case 59: uram32[args[0]] = uram32[args[1]] + uram32[args[2]]; break;
case 60: uram32[args[0]] = uram32[args[1]] - uram32[args[2]]; break;
case 61: uram32[args[0]] = uram32[args[1]] * uram32[args[2]]; break;
case 62: uram32[args[0]] = uram32[args[1]] / uram32[args[2]]; break;
case 63: uram32[args[0]] = uram32[args[1]] % uram32[args[2]]; break;
case 64: uram32[args[0]] = uram32[args[1]] | uram32[args[2]]; break;
case 65: uram32[args[0]] = uram32[args[1]] & uram32[args[2]]; break;
case 66: uram32[args[0]] = !uram32[args[1]]; break;
//  32
case 67: ram32[args[0]] += ram32[args[1]]; break;
case 68: ram32[args[0]] -= ram32[args[1]]; break;
case 69: ram32[args[0]] *= ram32[args[1]]; break;
case 70: ram32[args[0]] /= ram32[args[1]]; break;
case 71: ram32[args[0]] %= ram32[args[1]]; break;
case 72: ram32[args[0]] |= ram32[args[1]]; break;
case 73: ram32[args[0]] &= ram32[args[1]]; break;
case 74: ram32[args[0]] = ram32[args[1]] + ram32[args[2]]; break;
case 75: ram32[args[0]] = ram32[args[1]] - ram32[args[2]]; break;
case 76: ram32[args[0]] = ram32[args[1]] * ram32[args[2]]; break;
case 77: ram32[args[0]] = ram32[args[1]] / ram32[args[2]]; break;
case 78: ram32[args[0]] = ram32[args[1]] % ram32[args[2]]; break;
case 79: ram32[args[0]] = ram32[args[1]] | ram32[args[2]]; break;
case 80: ram32[args[0]] = ram32[args[1]] & ram32[args[2]]; break;
case 81: ram32[args[0]] = !ram32[args[1]]; break;
//  f
case 82: ramf[args[0]] += ramf[args[1]]; break;
case 83: ramf[args[0]] -= ramf[args[1]]; break;
case 84: ramf[args[0]] *= ramf[args[1]]; break;
case 85: ramf[args[0]] /= ramf[args[1]]; break;
case 86: ramf[args[0]] = ramf[args[1]] + ramf[args[2]]; break;
case 87: ramf[args[0]] = ramf[args[1]] - ramf[args[2]]; break;
case 88: ramf[args[0]] = ramf[args[1]] * ramf[args[2]]; break;
case 89: ramf[args[0]] = ramf[args[1]] / ramf[args[2]]; break;
case 90: ramf[args[0]] = !ramf[args[1]]; break;
//  u16
case 91: uram16[args[0]] += uram16[args[1]]; break;
case 92: uram16[args[0]] -= uram16[args[1]]; break;
case 93: uram16[args[0]] *= uram16[args[1]]; break;
case 94: uram16[args[0]] /= uram16[args[1]]; break;
case 95: uram16[args[0]] %= uram16[args[1]]; break;
case 96: uram16[args[0]] |= uram16[args[1]]; break;
case 97: uram16[args[0]] &= uram16[args[1]]; break;
case 98: uram16[args[0]] = uram16[args[1]] + uram16[args[2]]; break;
case 99: uram16[args[0]] = uram16[args[1]] - uram16[args[2]]; break;
case 100: uram16[args[0]] = uram16[args[1]] * uram16[args[2]]; break;
case 101: uram16[args[0]] = uram16[args[1]] / uram16[args[2]]; break;
case 102: uram16[args[0]] = uram16[args[1]] % uram16[args[2]]; break;
case 103: uram16[args[0]] = uram16[args[1]] | uram16[args[2]]; break;
case 104: uram16[args[0]] = uram16[args[1]] & uram16[args[2]]; break;
case 105: uram16[args[0]] = !uram16[args[1]]; break;
//  16
case 106: ram16[args[0]] += ram16[args[1]]; break;
case 107: ram16[args[0]] -= ram16[args[1]]; break;
case 108: ram16[args[0]] *= ram16[args[1]]; break;
case 109: ram16[args[0]] /= ram16[args[1]]; break;
case 110: ram16[args[0]] %= ram16[args[1]]; break;
case 111: ram16[args[0]] |= ram16[args[1]]; break;
case 112: ram16[args[0]] &= ram16[args[1]]; break;
case 113: ram16[args[0]] = ram16[args[1]] + ram16[args[2]]; break;
case 114: ram16[args[0]] = ram16[args[1]] - ram16[args[2]]; break;
case 115: ram16[args[0]] = ram16[args[1]] * ram16[args[2]]; break;
case 116: ram16[args[0]] = ram16[args[1]] / ram16[args[2]]; break;
case 117: ram16[args[0]] = ram16[args[1]] % ram16[args[2]]; break;
case 118: ram16[args[0]] = ram16[args[1]] | ram16[args[2]]; break;
case 119: ram16[args[0]] = ram16[args[1]] & ram16[args[2]]; break;
case 120: ram16[args[0]] = !ram16[args[1]]; break;
//  u8
case 121: uram8[args[0]] += uram8[args[1]]; break;
case 122: uram8[args[0]] -= uram8[args[1]]; break;
case 123: uram8[args[0]] *= uram8[args[1]]; break;
case 124: uram8[args[0]] /= uram8[args[1]]; break;
case 125: uram8[args[0]] %= uram8[args[1]]; break;
case 126: uram8[args[0]] |= uram8[args[1]]; break;
case 127: uram8[args[0]] &= uram8[args[1]]; break;
case 128: uram8[args[0]] = uram8[args[1]] + uram8[args[2]]; break;
case 129: uram8[args[0]] = uram8[args[1]] - uram8[args[2]]; break;
case 130: uram8[args[0]] = uram8[args[1]] * uram8[args[2]]; break;
case 131: uram8[args[0]] = uram8[args[1]] / uram8[args[2]]; break;
case 132: uram8[args[0]] = uram8[args[1]] % uram8[args[2]]; break;
case 133: uram8[args[0]] = uram8[args[1]] | uram8[args[2]]; break;
case 134: uram8[args[0]] = uram8[args[1]] & uram8[args[2]]; break;
case 135: uram8[args[0]] = !uram8[args[1]]; break;
//  8
case 136: ram8[args[0]] += ram8[args[1]]; break;
case 137: ram8[args[0]] -= ram8[args[1]]; break;
case 138: ram8[args[0]] *= ram8[args[1]]; break;
case 139: ram8[args[0]] /= ram8[args[1]]; break;
case 140: ram8[args[0]] %= ram8[args[1]]; break;
case 141: ram8[args[0]] |= ram8[args[1]]; break;
case 142: ram8[args[0]] &= ram8[args[1]]; break;
case 143: ram8[args[0]] = ram8[args[1]] + ram8[args[2]]; break;
case 144: ram8[args[0]] = ram8[args[1]] - ram8[args[2]]; break;
case 145: ram8[args[0]] = ram8[args[1]] * ram8[args[2]]; break;
case 146: ram8[args[0]] = ram8[args[1]] / ram8[args[2]]; break;
case 147: ram8[args[0]] = ram8[args[1]] % ram8[args[2]]; break;
case 148: ram8[args[0]] = ram8[args[1]] | ram8[args[2]]; break;
case 149: ram8[args[0]] = ram8[args[1]] & ram8[args[2]]; break;
case 150: ram8[args[0]] = !ram8[args[1]]; break;
// ==
case 151: cmp = uram64[args[0]] == uram64[args[1]]; break;
case 152: cmp = ram64[args[0]] == ram64[args[1]]; break;
case 153: cmp = ramd[args[0]] == ramd[args[1]]; break;
case 154: cmp = uram32[args[0]] == uram32[args[1]]; break;
case 155: cmp = ram32[args[0]] == ram32[args[1]]; break;
case 156: cmp = ramf[args[0]] == ramf[args[1]]; break;
case 157: cmp = uram16[args[0]] == uram16[args[1]]; break;
case 158: cmp = ram16[args[0]] == ram16[args[1]]; break;
case 159: cmp = uram8[args[0]] == uram8[args[1]]; break;
case 160: cmp = ram8[args[0]] == ram8[args[1]]; break;
// !=
case 161: cmp = uram64[args[0]] != uram64[args[1]]; break;
case 162: cmp = ram64[args[0]] != ram64[args[1]]; break;
case 163: cmp = ramd[args[0]] != ramd[args[1]]; break;
case 164: cmp = uram32[args[0]] != uram32[args[1]]; break;
case 165: cmp = ram32[args[0]] != ram32[args[1]]; break;
case 166: cmp = ramf[args[0]] != ramf[args[1]]; break;
case 167: cmp = uram16[args[0]] != uram16[args[1]]; break;
case 168: cmp = ram16[args[0]] != ram16[args[1]]; break;
case 169: cmp = uram8[args[0]] != uram8[args[1]]; break;
case 170: cmp = ram8[args[0]] != ram8[args[1]]; break;
// >
case 171: cmp = uram64[args[0]] > uram64[args[1]]; break;
case 172: cmp = ram64[args[0]] > ram64[args[1]]; break;
case 173: cmp = ramd[args[0]] > ramd[args[1]]; break;
case 174: cmp = uram32[args[0]] > uram32[args[1]]; break;
case 175: cmp = ram32[args[0]] > ram32[args[1]]; break;
case 176: cmp = ramf[args[0]] > ramf[args[1]]; break;
case 177: cmp = uram16[args[0]] > uram16[args[1]]; break;
case 178: cmp = ram16[args[0]] > ram16[args[1]]; break;
case 179: cmp = uram8[args[0]] > uram8[args[1]]; break;
case 180: cmp = ram8[args[0]] > ram8[args[1]]; break;
// <
case 181: cmp = uram64[args[0]] < uram64[args[1]]; break;
case 182: cmp = ram64[args[0]] < ram64[args[1]]; break;
case 183: cmp = ramd[args[0]] < ramd[args[1]]; break;
case 184: cmp = uram32[args[0]] < uram32[args[1]]; break;
case 185: cmp = ram32[args[0]] < ram32[args[1]]; break;
case 186: cmp = ramf[args[0]] < ramf[args[1]]; break;
case 187: cmp = uram16[args[0]] < uram16[args[1]]; break;
case 188: cmp = ram16[args[0]] < ram16[args[1]]; break;
case 189: cmp = uram8[args[0]] < uram8[args[1]]; break;
case 190: cmp = ram8[args[0]] < ram8[args[1]]; break;
// >=
case 191: cmp = uram64[args[0]] >= uram64[args[1]]; break;
case 192: cmp = ram64[args[0]] >= ram64[args[1]]; break;
case 193: cmp = ramd[args[0]] >= ramd[args[1]]; break;
case 194: cmp = uram32[args[0]] >= uram32[args[1]]; break;
case 195: cmp = ram32[args[0]] >= ram32[args[1]]; break;
case 196: cmp = ramf[args[0]] >= ramf[args[1]]; break;
case 197: cmp = uram16[args[0]] >= uram16[args[1]]; break;
case 198: cmp = ram16[args[0]] >= ram16[args[1]]; break;
case 199: cmp = uram8[args[0]] >= uram8[args[1]]; break;
case 200: cmp = ram8[args[0]] >= ram8[args[1]]; break;
// <=
case 201: cmp = uram64[args[0]] <= uram64[args[1]]; break;
case 202: cmp = ram64[args[0]] <= ram64[args[1]]; break;
case 203: cmp = ramd[args[0]] <= ramd[args[1]]; break;
case 204: cmp = uram32[args[0]] <= uram32[args[1]]; break;
case 205: cmp = ram32[args[0]] <= ram32[args[1]]; break;
case 206: cmp = ramf[args[0]] <= ramf[args[1]]; break;
case 207: cmp = uram16[args[0]] <= uram16[args[1]]; break;
case 208: cmp = ram16[args[0]] <= ram16[args[1]]; break;
case 209: cmp = uram8[args[0]] <= uram8[args[1]]; break;
case 210: cmp = ram8[args[0]] <= ram8[args[1]]; break;
// ++
case 211: uram64[args[0]]++; break;
case 212: ram64[args[0]]++; break;
case 213: ramd[args[0]]++; break;
case 214: uram32[args[0]]++; break;
case 215: ram32[args[0]]++; break;
case 216: ramf[args[0]]++; break;
case 217: uram16[args[0]]++; break;
case 218: ram16[args[0]]++; break;
case 219: uram8[args[0]]++; break;
case 220: ram8[args[0]]++; break;
// --
case 221: uram64[args[0]]--; break;
case 222: ram64[args[0]]--; break;
case 223: ramd[args[0]]--; break;
case 224: uram32[args[0]]--; break;
case 225: ram32[args[0]]--; break;
case 226: ramf[args[0]]--; break;
case 227: uram16[args[0]]--; break;
case 228: ram16[args[0]]--; break;
case 229: uram8[args[0]]--; break;
case 230: ram8[args[0]]--; break;
// a = b
case 231: uram64[args[0]] = (uint64_t)args[1]; break;
case 232: ram64[args[0]] = (int64_t)args[1]; break;
case 233: ramd[args[0]] = (int64_t)args[1]; break;
case 234: uram32[args[0]] = (uint32_t)args[1]; break;
case 235: ram32[args[0]] = (int32_t)args[1]; break;
case 236: ramf[args[0]] = (int32_t)args[1]; break;
case 237: uram16[args[0]] = (uint16_t)args[1]; break;
case 238: ram16[args[0]] = (int16_t)args[1]; break;
case 239: uram8[args[0]] = (uint8_t)args[1]; break;
case 240: ram8[args[0]] = (int8_t)args[1]; break;
// a = *b
case 241: uram64[args[0]] = uram64[args[1]]; break;
case 242: ram64[args[0]] = ram64[args[1]]; break;
case 243: ramd[args[0]] = ramd[args[1]]; break;
case 244: uram32[args[0]] = uram32[args[1]]; break;
case 245: ram32[args[0]] = ram32[args[1]]; break;
case 246: ramf[args[0]] = ramf[args[1]]; break;
case 247: uram16[args[0]] = uram16[args[1]]; break;
case 248: ram16[args[0]] = ram16[args[1]]; break;
case 249: uram8[args[0]] = uram8[args[1]]; break;
case 250: ram8[args[0]] = ram8[args[1]]; break;
// a = **b
case 251: uram64[args[0]] = uram64[uram64[args[1]]]; break;
case 252: ram64[args[0]] = ram64[uram64[args[1]]]; break;
case 253: ramd[args[0]] = ramd[uram64[args[1]]]; break;
case 254: uram32[args[0]] = uram32[uram64[args[1]]]; break;
case 255: ram32[args[0]] = ram32[uram64[args[1]]]; break;
case 256: ramf[args[0]] = ramf[uram64[args[1]]]; break;
case 257: uram16[args[0]] = uram16[uram64[args[1]]]; break;
case 258: ram16[args[0]] = ram16[uram64[args[1]]]; break;
case 259: uram8[args[0]] = uram8[uram64[args[1]]]; break;
case 260: ram8[args[0]] = ram8[uram64[args[1]]]; break;
// **a = b
case 261: uram64[uram64[args[0]]] = (uint64_t) args[1]; break;
case 262: ram64[uram64[args[0]]] = (int64_t) args[1]; break;
case 263: ramd[uram64[args[0]]] = (double) args[1]; break;
case 264: uram32[uram64[args[0]]] = (uint32_t) args[1]; break;
case 265: ram32[uram64[args[0]]] = (int32_t) args[1]; break;
case 266: ramf[uram64[args[0]]] = (float) args[1]; break;
case 267: uram16[uram64[args[0]]] = (uint16_t) args[1]; break;
case 268: ram16[uram64[args[0]]] = (int16_t) args[1]; break;
case 269: uram8[uram64[args[0]]] = (uint8_t) args[1]; break;
case 270: ram8[uram64[args[0]]] = (int8_t) args[1]; break;
// **a = *b
case 271: uram64[uram64[args[0]]] = uram64[args[1]]; break;
case 272: ram64[uram64[args[0]]] = ram64[args[1]]; break;
case 273: ramd[uram64[args[0]]] = ramd[args[1]]; break;
case 274: uram32[uram64[args[0]]] = uram32[args[1]]; break;
case 275: ram32[uram64[args[0]]] = ram32[args[1]]; break;
case 276: ramf[uram64[args[0]]] = ramf[args[1]]; break;
case 277: uram16[uram64[args[0]]] = uram16[args[1]]; break;
case 278: ram16[uram64[args[0]]] = ram16[args[1]]; break;
case 279: uram8[uram64[args[0]]] = uram8[args[1]]; break;
case 280: ram8[uram64[args[0]]] = ram8[args[1]]; break;
// **a = **b
case 281: uram64[uram64[args[0]]] = uram64[uram64[args[1]]]; break;
case 282: ram64[uram64[args[0]]] = ram64[uram64[args[1]]]; break;
case 283: ramd[uram64[args[0]]] = ramd[uram64[args[1]]]; break;
case 284: uram32[uram64[args[0]]] = uram32[uram64[args[1]]]; break;
case 285: ram32[uram64[args[0]]] = ram32[uram64[args[1]]]; break;
case 286: ramf[uram64[args[0]]] = ramf[uram64[args[1]]]; break;
case 287: uram16[uram64[args[0]]] = uram16[uram64[args[1]]]; break;
case 288: ram16[uram64[args[0]]] = ram16[uram64[args[1]]]; break;
case 289: uram8[uram64[args[0]]] = uram8[uram64[args[1]]]; break;
case 290: ram8[uram64[args[0]]] = ram8[uram64[args[1]]]; break;
// cast
case 291: uram64[args[0]] = (uint64_t)ram64[args[1]]; break;
case 292: uram64[args[0]] = (uint64_t)ramd[args[1]]; break;
case 293: uram64[args[0]] = (uint64_t)uram32[args[1]]; break;
case 294: uram64[args[0]] = (uint64_t)ram32[args[1]]; break;
case 295: uram64[args[0]] = (uint64_t)ramf[args[1]]; break;
case 296: uram64[args[0]] = (uint64_t)uram16[args[1]]; break;
case 297: uram64[args[0]] = (uint64_t)ram16[args[1]]; break;
case 298: uram64[args[0]] = (uint64_t)uram8[args[1]]; break;
case 299: uram64[args[0]] = (uint64_t)ram8[args[1]]; break;
case 300: ram64[args[0]] = (int64_t)uram64[args[1]]; break;
case 301: ram64[args[0]] = (int64_t)ramd[args[1]]; break;
case 302: ram64[args[0]] = (int64_t)uram32[args[1]]; break;
case 303: ram64[args[0]] = (int64_t)ram32[args[1]]; break;
case 304: ram64[args[0]] = (int64_t)ramf[args[1]]; break;
case 305: ram64[args[0]] = (int64_t)uram16[args[1]]; break;
case 306: ram64[args[0]] = (int64_t)ram16[args[1]]; break;
case 307: ram64[args[0]] = (int64_t)uram8[args[1]]; break;
case 308: ram64[args[0]] = (int64_t)ram8[args[1]]; break;
case 309: ramd[args[0]] = (double)uram64[args[1]]; break;
case 310: ramd[args[0]] = (double)ram64[args[1]]; break;
case 311: ramd[args[0]] = (double)uram32[args[1]]; break;
case 312: ramd[args[0]] = (double)ram32[args[1]]; break;
case 313: ramd[args[0]] = (double)ramf[args[1]]; break;
case 314: ramd[args[0]] = (double)uram16[args[1]]; break;
case 315: ramd[args[0]] = (double)ram16[args[1]]; break;
case 316: ramd[args[0]] = (double)uram8[args[1]]; break;
case 317: ramd[args[0]] = (double)ram8[args[1]]; break;
case 318: uram32[args[0]] = (uint32_t)uram64[args[1]]; break;
case 319: uram32[args[0]] = (uint32_t)ram64[args[1]]; break;
case 320: uram32[args[0]] = (uint32_t)ramd[args[1]]; break;
case 321: uram32[args[0]] = (uint32_t)ram32[args[1]]; break;
case 322: uram32[args[0]] = (uint32_t)ramf[args[1]]; break;
case 323: uram32[args[0]] = (uint32_t)uram16[args[1]]; break;
case 324: uram32[args[0]] = (uint32_t)ram16[args[1]]; break;
case 325: uram32[args[0]] = (uint32_t)uram8[args[1]]; break;
case 326: uram32[args[0]] = (uint32_t)ram8[args[1]]; break;
case 327: ram32[args[0]] = (int32_t)uram64[args[1]]; break;
case 328: ram32[args[0]] = (int32_t)ram64[args[1]]; break;
case 329: ram32[args[0]] = (int32_t)ramd[args[1]]; break;
case 330: ram32[args[0]] = (int32_t)uram32[args[1]]; break;
case 331: ram32[args[0]] = (int32_t)ramf[args[1]]; break;
case 332: ram32[args[0]] = (int32_t)uram16[args[1]]; break;
case 333: ram32[args[0]] = (int32_t)ram16[args[1]]; break;
case 334: ram32[args[0]] = (int32_t)uram8[args[1]]; break;
case 335: ram32[args[0]] = (int32_t)ram8[args[1]]; break;
case 336: ramf[args[0]] = (float)uram64[args[1]]; break;
case 337: ramf[args[0]] = (float)ram64[args[1]]; break;
case 338: ramf[args[0]] = (float)ramd[args[1]]; break;
case 339: ramf[args[0]] = (float)uram32[args[1]]; break;
case 340: ramf[args[0]] = (float)ram32[args[1]]; break;
case 341: ramf[args[0]] = (float)uram16[args[1]]; break;
case 342: ramf[args[0]] = (float)ram16[args[1]]; break;
case 343: ramf[args[0]] = (float)uram8[args[1]]; break;
case 344: ramf[args[0]] = (float)ram8[args[1]]; break;
case 345: uram16[args[0]] = (uint16_t)uram64[args[1]]; break;
case 346: uram16[args[0]] = (uint16_t)ram64[args[1]]; break;
case 347: uram16[args[0]] = (uint16_t)ramd[args[1]]; break;
case 348: uram16[args[0]] = (uint16_t)uram32[args[1]]; break;
case 349: uram16[args[0]] = (uint16_t)ram32[args[1]]; break;
case 350: uram16[args[0]] = (uint16_t)ramf[args[1]]; break;
case 351: uram16[args[0]] = (uint16_t)ram16[args[1]]; break;
case 352: uram16[args[0]] = (uint16_t)uram8[args[1]]; break;
case 353: uram16[args[0]] = (uint16_t)ram8[args[1]]; break;
case 354: ram16[args[0]] = (int16_t)uram64[args[1]]; break;
case 355: ram16[args[0]] = (int16_t)ram64[args[1]]; break;
case 356: ram16[args[0]] = (int16_t)ramd[args[1]]; break;
case 357: ram16[args[0]] = (int16_t)uram32[args[1]]; break;
case 358: ram16[args[0]] = (int16_t)ram32[args[1]]; break;
case 359: ram16[args[0]] = (int16_t)ramf[args[1]]; break;
case 360: ram16[args[0]] = (int16_t)uram16[args[1]]; break;
case 361: ram16[args[0]] = (int16_t)uram8[args[1]]; break;
case 362: ram16[args[0]] = (int16_t)ram8[args[1]]; break;
case 363: uram8[args[0]] = (uint8_t)uram64[args[1]]; break;
case 364: uram8[args[0]] = (uint8_t)ram64[args[1]]; break;
case 365: uram8[args[0]] = (uint8_t)ramd[args[1]]; break;
case 366: uram8[args[0]] = (uint8_t)uram32[args[1]]; break;
case 367: uram8[args[0]] = (uint8_t)ram32[args[1]]; break;
case 368: uram8[args[0]] = (uint8_t)ramf[args[1]]; break;
case 369: uram8[args[0]] = (uint8_t)uram16[args[1]]; break;
case 370: uram8[args[0]] = (uint8_t)ram16[args[1]]; break;
case 371: uram8[args[0]] = (int8_t)ram8[args[1]]; break;
case 372: ram8[args[0]] = (int8_t)uram64[args[1]]; break;
case 373: ram8[args[0]] = (int8_t)ram64[args[1]]; break;
case 374: ram8[args[0]] = (int8_t)ramd[args[1]]; break;
case 375: ram8[args[0]] = (int8_t)uram32[args[1]]; break;
case 376: ram8[args[0]] = (int8_t)ram32[args[1]]; break;
case 377: ram8[args[0]] = (int8_t)ramf[args[1]]; break;
case 378: ram8[args[0]] = (int8_t)uram16[args[1]]; break;
case 379: ram8[args[0]] = (int8_t)ram16[args[1]]; break;
case 380: ram8[args[0]] = (int8_t)uram8[args[1]]; break;
// io dev
case 381: devices[args[0]].write(vm, uram8 + args[1], args[2]); break;
case 382: devices[args[0]].out(vm); break;
case 383: devices[args[0]].read(vm, uram8 + args[1], args[2], args[3]); break;
case 384: devices[args[0]].wait(vm, args[1]); break;
