#include <stdio.h>


void main() {
	unsigned long long int x[] = {0x6f77206f6c6c6568, 0x0000000000646c72};
	char* y = (char*)x;
	puts(y);
}