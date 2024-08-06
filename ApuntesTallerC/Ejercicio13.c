#include "Ejercicio13.h"
#include <stdio.h>
#include <stdlib.h> // Para malloc() y free()

int main() {
    int *arreglo;      // Puntero para el arreglo de enteros
    int tamaño;        // Tamaño del arreglo
    int i;             // Variable de iteración

    // Solicitar el tamaño del arreglo al usuario
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &tamaño);

    // Asignar memoria dinámicamente para el arreglo
    arreglo = (int *)malloc(tamaño * sizeof(int));
    if (arreglo == NULL) {
        // Verificar si la asignación de memoria fue exitosa
        perror("Error al asignar memoria");
        return 1;
    }

    // Llenar el arreglo con valores
    for (i = 0; i < tamaño; i++) {
        arreglo[i] = i + 1; // Asignar valores del 1 al tamaño
    }

    // Imprimir los valores del arreglo
    printf("Valores del arreglo:\n");
    for (i = 0; i < tamaño; i++) {
        printf("%d ", arreglo[i]);
    }
    printf("\n");

    // Liberar la memoria asignada
    free(arreglo);

    return 0;
}