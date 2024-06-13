/*FILAVACIA :  FILA
ESFILAVACIA : FILA  BOOL
FRENTE : FILA  ITEM U {indefinido}
ENFILA : FILA X ITEM  FILA
DEFILA : FILA  FILA */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
const item indefinido=-9999;

typedef struct Nodo {
    item dato;
    struct Nodo* siguiente;
} Nodo;

// Definición de la Fila
typedef struct {
    Nodo* frente;
    Nodo* ultimo;
} Fila;


// Definicion para contructora primitiva
void filaVacia (Fila* fila){
    fila->frente=NULL;
    fila->ultimo=NULL;
}

// Funcion tipo Test
bool esFilaVacia (Fila* fila){
    if(fila->frente==NULL){
        return true;
    }
    return false;
}

// Funcion tipo Selectora
item frente (Fila* fila){
    if(fila->frente!=NULL){
        return fila->frente->dato;
    }
    return indefinido;
}

void enfila (Fila* fila, item x){
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = x;
    aux->siguiente = NULL;
    if(fila->frente==NULL){
        fila->frente=aux;
        fila->ultimo=aux;
    }else{
        fila->ultimo->siguiente = aux;
        fila->ultimo = aux;
    }
}

void defila(Fila* fila){
    if(!esFilaVacia(fila)){
        Nodo* aux = fila->frente;
        fila->frente=aux->siguiente;
        free(aux);
    }
}