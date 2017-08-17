// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: fork1

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define SLEEP_INTERVAL 1


void processTree(int depth) {
	pid_t pid;

	if(depth == 0) return;

	for(int i = 1; i <= SLEEP_INTERVAL; ++i) {
		sleep(1);
		//printf
	}
	

	pid = fork();
	switch(pid) {
		case -1:       // erro na abertura do processo filho
      		exit(1);
		case 0: // se for o filho
			printf("processo filho\n");
			processTree(depth-1);
			break;
		default:
			printf("processo pai\n");
			processTree(depth-1);
	}
}

int main ()
{

	processTree(2);

	exit(0);

}
