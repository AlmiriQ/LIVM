#define CONSOLE vm->devices[1]

void console_write(struct VMinst* vm, void* data, uint64_t length) {
	uint16_t* write_bс = ((uint16_t*)CONSOLE.buffer);
	uint8_t* write_b = (uint8_t*)(CONSOLE.buffer + 2);
	for (uint64_t i = 0; i < length; ++i) {
		if (*write_bс == 5120) return;
		write_b[(*write_bс)++] = ((uint8_t*)data)[i];
	}
}

void console_out(struct VMinst* vm) {
	puts((char*)(CONSOLE.buffer + 2));
	((uint16_t*)CONSOLE.buffer)[0] = 0;
}

void console_read(struct VMinst* vm, void* buffer, uint64_t length, uint64_t where) {
	uint16_t* read_bс = ((uint16_t*)(CONSOLE.buffer + 5120));
	uint8_t* read_b = ((uint8_t*)(CONSOLE.buffer + 5120) + where) + 2;
	for (uint64_t i = 0; i < length; ++i) {
		((uint8_t*)buffer)[i] = read_b[i];
	}
	*read_bс = 0;
}

void console_wait(struct VMinst* vm, uint64_t data) {
	uint16_t* read_bс = ((uint16_t*)(vm->devices[1].buffer + 5120));
	uint8_t* read_b = ((uint8_t*)vm->devices[1].buffer + 5120 + 2);
	printf("enter data: ");
	for (; *read_bс < data;)
		read_b[(*read_bс)++] = getchar();
}

void console_poweroff(struct VMinst* vm) {
	#ifdef LLLIVMDEBUG
		puts("<console_poweroff");
	#endif
	free(CONSOLE.buffer);
	#ifdef LLLIVMDEBUG
		puts("console_poweroff>");
	#endif
}

void setup_console(struct VMinst* vm) {
	CONSOLE.buffer = malloc(10240);
	CONSOLE.write    = &console_write;
	CONSOLE.out      = &console_out;
	CONSOLE.read     = &console_read;
	CONSOLE.wait     = &console_wait;
	CONSOLE.poweroff = &console_poweroff;
}