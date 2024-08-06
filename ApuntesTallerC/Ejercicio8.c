#include "Ejercicio8.h"
#include <stdio.h>
#include <stdlib.h>


int main() {
    // Definir y inicializar un arreglo de enteros
    int lista[] = {10, 20, 30, 40, 50};
    int tamaño = sizeof(lista) / sizeof(lista[0]); // Calcular el tamaño del arreglo
    
    // Declarar un puntero al primer elemento del arreglo
    int *puntero = lista;

    // Recorrer el arreglo usando aritmética de punteros
    for (int i = 0; i < tamaño; i++) {
        // Imprimir el valor del elemento actual
        printf("Elemento %d: %d\n", i, *(puntero + i));
    }

    return 0;
}