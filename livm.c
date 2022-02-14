void* ram;
  int8_t*   ram8;
 uint8_t*  uram8;
 int16_t*  ram16;
uint16_t* uram16;
 int32_t*  ram32;
uint32_t* uram32;
 int64_t*  ram64;
uint64_t* uram64;
   float*   ramf;
  double*   ramd;

void createVM(uint64_t ram_size) {
	ram    = (malloc(ram_size));
	ram8   = (int8_t*)  ((ram));
	uram8  = (uint8_t*) ((ram));
	ram16  = (int16_t*) ((ram));
	uram16 = (uint16_t*)((ram));
	ram32  = (int32_t*) ((ram));
	uram32 = (uint32_t*)((ram));
	ram64  = (int64_t*) ((ram));
	uram64 = (uint64_t*)((ram));
	ramf   = (float*)   ((ram));
	ramd   = (double*)  ((ram));
}

void deleteVM() {
	free(ram);
}

void runVM() {
	register uint64_t ip = 0, sp = 0, dp = 0;
	register uint64_t op = 0;
	register uint8_t cmp = 0;
	uint64_t args[8];
	while (1) {
		op = uram64[ip++];
		args[0] = 0;
		while((args[0]++ < 6) && (uram64[ip]))
			args[args[0]] = uram64[ip++];
		switch (op) {
			#include "xcase.c"
		}
	}
	end:;
}
