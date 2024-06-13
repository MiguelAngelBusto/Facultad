#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main() {
    Fila fila;
    filaVacia(&fila);

    printf("La fila está vacía: %s\n", esFilaVacia(&fila) ? "true" : "false");

    enfila(&fila, 10);
    enfila(&fila, 20);
    enfila(&fila, 30);

    printf("El frente de la fila es: %d\n", frente(&fila));
    printf("La fila está vacía: %s\n", esFilaVacia(&fila) ? "true" : "false");

    defila(&fila);
    printf("El frente de la fila es: %d\n", frente(&fila));

    defila(&fila);
    printf("El frente de la fila es: %d\n", frente(&fila));

    defila(&fila);
    printf("El frente de la fila es: %d\n", frente(&fila));
    printf("La fila está vacía: %s\n", esFilaVacia(&fila) ? "true" : "false");

    return 0;
}