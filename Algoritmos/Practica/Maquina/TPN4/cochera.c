#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

typedef struct Cochera {
    Nodo* cabeza;
    int capacidad;
    int libre;
} Cochera;

Cochera* cocheraVacia(int x) {
    Cochera* lista = (Cochera*)malloc(sizeof(Cochera));
    lista->cabeza = NULL;
    lista->capacidad = x;
    lista->libre=x;
    return lista;
}

Cochera* estacionar(Cochera* l1, int x){
    if(l1->libre>0){
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->valor = x;
    nuevoNodo->siguiente = l1->cabeza;
    l1->cabeza = nuevoNodo;
    l1->libre--;
    }else {
        printf("No se pudo agregar correctamente. Falta de capacidad.");
    }
}

bool estaVacia(Cochera* l1){
    if(l1->cabeza==NULL){
        return true;
    } else{
        return false;
    }
}

Cochera* quitarUltimo (Cochera* l1){
    if (estaVacia(l1)) {
        fprintf(stderr, "La lista está vacía\n");
        exit(EXIT_FAILURE);
    }
    Nodo* nodoAEliminar = l1->cabeza;
    l1->cabeza = l1->cabeza->siguiente;
    free(nodoAEliminar);
    l1->libre++;
}

Nodo* salirRecursiva (Nodo* l1, int x){
    if (l1==NULL) {
        return l1;
    }
    if (l1->valor==x)
    {
        return l1=l1->siguiente;
    } else {
        return salirRecursiva(l1->siguiente,x);
    }
}


Cochera* salir (Cochera* l1, int x){
    if (estaVacia(l1)) {
        fprintf(stderr, "La lista está vacía\n");
        exit(EXIT_FAILURE);
    }
    Nodo* nodoAEliminar = l1->cabeza;
    l1->cabeza = salirRecursiva(nodoAEliminar,x);
    return l1;
}

int ultimo (Cochera* l1){
    if (estaVacia(l1)) {
        return -9999;
    }else {
       return l1->cabeza->valor;
    }
}

bool estacionadoRecusiva (Nodo* l1,int x){
    if (l1==NULL) {
        return false;
    }
    if(l1->valor==x){
        return true;
    } else {
        return estacionadoRecusiva(l1->siguiente,x);
    }
}

bool estacionado (Cochera* l1,int x){
    if (estaVacia(l1)) {
        return false;
    }
    Nodo* nodoAEliminar = l1->cabeza;
    return estacionadoRecusiva(nodoAEliminar,x);
}


int capacidad (Cochera* l1){
    return l1->capacidad;
}

int libre (Cochera* l1){
    return l1->libre;
}

int main() {
    // Crear un estacionamiento con una capacidad de 5 lugares
    Cochera* estacionamiento = cocheraVacia(5);

    // Probar si el estacionamiento está vacío
    printf("El estacionamiento esta vacio? %s\n", estaVacia(estacionamiento) ? "Sí" : "No");

    // Estacionar algunos autos
    estacionar(estacionamiento, 101);
    estacionar(estacionamiento, 102);
    estacionar(estacionamiento, 103);

    // Verificar si autos específicos están estacionados
    printf("El auto 101 esta estacionado? %s\n", estacionado(estacionamiento, 101) ? "Sí" : "No");
    printf("El auto 104 esta estacionado? %s\n", estacionado(estacionamiento, 104) ? "Sí" : "No");

    // Probar la capacidad y lugares disponibles
    printf("Capacidad total del estacionamiento: %d\n", capacidad(estacionamiento));
    printf("Lugares disponibles en el estacionamiento: %d\n", libre(estacionamiento));

    // Quitar un auto
    estacionamiento = salir(estacionamiento, 101);

    // Probar si el auto ha sido quitado
    printf("El auto 101 está estacionado? %s\n", estacionado(estacionamiento, 101) ? "Sí" : "No");

    // Probar si el estacionamiento está vacío después de quitar un auto
    printf("El estacionamiento está vacío? %s\n", estaVacia(estacionamiento) ? "Sí" : "No");

    // Liberar la memoria asignada
    free(estacionamiento);

    return 0;
}