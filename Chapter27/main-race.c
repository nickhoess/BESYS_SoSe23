#include <stdio.h>

#include "common_threads.h"

pthread_mutex_t l1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t l2 = PTHREAD_MUTEX_INITIALIZER;

int balance = 0;

void* worker(void* arg) {
    /*Pthread_mutex_lock(&l1);
    balance++; // unprotected access
    Pthread_mutex_unlock(&l1)*/
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t p;
    Pthread_create(&p, NULL, worker, NULL);
    Pthread_mutex_lock(&l2);
    balance++; // unprotected access
    Pthread_mutex_lock(&l2);
    Pthread_join(p, NULL);
    return 0;
    return 0;
}
