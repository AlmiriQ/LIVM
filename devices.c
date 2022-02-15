#define DEV_C 1

void c_write(struct VMinst* vm, void* data, uint64_t length) {
	uint16_t* write_bс = ((uint16_t*)vm->devices[0].buffer);
	uint8_t* write_b = (uint8_t*)(vm->devices[0].buffer + 2);
	for (uint64_t i = 0; i < length; ++i) {
		if (*write_bс == 5120) return;
		write_b[(*write_bс)++] = ((uint8_t*)data)[i];
	}
}

void c_out(struct VMinst* vm) {
	puts((char*)(vm->devices[0].buffer + 2));
}

void c_read(struct VMinst* vm, void* buffer, uint64_t length, uint64_t where) {
	uint16_t* read_bс = ((uint16_t*)(vm->devices[0].buffer + 5120));
	uint8_t* read_b = ((uint8_t*)(vm->devices[0].buffer + 5120) + where) + 2;
	for (uint64_t i = 0; i < length; ++i) {
		((uint8_t*)buffer)[i] = read_b[i + 1];
	}
	*read_bс = 0;
}

void c_wait(struct VMinst* vm, uint64_t data) {
	uint16_t* read_bс = ((uint16_t*)(vm->devices[0].buffer + 5120));
	uint8_t* read_b = ((uint8_t*)vm->devices[0].buffer + 5120);
	for (uint64_t i = 0; i < data; i++) {
		if (*read_bс == 5120) return;
		read_b[++(*read_bс)] = getchar();
	}
}

void c_poweroff(struct VMinst* vm) {
	free(vm->devices[0].buffer);
}

void setup_console(struct VMinst* vm) {
	vm->devices[0].buffer = malloc(10240);
	vm->devices[0].write    = &c_write;
	vm->devices[0].out      = &c_out;
	vm->devices[0].read     = &c_read;
	vm->devices[0].wait     = &c_wait;
	vm->devices[0].poweroff = &c_poweroff;
}

void dev_init(struct VMinst* vm) {
	vm->devices = (struct IODevice*)malloc(sizeof(struct IODevice) * 1);
	setup_console(vm);
}

void dev_delete(struct VMinst* vm) {
	for (uint64_t d = 0; d < DEV_C; d++) vm->devices[d].poweroff(vm);
	free(vm->devices);
}