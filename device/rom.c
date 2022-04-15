#define ROM vm->devices[2]

void rom_write(struct VMinst* vm, void* data, uint64_t length) {
	if (length == 0) ((uint64_t*)ROM.buffer)[0] = (uint64_t)data;
	else fwrite(data, sizeof(uint8_t), length, ((FILE**)(ROM.buffer))[1024 * 256 / 8 - 1 - ((uint64_t*)ROM.buffer)[0]]);
}

void rom_out(struct VMinst* vm) {
	printf("rom_out was called. [%p]", vm);
	exit(-1);
}

void rom_read(struct VMinst* vm, void* buffer, uint64_t length, uint64_t where) {
	fread(buffer, sizeof(uint8_t), length, ((FILE**)(ROM.buffer))[1024 * 256 / 8 - 1 - ((uint64_t*)ROM.buffer)[0]]);
}

void rom_wait(struct VMinst* vm, uint64_t data) {
	fseek(((FILE**)(ROM.buffer))[1024 * 256 / 8 - 1 - ((uint64_t*)ROM.buffer)[0]], data, SEEK_SET);
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
	((uint64_t*)ROM.buffer)[0] = 0;
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
		((uint64_t**)ROM.buffer)[1024 * 256 / 8 - 1 - i] = (uint64_t*) fopen(dev_rom[i], "wb+");
	}
} 
