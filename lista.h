#ifndef lista_h
#define lista_h

#include <stdio.h>

typedef struct Nodo {
    char letra;
    struct Nodo* siguiente;
} Nodo;

typedef struct Lista {
    Nodo* cabeza;
} Lista;

#endif /* lista_h */
