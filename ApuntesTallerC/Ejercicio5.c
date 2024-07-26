#include <Ejercicio5.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero;
    // Definir los tres números (bueno, malo, feo)
    const int BUENO = 1;
    const int MALO = 2;
    const int FEOSO = 3;

    // Solicitar al usuario que ingrese un número
    printf("Ingrese un número: ");
    scanf("%d", &numero);

    // Usar el switch para determinar el mensaje a imprimir
    switch (numero) {
        case BUENO:
            printf("El bueno\n");
            break;
        case MALO:
            printf("El malo\n");
            break;
        case FEOSO:
            printf("El feo\n");
            break;
        default:
            printf("No sé\n");
            break;
    }

    return 0;
}