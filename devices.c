/*
(C) M. Ærþ.
*/

#define DEV_C 3

#include "device/clock.c"
#include "device/console.c"
#include "device/rom.c"

void dev_init(struct VMinst* vm) {
	vm->devices = (struct IODevice*)malloc(sizeof(struct IODevice) * DEV_C);
	setup_clock(vm);
	setup_console(vm);
	setup_rom(vm);
	#ifdef LIVMDEBUG
		puts("dev_init");
	#endif
}

void dev_delete(struct VMinst* vm) {
	for (uint64_t d = 0; d < DEV_C; d++) vm->devices[d].poweroff(vm);
	free(vm->devices);
	#ifdef LIVMDEBUG
		puts("dev_delete");
	#endif
}