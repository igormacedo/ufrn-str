// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: fork1

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEEP_TIME 10

int main (int argc, char **argv)
{
	pid_t pid1, pid2, pid3, pid4, pid5, pid6;
	int argv0size = strlen(argv[0]);
	
	printf("PROG1\n"); strncpy(argv[0], "PROG1.0.0", argv0size);
	sleep(SLEEP_TIME);
	pid1 = fork();
	switch(pid1) {
		case -1:       // erro na abertura do processo filho
      		exit(1);
		case 0: // se for o filho
			printf("PROG1.1\n"); strncpy(argv[0], "PROG1.1.0", argv0size);
			sleep(SLEEP_TIME);
			pid2 = fork();
			switch(pid2) {
				case -1:
					exit(1);
				case 0:
					printf("PROG1.1.1\n"); strncpy(argv[0], "PROG1.1.1", argv0size);
					sleep(3*SLEEP_TIME);
					break;
				default:
					sleep(SLEEP_TIME);
					pid5 = fork();
					switch(pid5) {
						case -1:
							exit(1);
						case 0:
							printf("PROG1.1.2\n"); strncpy(argv[0], "PROG1.1.2", argv0size);
							sleep(3*SLEEP_TIME);
							break;
						default:
							sleep(SLEEP_TIME);
							break;
					}
					break;
			}
			break;
		default:
			sleep(SLEEP_TIME);
			pid3 = fork();
			switch(pid3) {
				case -1:
					exit(1);
				case 0:				
					printf("PROG1.2\n"); strncpy(argv[0], "PROG1.2.0", argv0size);
					sleep(SLEEP_TIME);
					pid2 = fork();
					switch(pid2) {
						case -1:
							exit(1);
						case 0:
							printf("PROG1.2.1\n"); strncpy(argv[0], "PROG1.2.1", argv0size);
							sleep(3*SLEEP_TIME);
							break;
						default:
							sleep(SLEEP_TIME);
							pid6 = fork();
							switch(pid6) {
								case -1:
									exit(1);
								case 0:
									printf("PROG1.2.2\n"); strncpy(argv[0], "PROG1.2.2", argv0size);
									sleep(3*SLEEP_TIME);
									break;
								default:
									sleep(SLEEP_TIME);					
									break;
							}
					}
					break;
				default:
					sleep(SLEEP_TIME);					
					break;
			}
	}

	exit(0);

}
