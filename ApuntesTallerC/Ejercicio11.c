#include "Ejercicio11.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Definir una variable global compartida
int variable_global = 0;

// Definir un mutex
pthread_mutex_t mutex;

void *incrementar(void *arg) {
    for (int i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutex); // Adquirir el mutex
        variable_global++;          // Acceder y modificar la variable global
        printf("Hilo %ld incrementó la variable_global a %d\n", (long)arg, variable_global);
        pthread_mutex_unlock(&mutex); // Liberar el mutex
        sleep(1); // Simular trabajo
    }
    return NULL;
}

int main() {
    pthread_t hilo1, hilo2;

    // Inicializar el mutex
    if (pthread_mutex_init(&mutex, NULL) != 0) {
        perror("mutex_init falló");
        return 1;
    }

    // Crear los hilos
    if (pthread_create(&hilo1, NULL, incrementar, (void *)1) != 0) {
        perror("pthread_create falló para hilo1");
        return 1;
    }

    if (pthread_create(&hilo2, NULL, incrementar, (void *)2) != 0) {
        perror("pthread_create falló para hilo2");
        return 1;
    }

    // Esperar a que ambos hilos terminen
    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    // Destruir el mutex
    pthread_mutex_destroy(&mutex);

    printf("Valor final de variable_global: %d\n", variable_global);

    return 0;
}