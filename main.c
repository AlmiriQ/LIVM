#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>

#include "livm.c" // FUUUUCK

int main() { // FUCK FUCK FUCK, FUCK
	createVM(100); // alloc 100 bytes
	uram64[0] = 11; // poweroff opcode
	runVM(); // run this fucking fuck
	deleteVM(); // delete this shit, oh finally
	return 0; // fuck all this code
}