/*
(C) M. Ærþ.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <inttypes.h>
#include <math.h>

// #define LIVMDEBUG
// #define LLLIVMDEBUG
#include "livm.c"


uint64_t str2u64(char* data) {
	uint64_t* result = (uint64_t*)data;
	return *result;
}


int main() {
	struct VMinst vm = createVM(512); // alloc 256 bytes
	uint64_t vmram[] = { // "proper" way to write out "Hello, LIVM!"
		#include "out.fx"
	};
	loadRAM(&vm, vmram, sizeof vmram / sizeof(uint64_t));
	//print_ullram(&vm);
	//uint64_t dt[] = {5485433203209299272, 7810728294139909705, 0};
	//puts(((char*)dt));
	runVM(&vm);
	//print_ullram(&vm);
	deleteVM(&vm);
	return 0;
}
