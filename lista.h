#ifndef lista_h
#define lista_h

#include <stdio.h>

typedef struct Nodo
{
    char letra;
    struct Nodo *siguiente;
} Nodo;

typedef struct Lista
{
    Nodo *cabeza;
    int longitud;
} Lista;

Nodo *CrearNodo(char letra);
void DestruirNodo(Nodo *nodo);
void InsertarPrincipio(Lista *lista, char letra);
void InsertarFinal(Lista *lista, char letra);
void InsertarDespues(int n, Lista *lista, char letra);
int Contar(Lista *lista);
int EstaVacia(Lista *lista);
void EliminarPrincipio(Lista *lista);
void EliminarUltimo(Lista *lista);

#endif /* lista_h */
