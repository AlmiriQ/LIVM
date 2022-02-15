/*
(C) M. Ærþ.
*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

//#define LIVMDEBUG
//#define LLLIVMDEBUG
#include "livm.c"


int main() {
	struct VMinst vm = createVM(256); // alloc 256 bytes
	uint64_t vmram[] = { // "proper" way to write out "Hello, LIVM!"
		// start:
		1, 1, 8, 0, // goto code
		// data:
		0x4c202c6f6c6c6548, 0x00000000214d5649, 0, 0, // "Hello, LIVM!"
		// code:
		381, 3, 0, 32, 12, // device.write(console, "Hello, LIVM!", 12) - write string (char*) to console's buffer
		382, 1, 0, // device.out(console) - write out console's buffer
		12, 0 // stop VM
	};
	loadRAM(&vm, vmram, sizeof vmram / sizeof(uint64_t));
	//uint64_t dt[] = {5485433203209299272, 7810728294139909705, 0};
	//puts(((char*)dt));
	runVM(&vm);
	deleteVM(&vm);
	return 0;
}
