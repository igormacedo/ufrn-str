//
//  thread8.cpp
//  
//
//  Created by Affonso on 25/10/16.
//
//

// #include "thread8.hpp"

// Programa que sincroniza threads utilizando-se mutexes
// Para compilá-lo utilise: g++ -o thread8 thread8.cpp -lpthread


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>

void *thread_function(void *arg); // declaração da função a ser executada na thread

pthread_mutex_t work_mutex; /* proteção para: work_area e time_to_exit */

//#define WORK_SIZE 1024
//char work_area[WORK_SIZE];
//int time_to_exit = 0;

int main() {
    int res;
    pthread_t a_thread;
    void *thread_result;
    
    // Iniciar Multex
    res = pthread_mutex_init(&work_mutex, NULL);
    if (res != 0) {
        perror("Iniciação do Mutex falhou");
        exit(EXIT_FAILURE);
    }
    
    // Criar thread
    res = pthread_create(&a_thread, NULL, thread_function, NULL);
    if (res != 0) {
        perror("Criação da Thread falhou");
        exit(EXIT_FAILURE);
    }
    
    for(int i=0; i< 3; i++) {
        pthread_mutex_lock(&work_mutex); // Entrando na região crítica
        printf("MAIN() --> Thread main() vai dormir por 3 segundos\n");
        //sleep(5);
        getchar();
        pthread_mutex_unlock(&work_mutex); // saindo de região critica
        sleep(1);
    }
    
   
    
    // Juntando thread mai() com a_thread
    
    printf("\nMAIN() --> Esperando a thread terminar...\n");
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("Junção da Thread falhou");
        exit(EXIT_FAILURE);
    }
    printf("MAIN() --> Thread foi juntada com sucesso\n");
    pthread_mutex_destroy(&work_mutex);  // destruição do multex
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
    sleep(1);
    for(int i=0; i< 10; i++) {
        pthread_mutex_lock(&work_mutex);
        printf("THREAD() --> a_thread vai dormir por 1 segundo\n");
        sleep(1);
        pthread_mutex_unlock(&work_mutex);
        sleep(1);
    }
    pthread_exit(0);
}