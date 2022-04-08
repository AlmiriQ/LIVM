#define CLOCK vm->devices[0]

void clock_write(struct VMinst* vm, void* data, uint64_t length) {
	printf("clock_write was called. [%p, %p, %lu]", vm, data, length);
	exit(-1);
}

void clock_out(struct VMinst* vm) {
	printf("clock_out was called. [%p]", vm);
	exit(-1);
}

void clock_read(struct VMinst* vm, void* buffer, uint64_t length, uint64_t where) {
	time(((time_t*)buffer));
}

void clock_wait(struct VMinst* vm, uint64_t data) {
	usleep(data);
}

void clock_poweroff(struct VMinst* vm) {
	#ifdef LLLIVMDEBUG
		puts("<clock_poweroff");
	#endif
	free(CLOCK.buffer);
	#ifdef LLLIVMDEBUG
		puts("clock_poweroff>");
	#endif
}

void setup_clock(struct VMinst* vm) {
	CLOCK.buffer = malloc(10240);
	CLOCK.write    = &clock_write;
	CLOCK.out      = &clock_out;
	CLOCK.read     = &clock_read;
	CLOCK.wait     = &clock_wait;
	CLOCK.poweroff = &clock_poweroff;
} 
