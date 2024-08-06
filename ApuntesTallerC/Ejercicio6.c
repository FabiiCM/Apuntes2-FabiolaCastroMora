#include "Ejercicio6.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero;
    unsigned long long factorial = 1; // Usamos unsigned long long para manejar números grandes

    // Solicitar al usuario que ingrese un número
    printf("Ingrese un número entero no negativo: ");
    scanf("%d", &numero);

    // Verificar que el número sea no negativo
    if (numero < 0) {
        printf("Error: El número debe ser no negativo.\n");
        return 1;
    }

    // Calcular el factorial utilizando un bucle while
    int i = 1;
    while (i <= numero) {
        factorial *= i;
        i++;
    }

    // Mostrar el resultado
    printf("El factorial de %d es %llu\n", numero, factorial);

    return 0;
}