#include "Ejercicio12.h"
#include <stdio.h>
#include <string.h> // Para usar strcpy

// Definición de la estructura Estudiante
struct Estudiante {
    char nombre[50];
    int edad;
    float nota;
};

int main() {
    // Crear una instancia de la estructura Estudiante
    struct Estudiante estudiante;

    // Asignar valores a los campos de la estructura
    strcpy(estudiante.nombre, "Juan Pérez"); // Usar strcpy para copiar la cadena
    estudiante.edad = 20;
    estudiante.nota = 8.5;

    // Imprimir los valores de la estructura
    printf("Nombre del estudiante: %s\n", estudiante.nombre);
    printf("Edad del estudiante: %d\n", estudiante.edad);
    printf("Nota del estudiante: %.2f\n", estudiante.nota);

    return 0;
}