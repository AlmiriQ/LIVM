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
	time_t t[5];
	t[0] = clock();
	struct VMinst vm = createVM(512); // alloc 256 bytes
	uint64_t vmram[] = { // "proper" way to write out "Hello, LIVM!"
		#include "out.fx"
	};
	t[1] = clock();
	loadRAM(&vm, vmram, sizeof vmram / sizeof(uint64_t));
	t[2] = clock();
	//print_ullram(&vm);
	//uint64_t dt[] = {5485433203209299272, 7810728294139909705, 0};
	//puts(((char*)dt));
	runVM(&vm);
	t[3] = clock();
	//print_ullram(&vm);
	deleteVM(&vm);
	t[4] = clock();
	printf("Full execution time: %d, %f\n", t[4] - t[0], (((double)t[4] - t[0])/((double)CLOCKS_PER_SEC)));
	printf("Setup time: %d\n", t[1] - t[0]);
	printf("Boot time: %d\n", t[2] - t[1]);
	printf("Execution time: %d, %f\n", t[3] - t[2], (((double)t[3] - t[2])/((double)CLOCKS_PER_SEC)));
	printf("Clean time: %d\n", t[4] - t[3]);
	return 0;
}
