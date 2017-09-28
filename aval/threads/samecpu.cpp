/* 
 Descrição:
 - Programa que cria 3 threads.
 Compilar: g++ -pthread -o nomeExecutavel nomeDesseArquivo
*/


#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#define NUM_THREADS 3

// Função auxiliar da thread
void* funcaoHelper(void* idThread) {
	while(1) {
		printf("%d",(int)idThread + 1);
		//usleep(1000);
	}
  /*sleep((int)idThread + 1);
  printf("Finalizar a thread: %d\n", (int)idThread);
  //Finalizar com o código de retorno igual ao idThread
  pthread_exit((void *) idThread);*/
}  

int main(int argc, char *argv[]){

	cpu_set_t cpuset;


  //Vetor de threads
  pthread_t vetorThreads[NUM_THREADS];

  //Status de criação
  int statusRetorno;

  //Status de finalização da thread
  void * statusFinalizacao;

  //Loop para criar as threads
  for(int i=0; i < NUM_THREADS; i++){
      printf("Main - criando a thread: %d\n", i);
      //Criar a thread i
      statusRetorno = pthread_create(&vetorThreads[i], NULL, funcaoHelper, (void *)i);
      //Verificando a existência de erros na criação
      if (statusRetorno){
         printf("Erro ao criar a thread: %d\n", statusRetorno);
         exit(-1);
      }
   }
  for (int i=0; i < NUM_THREADS; i++){
   CPU_ZERO(&cpuset);
   CPU_SET(0, &cpuset);
	pthread_setaffinity_np(vetorThreads[i], sizeof(cpu_set_t), &cpuset);
   }
  //Realizando um join com todas as threads
  for (int i=0; i < NUM_THREADS; i++){
      //Main fica bloqueado até vetorThreads[i] finalizar
      statusRetorno = pthread_join(vetorThreads[i], &statusFinalizacao);
       if (statusRetorno){
         printf("Erro ao executar thread_join: %d\n", statusRetorno);
         exit(-1);
      }
      printf("Join finalizado para a thread: %d com o codigo: %d\n", i, (int)statusFinalizacao);
   }
   printf("Finalizando o metodo main\n");
   pthread_exit(NULL);
}
