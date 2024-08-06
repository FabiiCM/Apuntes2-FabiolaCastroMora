#include "Ejercicio7.h"
#include <stdio.h>
#include <stdlib.h>



int main() {
    int numero = 10;        // Definir un número entero
    int *puntero = &numero; // Definir un puntero a ese número entero

    // Imprimir el valor del número
    printf("Valor del número: %d\n", numero);

    // Imprimir la dirección de memoria a la que apunta el puntero
    printf("Dirección de memoria del número: %p\n", (void *)&numero);

    // Imprimir el valor del número a través del puntero
    printf("Valor del número a través del puntero: %d\n", *puntero);

    // Imprimir la dirección de memoria almacenada en el puntero
    printf("Dirección de memoria almacenada en el puntero: %p\n", (void *)puntero);

    return 0;
}