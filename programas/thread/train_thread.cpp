#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t trilho3_mutex = PTHREAD_MUTEX_INITIALIZER;

void L(int num_thread, int l, int lenteza)
{
    if (l == 3) {
        printf("\033[0;31m%sThread %d entrando trilho %d\033[0m\n", 
               num_thread==1?" ":"\t\t\t\t", num_thread, l);
    } else {
        printf("\033[0;34m%sThread %d entrando trilho %d\033[0m\n", 
               num_thread==1?" ":"\t\t\t\t", num_thread, l);		
    }	
    fflush(stdout);
    sleep(lenteza);
    //printf("%sThread %d saindo trilho %d\n", 
    //	   num_thread==1?" ":"\t\t\t\t", num_thread, l);
    //fflush(stdout);
}

void* thread_function1(void* data)
{
    int num = (int) data;
    while(1)
    {
        L(1,2,1);
        pthread_mutex_lock(&trilho3_mutex);
        L(1,3,1);
        pthread_mutex_unlock(&trilho3_mutex);
        L(1,1,1);
    }
}

void* thread_function2(void* data)
{
    int num = (int) data;
    while(1)
    {
        L(2,5,5);
        pthread_mutex_lock(&trilho3_mutex);
        L(2,3,5);
        pthread_mutex_unlock(&trilho3_mutex);
        L(2,4,5);
    }
}

int main()
{
    srand(time(NULL));
    pthread_t thread1, thread2;
    pthread_mutex_init(&trilho3_mutex, NULL);

    pthread_create(&thread1, NULL, thread_function1, NULL); 
    pthread_create(&thread2, NULL, thread_function2, NULL); 

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
