#include <Ejercicio3.h>
#include <stdio.h>
#include <stdlib.h>

int ejercicio3() {
    int numero;

    // Solicitar al usuario que ingrese un número entero
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);

    // Determinar si el número es positivo, negativo o cero
    if (numero > 0) {
        printf("El numero %d es positivo.\n", numero);
    } else if (numero < 0) {
        printf("El numero %d es negativo.\n", numero);
    } else {
        printf("El numero es cero.\n");
    }

    return 0;
}