/*El objetivo del ejercicio es implementar un calculador de expresiones postfijas usando una pila. 
Una expresión postfija (o notación polaca inversa) es una forma de escribir expresiones aritméticas 
sin paréntesis, donde los operadores siguen a sus operandos. Por ejemplo, la expresión infija 3 + 4 
se escribe como 3 4 + en notación postfija.

Instrucciones
Definir la Pila:

Implementa una clase Pila que tenga las siguientes operaciones:
push(elemento): Inserta un elemento en la pila.
pop(): Elimina y devuelve el elemento en la cima de la pila.
peek(): Devuelve el elemento en la cima de la pila sin eliminarlo.
is_empty(): Devuelve True si la pila está vacía, de lo contrario, False.
Implementar el Calculador de Expresiones Postfijas:

Implementa una función evaluar_expresion_postfija(expresion) que tome una expresión postfija como una cadena de texto y devuelva el resultado de la evaluación.
La función debe usar una pila para realizar la evaluación.
La expresión puede contener números enteros y los operadores +, -, *, /.
Ejemplos:

evaluar_expresion_postfija("3 4 +") debe devolver 7.
evaluar_expresion_postfija("10 6 9 3 + -11 * / * 17 + 5 +") debe devolver 22.
*/

#include <stdalign.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct Nodo
{
    char dato;
    Nodo* siguiente;
} Nodo;

typedef struct Pila {
    Nodo* cima;
} Pila;

Pila* crearPila() {
    Pila* pila = (Pila*)malloc(sizeof(Pila));
    pila->cima = NULL;
    return Pila;
}

void push (Pila* h, char x){
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo*));
    aux->dato=x;
    aux->siguiente=h->cima;
    h->cima=aux;
}

void pop (Pila* h){
    Nodo* aux = (Nodo*)malloc(sizeof(Nodo*));
    aux=h->cima;
    h->cima=aux->siguiente;
    free(aux);
}


bool esPilaVacia (Pila* h){
    if(h->cima!=NULL){
        return false;
    }else{
        return true;
    }
}

char top (Pila* h){
    if(!esPilaVacia(h)){
        return h->cima->dato;
    } else {
        return "?";
    }
}

int main (){
    string x = "(A+B)/C-D=";

    return 0;
}