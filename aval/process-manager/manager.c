// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa matatdor.cpp
// Sinais sã eventos gerados pelo Unix em resposta a algumas condições, como:
//  erros, violação de memória, instrução ilegal, ...

#define _GNU_SOURCE
#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system()
#include <sched.h>

int  main(int argc, char **argv)
{
	int pid_target;
	int option;
	int cpu;
	cpu_set_t mask;
     
  	printf("Eu sou um programa gerenciador de programas.\n\n" );
	while(1) {
		printf("Digite o PID do processo que deve gerenciar: ");
		scanf("%d", &pid_target);
	
		printf("Selecione uma opção:\n");
		printf("1 - Matar o processo\n");
		printf("2 - Parar o processo\n");
		printf("3 - Continuar o processo\n");
		printf("4 - Selecionar CPU para o processo rodar\n");
		scanf("%d", &option);

		switch(option) {
			case 1:
				kill(pid_target, SIGKILL);
				break;
			case 2:
				kill(pid_target, SIGSTOP);
				break;
			case 3:
				kill(pid_target, SIGCONT);
				break;
			case 4:
				printf("Selecione a CPU [1 ou 2]: ");
				scanf("%d", &cpu);
				CPU_ZERO(&mask);
				CPU_SET(cpu-1, &mask);
				if(sched_setaffinity(pid_target, sizeof(cpu_set_t), &mask) < 0) {
					fprintf(stderr, "Erro setando CPU\n");
				}
				break;
		}
		system("clear");
	}
	exit(0);
}






