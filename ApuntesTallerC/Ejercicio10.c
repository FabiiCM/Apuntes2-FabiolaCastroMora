#include "Ejercicio9.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pipefd[2]; // Descriptores de archivo para el pipe (pipefd[0] para leer, pipefd[1] para escribir)
    pid_t pid1, pid2;
    pid_t padre_pid = getpid(); // PID del proceso padre

    // Crear el pipe
    if (pipe(pipefd) == -1) {
        perror("pipe falló");
        exit(EXIT_FAILURE);
    }

    // Crear el primer proceso hijo
    pid1 = fork();
    if (pid1 < 0) {
        perror("fork falló");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0) {
        // Este bloque se ejecuta en el primer proceso hijo
        close(pipefd[1]); // Cerrar el extremo de escritura del pipe
        pid_t recibido;
        read(pipefd[0], &recibido, sizeof(recibido)); // Leer el PID del padre
        close(pipefd[0]); // Cerrar el extremo de lectura del pipe
        printf("Proceso hijo 1 (PID: %d) recibió PID del padre: %d\n", getpid(), recibido);
        exit(EXIT_SUCCESS);
    }

    // Crear el segundo proceso hijo
    pid2 = fork();
    if (pid2 < 0) {
        perror("fork falló");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0) {
        // Este bloque se ejecuta en el segundo proceso hijo
        close(pipefd[1]); // Cerrar el extremo de escritura del pipe
        pid_t recibido;
        read(pipefd[0], &recibido, sizeof(recibido)); // Leer el PID del padre
        close(pipefd[0]); // Cerrar el extremo de lectura del pipe
        printf("Proceso hijo 2 (PID: %d) recibió PID del padre: %d\n", getpid(), recibido);
        exit(EXIT_SUCCESS);
    }

    // Este bloque se ejecuta en el proceso padre
    close(pipefd[0]); // Cerrar el extremo de lectura del pipe
    write(pipefd[1], &padre_pid, sizeof(padre_pid)); // Enviar el PID del padre a través del pipe
    close(pipefd[1]); // Cerrar el extremo de escritura del pipe

    // Esperar a que ambos hijos terminen
    wait(NULL);
    wait(NULL);

    printf("Proceso padre (PID: %d) terminó.\n", getpid());

    return 0;
}