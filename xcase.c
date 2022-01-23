// what is a template/generic?
op = ramu64[ip], arg = ramu64[ip + 1]; 
//printf("%d | %d %d: a[%d] b[%d] c[%d]\n", ip / 2 + 1, op, arg, a, b, c);
//uint8_t dx = getchar();
switch (op) {
	case NOP: break;
	case END: break;
	case LDA: a = xram[arg]; break;
	case LDB: b = xram[arg]; break;
	case LDC: c = xram[arg]; break;
	case ULA: xram[arg] = (xtype) a; break;
	case ULB: xram[arg] = (xtype) b; break;
	case ULC: xram[arg] = (xtype) c; break;
	case CST:
		switch (arg) {
			case 0: break;
			case 1: a = (uint8_t) a; break;
			case 2: a = (int8_t) a; break;
			case 3: a = (uint16_t) a; break;
			case 4: a = (int16_t) a; break;
			case 5: a = (uint32_t) a; break;
			case 6: a = (int32_t) a; break;
			case 7: a = (uint64_t) a; break;
			case 8: a = (int64_t) a; break;
			case 9: a = (float) a; break;
			case 10: a = (double) a; break;
		};
		break;
	case SSM: size_mode = arg; mode_int = 0; break;
	case JMP: ip = a; break;
	case IVE: if (c) ip = a; break;
	case SLE: if (!c) ip = a; break;
	case SIP: a = ip; break;
	case SUB: a -= b; break;
	case SUM: a += b; break;
	case MUL: a *= b; break;
	case DIV: a /= b; break;
	case MOD: a %= b; break;
	case POW: a = pow(a, b); break;
	case INC: a++; break;
	case DEC: a--; break;
	case AND: a &= b; break;
	case BOR: a |= b; break;
	case XOR: a ^= b; break;
	case NOT: a = !a; break;
	case EQU: a = a == b; break;
	case LTH: a = a < b; break;
	case GTH: a = a > b; break;
	case OFR: vm_dev[arg]->offer(a, b, c); break;
	case WAI: vm_dev[arg]->wait(a, b, c); break;
	case OUT: vm_dev[arg]->out(a, b, c); break;
	case REA: a = vm_dev[arg]->read(a, b, c); break;
	case ALC: break;
	case RLC: break;
	case FRE: break;
	case CPY: break;
	case ADD: break;
	case CAT: break;
	case PRC: break;
}
ip += 2;
/*if (dx == '?') {
	getchar();
	for(uint64_t i = 0; i < 50; i++) printf("%u ", ((uint8_t*)d_console.buffer)[i]);
	puts("");
}*/
