#include "Ejercicio13.h"
#include <stdio.h>
#include <stdlib.h>

// Definir la estructura del nodo de la lista enlazada
struct Nodo {
    int dato;
    struct Nodo *siguiente;
};

// Función para crear un nuevo nodo
struct Nodo* crearNodo(int dato) {
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL) {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para insertar un nodo al final de la lista
void insertarFinal(struct Nodo **cabeza, int dato) {
    struct Nodo *nuevoNodo = crearNodo(dato);
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        struct Nodo *temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}

// Función para obtener el tamaño de la lista
int obtenerTamano(struct Nodo *cabeza) {
    int tamano = 0;
    struct Nodo *temp = cabeza;
    while (temp != NULL) {
        tamano++;
        temp = temp->siguiente;
    }
    return tamano;
}

// Función para imprimir los elementos de la lista
void imprimirLista(struct Nodo *cabeza) {
    struct Nodo *temp = cabeza;
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}

// Función para liberar la memoria de la lista
void liberarLista(struct Nodo *cabeza) {
    struct Nodo *temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

int main() {
    struct Nodo *cabeza = NULL;
    int opcion, valor;

    while (1) {
        printf("\nMenú:\n");
        printf("1. Insertar al final\n");
        printf("2. Obtener tamaño\n");
        printf("3. Imprimir lista\n");
        printf("4. Salir\n");
        printf("Ingrese su opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &valor);
                insertarFinal(&cabeza, valor);
                break;
            case 2:
                printf("Tamaño de la lista: %d\n", obtenerTamano(cabeza));
                break;
            case 3:
                imprimirLista(cabeza);
                break;
            case 4:
                liberarLista(cabeza);
                printf("Saliendo...\n");
                exit(EXIT_SUCCESS);
            default:
                printf("Opción inválida. Intente de nuevo.\n");
        }
    }

    return 0;
}