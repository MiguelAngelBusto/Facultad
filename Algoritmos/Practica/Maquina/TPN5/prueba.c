#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Pila pila;
    pilaVacia(&pila);

    // Prueba de push
    push(&pila, 10);
    push(&pila, 20);
    push(&pila, 30);

    // Prueba de ver la cima
    printf("Cima de la pila: %d\n", top(&pila)); // Debería imprimir 30
    printf("Fondo de la pila: %d\n", fondo(&pila)); // Debería imprimir 10
    // Prueba de pop
    printf("Sacado de la pila: %d\n", top(&pila)); // Debería imprimir 30
    pop(&pila);
    //Prueba de popf
    printf("Fondo de la pila: %d\n", fondo(&pila)); // Debería imprimir 10
    popf(&pila);
    printf("Sacado de la pila: %d\n", top(&pila)); // Debería imprimir 20
    pop(&pila);
    push(&pila, 10);
    push(&pila, 20);
    push(&pila, 30);
    push(&pila, 30);
    push(&pila, 30);
    // Prueba de ver la cima nuevamente
    printf("Cima de la pila: %d\n", top(&pila)); // Debería imprimir 30

    // Prueba de ver reemplazar
     reemplazar(&pila,30,5);
     printf("Cima de la pila: %d\n", top(&pila)); // Debería imprimir 5
    // Prueba de pila vacía
    pop(&pila);
    if (esPilaVacia(&pila)) {
        printf("La pila está vacía.\n");
    }

    // Destruir la pila
    liberarPila(&pila);

    return 0;
}