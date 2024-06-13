/*Codifique en un archivo de nombre Pila.h una implementación en lenguaje C del ADT
PILA de enteros con lista enlazada utilizando la tipificación vista en la clase práctica.
Escriba un programa para probar todas las operaciones del ADT Pila y la operación del
apartado b). Calcule la complejidad de las operaciones en notación O Grande*/
#include <stdio.h>
#include <stdlib.h>

typedef int item;
const item indefinido=-9999;

typedef struct Nodo {
    item dato;
    struct Nodo* siguiente;
} Nodo;

// Definición de la pila
typedef struct {
    Nodo* cima;
} Pila;

// Función para inicializar la pila
void pilaVacia(Pila* pila) {
    pila->cima = NULL;
}

// Función para verificar si la pila está vacía
int esPilaVacia(Pila* pila) {
    return pila->cima == NULL;
}

// Función para empujar un elemento en la pila
void push(Pila* pila, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = pila->cima;
    pila->cima = nuevoNodo;
}

// Función para pop un elemento de la pila
void pop(Pila* pila) {
    if (!esPilaVacia(pila)) {
    Nodo* nodoAEliminar = pila->cima;
    pila->cima = nodoAEliminar->siguiente;
    free(nodoAEliminar);
    }
}

// Función para ver el elemento en la cima de la pila sin poplo
int top(Pila* pila) {
    if (esPilaVacia(pila)) {
        return -9999;
    }
    return pila->cima->dato;
}

// Función para destruir la pila y liberar la memoria
void liberarPila(Pila* pila) {
    while (!esPilaVacia(pila)) {
        pop(pila);
    }
}

// Función para obtener el fondo de la fila
int fondo (Pila* pila){
    if(!esPilaVacia(pila)){
        Nodo* aux = pila->cima;
        while(aux->siguiente!=NULL){
            aux = aux->siguiente;
        }
        return aux->dato;
    }
    return -9999;
    
}

// Función para eliminar el fondo de la pila
void popf (Pila* pila){
    if (!esPilaVacia(pila)) {
        Nodo* aux = pila->cima;
        if(aux->siguiente==NULL){
            pop(pila);
            return;
        }
        Nodo* anterior = aux->siguiente;
        while(anterior->siguiente!=NULL){
            aux = aux->siguiente;
            anterior = anterior->siguiente;
        }
        Nodo* nodoAEliminar = aux->siguiente;
        aux->siguiente=anterior->siguiente;
        free(nodoAEliminar);
    }
}
// Función para remplazar los x por el valor y
void reemplazar (Pila* pila,int x,int y){
    if (!esPilaVacia(pila)){
        Nodo* aux = pila->cima;
        while(aux->siguiente!=NULL){
            if(aux->dato==x){
                aux->dato=y;
            }
            aux=aux->siguiente;
        }
    }
}