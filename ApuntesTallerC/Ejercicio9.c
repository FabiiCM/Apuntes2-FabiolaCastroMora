#include "Ejercicio9.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid; // Identificador del proceso

    // Crear un nuevo proceso hijo
    pid = fork();

    if (pid < 0) {
        // Error en fork()
        perror("fork falló");
        return 1;
    }

    if (pid == 0) {
        // Este bloque se ejecuta en el proceso hijo
        printf("Mensaje del proceso hijo (PID: %d)\n", getpid());
        // El proceso hijo termina aquí
        return 0;
    } else {
        // Este bloque se ejecuta en el proceso padre
        printf("Mensaje del proceso padre (PID: %d)\n", getpid());
        // El proceso padre espera a que el proceso hijo termine
        wait(NULL); // NULL puede ser reemplazado por un puntero a una variable int para obtener el estado de terminación del hijo
        printf("Proceso hijo ha terminado. El proceso padre continúa.\n");
    }

    return 0;
}