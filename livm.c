/*
(C) M. Ærþ.
*/

struct VMinst;
struct IODevice;

struct IODevice { // input/output device
	void* buffer;
	void (*write)(struct VMinst* vm, void* data, uint64_t length);
	void (*out)(struct VMinst* vm);
	void (*read)(struct VMinst* vm, void* buffer, uint64_t length, uint64_t where);
	void (*wait)(struct VMinst* vm, uint64_t data);
	void (*poweroff)(struct VMinst* vm);
};

struct VMinst {
	void*        ram;
	int8_t*     ram8;
	uint8_t*   uram8;
	int16_t*   ram16;
	uint16_t* uram16;
	int32_t*   ram32;
	uint32_t* uram32;
	int64_t*   ram64;
	uint64_t* uram64;
	float*      ramf;
	double*     ramd;

	uint64_t      ip;
	uint64_t      sp;
	uint64_t      dp;

	struct IODevice* devices;
};

#ifdef LIVMDEBUG
# define LIVMCREATION printf("LIVM instance [%p] created.\n", &vm);
# define LIVMSTARTWORK printf("LIVM instance [%p] started.\n", vm)
# define LIVMENDWORK printf("LIVM instance [%p] ended it's work.\n", vm)
# define LIVMDELETING printf("LIVM instance [%p] was deleted.\n", &vm)
# define LIVMARGOVERFLOW { printf("ERROR: arg overflow at [ip=%ld, op=%ld]\n", ip, op); continue; }
#else
# define LIVMCREATION
# define LIVMSTARTWORK
# define LIVMENDWORK
# define LIVMDELETING
# define LIVMARGOVERFLOW continue;
#endif

#include "devices.c"

struct VMinst createVM(uint64_t ram_size) {
	struct VMinst vm;
	vm.ram    = malloc(ram_size);
	if (vm.ram == NULL) exit(-1);
	vm.ram8   = (int8_t*)  vm.ram;
	vm.uram8  = (uint8_t*) vm.ram;
	vm.ram16  = (int16_t*) vm.ram;
	vm.uram16 = (uint16_t*)vm.ram;
	vm.ram32  = (int32_t*) vm.ram;
	vm.uram32 = (uint32_t*)vm.ram;
	vm.ram64  = (int64_t*) vm.ram;
	vm.uram64 = (uint64_t*)vm.ram;
	vm.ramf   = (float*)   vm.ram;
	vm.ramd   = (double*)  vm.ram;
	LIVMCREATION
	dev_init(&vm);
	return vm;
}

struct VMinst* loadRAM(struct VMinst* vm, uint64_t* RAM, uint64_t length) {
	for (uint64_t i = 0; i < length; ++i) vm->uram64[i] = RAM[i];
	return vm;
}

struct VMinst* deleteVM(struct VMinst* vm) {
	LIVMDELETING;
	free(vm->ram);
	dev_delete(vm);
	return vm;
}

void print_ullram(struct VMinst* vm) {
	for (int i = 0; i < 100; i++) printf("%lu ", vm->uram64[i]);
	printf("\n");
}

struct VMinst* runVM(struct VMinst* vm) {
	LIVMSTARTWORK;
	register uint64_t ip = vm->ip,
					  sp = vm->sp,
					  dp = vm->dp;

	register uint64_t op = 0;
	register uint8_t cmp = 0;

	register uint8_t argc  = 0;
	register uint8_t cargc = 0;
	uint64_t args[8];

	register int8_t*     ram8 =   vm->ram8;
	register uint8_t*   uram8 =  vm->uram8;
	register int16_t*   ram16 =  vm->ram16;
	register uint16_t* uram16 = vm->uram16;
	register int32_t*   ram32 =  vm->ram32;
	register uint32_t* uram32 = vm->uram32;
	register int64_t*   ram64 =  vm->ram64;
	register uint64_t* uram64 = vm->uram64;
	register float*      ramf =   vm->ramf;
	register double*     ramd =   vm->ramd;

	struct IODevice* devices = vm->devices;

	while (1) {
		#ifdef LLLIVMDEBUG
			printf("%ld\t|\t", ip);
		#endif
		op = uram64[ip++];
		#ifdef LLLIVMDEBUG
			printf("%ld <- %ld -> %ld\t", uram64[ip - 2], op, uram64[ip + 1]);
		#endif
		argc = uram64[ip++];
		#ifdef LLLIVMDEBUG
			printf("c=%d\t[", argc);
		#endif
		cargc = 0;

		if (argc > 8) LIVMARGOVERFLOW;

		while(cargc < argc)
			args[cargc++] = uram64[ip++];

		#ifdef LLLIVMDEBUG
			for (register uint8_t x = 0; x < (argc - 1); x++)
				printf("%ld, ", args[x]);
			printf("%ld]\n", args[argc - 1]);
		#endif
		switch (op) {
			#include "xcase.c"
		}
		#ifdef LLLIVMDEBUG
			if (getchar() == 'x') {
				print_ullram(vm);
			};
		#endif
	}
	end: LIVMENDWORK;
	vm->ip = ip;
	vm->sp = sp;
	vm->dp = dp;
	return vm;
}

# undef LIVMCREATION
# undef LIVMSTARTWORK
# undef LIVMENDWORK
# undef LIVMDELETING
# undef LIVMARGOVERFLOW