#define opargs uint64_t a, uint64_t b, uint64_t c
	typedef void opfunc(opargs);
	typedef uint64_t rdfunc(opargs);

	struct Device {
		uint64_t* buffer;
		uint64_t* data;
		uint64_t* rdata;
		opfunc* offer;
		opfunc* wait;
		opfunc* out;
		rdfunc* read;
	};

	void d_null_writef(opargs) {}
	uint64_t d_null_readf(opargs) {}

	struct Device d_null = {
		.buffer = NULL,
		.data = NULL,
		.rdata = NULL,
		.offer = d_null_writef,
		.wait = d_null_writef,
		.out = d_null_writef,
		.read = d_null_readf
	};

	void d_clock_offer(opargs) {}
	void d_clock_out(opargs) {}
	void d_clock_wait(opargs) {
		usleep(a * 1000);
	}
	uint64_t d_clock_read(opargs) {
		return (uint64_t)clock();
	}

	struct Device d_clock = {
		.buffer = NULL,
		.data = NULL,
		.rdata = NULL,
		.offer = d_clock_offer,
		.wait = d_clock_wait,
		.out = d_clock_out,
		.read = d_clock_read
	};

	# ifdef CONSOLE_D
		void d_console_offer(opargs);
		void d_console_out(opargs);
		void d_console_wait(opargs);
		uint64_t d_console_read(opargs);

		struct Device d_console = {
			.buffer = (uint64_t[1024]){ [0 ... 1023] = 0 },
			.data = (uint64_t[800]){ [0 ... 799] = 0 },
			.rdata = (uint64_t[1]){ 0 },
			.offer = d_console_offer,
			.wait = d_console_wait,
			.out = d_console_out,
			.read = d_console_read
		};

		void d_console_offer(opargs) {
			if (a == 0) return;
			uint64_t* cursor = d_console.buffer;
			uint8_t* data = (uint8_t*)(d_console.buffer + 1);
			if (c == 1) {
				(*cursor) = a;
				return;
			}
			if (*cursor >= 3200) return;
			if (a == 1)
				data[*cursor++] = b;
			else {
				if ((*cursor + a) >= 3200) return;
				for (uint64_t i = 0; i < a; i++)
					data[(*cursor)++] = ramu8[b + i];
			}
		}
		void d_console_out(opargs) {
			uint8_t* _data = (uint8_t*)(d_console.buffer + 1);
			uint64_t* _data64 = (uint64_t*)_data;
			for (uint64_t i = 0; i < 400; i++) 
				d_console.data[i] = _data64[i];
			d_console.buffer[0] = 0;
			printf("\e[H");
			for (uint64_t i = 0; i < 40; i++) {
				for (uint64_t j = 0; j < 80; j++) {
					if (((uint8_t*)d_console.data)[j + i * 80])
						putchar(((uint8_t*)d_console.data)[j + i * 80]);
					else putchar(' ');
				}
				putchar('\n');
			}
		}
		void d_console_wait(opargs) {
			d_console.rdata[0] = getchar();
		}
		uint64_t d_console_read(opargs) {
			return d_console.rdata[0];
		}
	# else
		#  define d_console d_null
	# endif

	struct Device* vm_dev[2] = { &d_clock, &d_console };

	# ifdef d_console
		#  undef d_console
	# endif
#undef opargs
