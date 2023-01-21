#include "lista.h"
#include <stdlib.h>

Nodo *CrearNodo(char letra)
{
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    nodo->siguiente = NULL;
    return nodo;
}

void DestruirNodo(Nodo *nodo)
{
    free(nodo);
}

void InsertarPrincipio(Lista *lista, char letra)
{
    Nodo *nodo = CrearNodo(letra);
    nodo->siguiente = lista->cabeza;
    lista->cabeza = nodo;
    lista->longitud++;
}

void InsertarFinal(Lista *lista, char letra)
{
    Nodo *nodo = CrearNodo(letra);
    if (lista->cabeza == NULL)
    {
        lista->cabeza = nodo;
    }
    else
    {
        Nodo *puntero = lista->cabeza;
        while (puntero->siguiente)
        {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

void InsertarDespues(int n, Lista *lista, char letra)
{
    Nodo *nodo = CrearNodo(letra);
    if (lista->cabeza == NULL)
    {
        lista->cabeza = nodo;
    }
    else
    {
        Nodo *puntero = lista->cabeza;
        int posicion = 0;
        while (posicion < n && puntero->siguiente)
        {
            puntero = puntero->siguiente;
            posicion++;
        }
        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

int Contar(Lista *lista)
{
    return lista->longitud;
}

int EstaVacia(Lista *lista)
{
    return lista->cabeza == NULL;
}

void EliminarPrincipio(Lista *lista)
{
    if (!EstaVacia(lista))
    {

        Nodo *elimidado = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        DestruirNodo(elimidado);
        lista->longitud--;
    }
}

void EliminarUltimo(Lista *lista)
{
    if (lista->cabeza)
    {
        if (lista->cabeza->siguiente)
        {
            Nodo *puntero = lista->cabeza;
            while (puntero->siguiente->siguiente)
            {
                puntero = puntero->siguiente;
            }
            Nodo *eliminado = puntero->siguiente;
            puntero->siguiente = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        }
        else
        {
            Nodo *eliminado = lista->cabeza;
            lista->cabeza = NULL;
            DestruirNodo(eliminado);
            lista->longitud--;
        }
    }
}