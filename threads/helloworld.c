#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUMTHREADS 10000
int total;
pthread_mutex_t lock;

void * printHelloWorld(void *datos){
    printf("Hello World desde un hilo %d \n", * (int *) datos);
    pthread_mutex_lock(&lock);
    total += 100;
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}


int main(){
    pthread_t myThread[NUMTHREADS];
    int tIds[NUMTHREADS];
    pthread_mutex_init(&lock, NULL);
    pthread_mutex_unlock(&lock); //Abir por si acaso
    for(int i = 0; i < NUMTHREADS; i++){
        tIds[i] = i;
        pthread_create(&myThread[i],NULL,printHelloWorld, &tIds[i]);
    }
    
    for(int i = 0; i < NUMTHREADS; i++){
        pthread_join(myThread[i],NULL);
    }

    printf("Total: %d\n",total);
    pthread_exit(NULL);
}