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
	void*        raw_ram;

	uint64_t ram_size;

	uint64_t      ip;
	uint64_t      sp;
	uint64_t      dp;

	struct IODevice* devices;
};

char* dev_rom[] = {"sda"};

#ifndef DEV_ROM_COUNT
# define DEV_ROM_COUNT 0
#endif

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
	vm.ip = 0;
	vm.sp = 0;
	vm.dp = 0;
	vm.raw_ram  = malloc(ram_size);
	vm.ram      = vm.raw_ram;
	vm.ram_size = ram_size;
	if (vm.ram == NULL) exit(-1);
	LIVMCREATION
	dev_init(&vm);
	return vm;
}

struct VMinst* loadRAM(struct VMinst* vm, uint64_t* RAM, uint64_t length) {
	for (uint64_t i = 0; i < length; ++i) ((uint64_t*)vm->raw_ram)[i] = RAM[i];
	return vm;
}

struct VMinst* deleteVM(struct VMinst* vm) {
	LIVMDELETING;
	free(vm->raw_ram);
	dev_delete(vm);
	return vm;
}



void print_ullram(struct VMinst* vm) {
	for (uint64_t i = 0; i < vm->ram_size / 8; i++)
		printf("%p\t|\t%lu\n", ((uint64_t*)vm->ram)+i, ((uint64_t*)vm->raw_ram)[i]);
	printf("\n");
}

struct VMinst* runVM(struct VMinst* vm) {
	LIVMSTARTWORK;
	register uint64_t ip = vm->ip,
					  sp = vm->sp,
					  dp = vm->dp;
	void* raw_ram = vm->raw_ram;
	void* ram = vm->ram;

	register uint64_t op = 0;
	register uint8_t cmp = 0;

	register uint8_t argc  = 0;
	register uint8_t cargc = 0;
	uint64_t args[8];

	#define code_ram ((uint64_t*)raw_ram)
	#define uram64 ((uint64_t*)ram)
	#define ram64 ((int64_t*)ram)
	#define ramd ((double*)ram)
	#define uram32 ((uint32_t*)ram)
	#define ram32 ((int32_t*)ram)
	#define ramf ((float*)ram)
	#define uram16 ((uint16_t*)ram)
	#define ram16 ((int16_t*)ram)
	#define uram8 ((uint8_t*)ram)
	#define ram8 ((int8_t*)ram)

	struct IODevice* devices = vm->devices;

	while (1) {
		#ifdef LLLIVMDEBUG
			printf("%ld\t|\t", ip);
			printf("%ld <- %ld -> %ld\t", code_ram[ip - 1], code_ram[ip], code_ram[ip + 1]);
		#endif
		op = code_ram[ip++];
		argc = code_ram[ip++];
		#ifdef LLLIVMDEBUG
			printf("c=%d\t[", argc);
		#endif
		cargc = 0;

		if (argc > 8) LIVMARGOVERFLOW;

		while(cargc < argc)
			args[cargc++] = code_ram[ip++];

		#ifdef LLLIVMDEBUG
			for (register uint8_t x = 0; x < (argc - 1); x++)
				printf("%ld, ", args[x]);
			if (argc == 0) printf("]\t"); 
			else printf("%ld]\t", args[argc - 1]);
			printf("|\t%lld\n", dp);
		#endif
		switch (op) {
			#include "xcase.c"
		}
		#ifdef LLLIVMDEBUG
			if (getchar() == 'x') {
				print_ullram(vm);
				getchar();
			};
		#endif
	}
	end: LIVMENDWORK;

	#undef code_ram
	#undef uram64
	#undef ram64
	#undef ramd
	#undef uram32
	#undef ram32
	#undef ramf
	#undef uram16p
	#undef ram16
	#undef uram8
	#undef ram8

	vm->ip = ip;
	vm->sp = sp;
	vm->dp = dp;
	vm->ram = ram;
	return vm;
}

# undef LIVMCREATION
# undef LIVMSTARTWORK
# undef LIVMENDWORK
# undef LIVMDELETING
# undef LIVMARGOVERFLOW