#include <stdio.h>
#include <pthread.h>

pthread_mutex_t buffer_empty = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t buffer_full = PTHREAD_MUTEX_INITIALIZER;

int buffer;

void *producer(void *data) {
    int i;
    for(i = 0; i < 10; ++i) {
        pthread_mutex_lock(&buffer_empty);
        printf("Producing %d\n", i);
        buffer = i;
        pthread_mutex_unlock(&buffer_full);
    }
}

void *consumer(void *data) {
    int i;
    for(i = 0; i < 10; ++i) {
        pthread_mutex_lock(&buffer_full);
        printf("\tConsuming %d\n", buffer);
        pthread_mutex_unlock(&buffer_empty);
    }
}

int main(int argc, char **argv) {
    pthread_t consumer_thread,
              producer_thread;

    pthread_mutex_lock(&buffer_full);

    pthread_create(&consumer_thread, NULL, consumer, NULL);
    pthread_create(&producer_thread, NULL, producer, NULL);

    pthread_join(consumer_thread, NULL);
    pthread_join(producer_thread, NULL);

    return 0;
}
