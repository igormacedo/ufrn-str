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


int main() {
    int res;
    pthread_t thread1, thread2, thread3, thread4;
    void *thread_result;
    int valor1, valor2;
	
    printf("MAIN()--> Criar thread...\n");
    valor1 = 111;
    res = pthread_create(&thread1, NULL, thread_function, (void *) &valor1);
    if (res != 0) {
        perror("A Craição da Thread falhou");
        exit(EXIT_FAILURE);
    }

    valor2 = 22222;
    res = pthread_create(&thread2, NULL, thread_function, (void *) &valor2);
    if (res != 0) {
        perror("A Craição da Thread falhou");
        exit(EXIT_FAILURE);
    }

    printf("MAIN()--> Esperando pelo término da thread...\n");
    res = pthread_join(thread1, &thread_result);
    if (res != 0) {
        perror("O thread_join falhou");
        exit(EXIT_FAILURE);
    }
    printf("MAIN()--> O thread_join retornou:   %s\n", (char *)thread_result);
    //printf("MAIN()--> Message agora é: %s\n\n", message);
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
    int *i;

    i = (int *) arg;
    while (1) {
      printf("%d\n", *i);
     //printf("%d\n",(int) *arg);
    }
    //pthread_exit((void *) "Obrigado pelo seu tempo de CPU");
}
