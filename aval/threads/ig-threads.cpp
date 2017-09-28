/* 
 Descrição:
 - Programa que cria 3 threads.
 Compilar: g++ -pthread -o nomeExecutavel nomeDesseArquivo
*/


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_THREADS 4

// Função auxiliar da thread
void* funcaoCarga(void* idThread){
	for(;;){
		printf("%d",(int)idThread);
	}
	pthread_exit((void *) idThread);
}
void* funcaoHelper(void* idThread) {
  printf("Finalizar a thread: %d\n", (int)idThread);
  //Finalizar com o código de retorno igual ao idThread
  pthread_exit((void *) idThread);
}  

int main(int argc, char *argv[]){
	int numberOfProcessors = sysconf(_SC_NPROCESSORS_ONLN);
   printf("Number of processors: %d\n", numberOfProcessors);
   
  cpu_set_t cpus;
  CPU_ZERO(&cpus);
  CPU_SET(0, &cpus);

  //Vetor de threads
  pthread_t vetorThreads[NUM_THREADS];
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setaffinity_np(&attr, sizeof(cpu_set_t), &cpus);

  //Status de criação
  int statusRetorno;

  //Status de finalização da thread
  void * statusFinalizacao;

  //Loop para criar as threads
  for(int i=0; i < NUM_THREADS; i++){
      printf("Main - criando a thread: %d\n", i);
      //Criar a thread i
   
      //pthread_create(&threads[i], &attr, funcaoCarga, NULL);
      statusRetorno = pthread_create(&vetorThreads[i], &attr, funcaoCarga, (void *)i);
      //Verificando a existência de erros na criação
      if (statusRetorno){
         printf("Erro ao criar a thread: %d\n", statusRetorno);
         exit(-1);
      }
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
