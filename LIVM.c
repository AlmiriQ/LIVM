uint64_t pc, cc; 
void* ram; 

uint8_t* ramu8; 
uint16_t* ramu16; 
uint32_t* ramu32; 
uint64_t* ramu64; 
int8_t* ram8; 
int16_t* ram16; 
int32_t* ram32; 
int64_t* ram64; 
float* ramf; 
double* ramd; 


#include "device.c"


void allocLIVM(uint64_t size) { 
	ram = malloc(size); 
	ramu8 = (uint8_t*)ram, ramu16 = (uint16_t*)ram, 
	ramu32 = (uint32_t*)ram, ramu64 = (uint64_t*)ram; 
	ram8 = (int8_t*)ram, ram16 = (int16_t*)ram, 
	ram32 = (int32_t*)ram, ram64 = (int64_t*)ram; 
	ramf = (float*)ram, ramd = (double*)ram; 
} 

enum opcode { 
	NOP, END, // 2 
	LDA, LDB, LDC, // 3 
	ULA, ULB, ULC, // 3 
	CST, SSM, // 2 
	JMP, IVE, SLE, SIP, // 4 
	SUB, SUM, MUL, DIV, MOD, POW, // 6 
	INC, DEC, // 2 
	AND, BOR, XOR, NOT, // 4 
	EQU, LTH, GTH, // 3 
	OFR, WAI, OUT, GET, // 4 
	ALC, RLC, FRE, CPY, ADD, CAT, // 6 
	PRC // 1
	/*
		TODO: PRC
		PRC - process
		PRC 0 - create a new process with id = a
		PRC 1 - kill process with id = a
		PRC 2 - set offset = b for process with id = a
	*/
};

void print_ullram() {
	for (int i = 0; i < 100; i++) printf("%llu ", ramu64[i]);
	printf("\n");
}

void run() { 
	register uint_least64_t ip = 0; 
	register uint_least64_t a = 0, b = 0, c = 0, s = 0, op, arg; 
	register uint8_t running = 1, mode_int = 1, size_mode = 1; 
	
	while (running) { 
		switch (size_mode) { 
			case 0: 
				running = 0; 
				break; 
			case 1: 
				while (mode_int) { 
					#define xtype uint8_t 
					#define xram ramu8 
					#include "xcase.c" 
					#undef xtype 
					#undef xram 
				} 
				break; 
			case 2: 
				while (mode_int) { 
					#define xtype int8_t 
					#define xram ram8 
					#include "xcase.c" 
					#undef xtype 
					#undef xram 
				} 
				break; 
			case 3: 
				while (mode_int) { 
					#define xtype uint16_t 
					#define xram ramu16 
					#include "xcase.c" 
					#undef xtype 
					#undef xram 
				} 
				break; 
			case 4: 
				while (mode_int) { 
					#define xtype int16_t 
					#define xram ram16 
					#include "xcase.c" 
					#undef xtype 
					#undef xram 
				} 
				break; 
			case 5: 
				while (mode_int) { 
					#define xtype uint32_t 
					#define xram ramu32 
					#include "xcase.c" 
					#undef xtype 
					#undef xram 
				} 
				break; 
			case 6: 
				while (mode_int) { 
					#define xtype int32_t 
					#define xram ram32 
					#include "xcase.c" 
					#undef xtype 
					#undef xram 
				} 
				break; 
			case 7: 
				while (mode_int) { 
					#define xtype uint64_t 
					#define xram ramu64 
					#include "xcase.c" 
					#undef xtype 
					#undef xram 
				} 
				break; 
			case 8: 
				while (mode_int) { 
					#define xtype int64_t 
					#define xram ram64 
					#include "xcase.c" 
					#undef xtype 
					#undef xram 
				} 
				break; 
			case 9: 
				while (mode_int) { 
					#define xtype float 
					#define xram ramf 
					#include "xfcase.c" 
					#undef xtype 
					#undef xram 
				} 
				break; 
			case 10: 
				while (mode_int) { 
					#define xtype double 
					#define xram ramd 
					#include "xfcase.c" 
					#undef xtype 
					#undef xram 
				} 
				break; 
		} 
		mode_int = 1; 
	} 
	free(ram); 
} 

void loadBIOS(uint64_t length, uint64_t* data) { 
	for (register uint64_t i = 0; i < length; ++i) ramu64[i] = data[i]; 
} 
