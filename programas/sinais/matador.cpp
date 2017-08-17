// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa matatdor.cpp
// Sinais sã eventos gerados pelo Unix em resposta a algumas condições, como:
//  erros, violação de memória, instrução ilegal, ...

#include <signal.h> // definição dos sinais de interrupções
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> // system()



int  main()
{
  // o processo que vai matar

	int meu_pid;
	int pid_vitima;

	meu_pid = getpid();
	int action;
  
	printf( "O que fazer da vida? ");
	scanf( "%d", &action);

	switch(action)
	{
		case 1:	
		{
			printf( "Eu vou matar um processo! %d\n", meu_pid );
			printf( "Digite o PID do processo que devo atuar: ");
			scanf( "%d", &pid_vitima);
			kill(pid_vitima, SIGKILL);
			break;
		}
		case 2:
		{
			printf( "Eu vou pausar um processo! %d\n", meu_pid );
			printf( "Digite o PID do processo que devo atuar: ");
			scanf( "%d", &pid_vitima);
			kill(pid_vitima, SIGTSTP);
			break;
		}
		case 3:
		{
			printf( "Eu vou continuar um processo! %d\n", meu_pid );
			printf( "Digite o PID do processo que devo atuar: ");
			scanf( "%d", &pid_vitima);
			kill(pid_vitima, SIGCONT);
			break;
		}
		default:
			break;
			
	}

	printf( "\nAgora posso morrer tranquilo.\n");
	exit(0);
}






