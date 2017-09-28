
/*
 *  thread2.cpp
 *  teste
 *
 *  Created by Luiz Affonso on 04/09/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// programa thread2.cpp
// Programa que cria uma thread e espera seu término para também poder terminar 
// Para compilá-lo utilise: g++ -o thread2 thread2.cpp -lpthread



//#include "thread2.h"


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>   // biblioteca pthread


void *thread_function(void *arg);

//char message[] = "Alô, Mundo cruel!";

int main() {
    int res;
    
	pthread_t a_thread;
	pthread_t b_thread;

    void *thread_result;
    // criação de thread: (endereco_da_thread, atributos_da_thread, endereco_da_função, argumentos_da_função)
	int number;
	number = 1;
    res = pthread_create(&a_thread, NULL, thread_function, (void *)number);
    if (res != 0) {
        perror("A Craição da Thread falhou");
        exit(EXIT_FAILURE);
    }
    
	number = 2;
	res = pthread_create(&b_thread, NULL, thread_function, (void *)number);
    if (res != 0) {
        perror("A Craição da Thread falhou");
        exit(EXIT_FAILURE);
    }


    printf("MAIN()--> Esperando pelo término da thread...\n");
  
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("O thread_join a falhou");
        exit(EXIT_FAILURE);
    }
    
	res = pthread_join(b_thread, &thread_result);
    if (res != 0) {
        perror("O thread_join b falhou");
        exit(EXIT_FAILURE);
    }
  
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
	int number = (int) arg;
	int sleeptime = (number == 1 ? 3 : 5);
    printf("THREAD--> thread_function está rodando. O argumento foi %d\n", number);
    printf("THREAD--> Agora vou dormir por %d segundos\n", sleeptime);
    sleep(sleeptime);
	printf("THREAD--> Acordei e agora vou terminar\n");
    pthread_exit((void *) "Obrigado pelo seu tempo de CPU");
}
