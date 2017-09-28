#include <stdio.h>
#include <sched.h>
#include <unistd.h>

int main() {
	int cpu = 0;
	cpu_set_t mask;

	
	while(1) {
		printf("cpu = %d\n", cpu);
		CPU_ZERO(&mask);
		CPU_SET(cpu, &mask);
		cpu = (cpu ? 0 : 1);

		if(sched_setaffinity(0, sizeof(cpu_set_t), &mask) < 0) {
			fprintf(stderr, "Error setting CPU\n");
		}
		
		sleep(2);
	}
	return 0;
}
