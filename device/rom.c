#define ROM vm->devices[2]

void rom_write(struct VMinst* vm, void* data, uint64_t length) {
	printf("rom_write was called. [%p, %p, %lu]", vm, data, length);
	exit(-1);
}

void rom_out(struct VMinst* vm) {
	printf("rom_out was called. [%p]", vm);
	exit(-1);
}

void rom_read(struct VMinst* vm, void* buffer, uint64_t length, uint64_t where) {
	
}

void rom_wait(struct VMinst* vm, uint64_t data) {
}

void rom_poweroff(struct VMinst* vm) {
	#ifdef LLLIVMDEBUG
		puts("<rom_poweroff");
	#endif
	free(ROM.buffer);
	#ifdef LLLIVMDEBUG
		puts("rom_poweroff>");
	#endif
}

void setup_rom(struct VMinst* vm) {
	ROM.buffer = malloc(1024 * 256);
	ROM.write    = &rom_write;
	ROM.out      = &rom_out;
	ROM.read     = &rom_read;
	ROM.wait     = &rom_wait;
	ROM.poweroff = &rom_poweroff;
	if (DEV_ROM_COUNT > 8) {
		puts("Error: DEV_ROM_COUNT must be <= 8.");
		exit(-1);
	}
	for (int i = 0; i < DEV_ROM_COUNT; ++i) {
		((uint64_t**)ROM.buffer)[1024 * 32 - 8 + i] = (uint64_t*) fopen(dev_rom[i], "rb+");
	}
} 
