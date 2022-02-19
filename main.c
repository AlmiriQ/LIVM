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


uint64_t str2u64(char* data) {
	uint64_t* result = (uint64_t*)data;
	return *result;
}


int main() {
	struct VMinst vm = createVM(256); // alloc 256 bytes
	uint64_t vmram[] = { // "proper" way to write out "Hello, LIVM!"
		// start:
		1, 1, 8, 0, // goto code
		// data:
		str2u64("You ente"), str2u64("red:     "), 0, 0,
		// code:
		384, 2, 1, 4,
		383, 4, 1, 48, 4, 0,
		381, 3, 1, 32, 20,
		382, 1, 1,
		12, 0
	};
	loadRAM(&vm, vmram, sizeof vmram / sizeof(uint64_t));
	//uint64_t dt[] = {5485433203209299272, 7810728294139909705, 0};
	//puts(((char*)dt));
	runVM(&vm);
	deleteVM(&vm);
	return 0;
}
