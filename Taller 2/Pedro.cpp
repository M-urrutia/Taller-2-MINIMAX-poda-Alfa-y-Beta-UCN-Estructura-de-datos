#include "Nodo.cpp"
#include <iostream>

using namespace std;

void imprimirHijos(Nodo* raiz){
    for (int i = 0; i < raiz -> getNumHijos(); i++){
        raiz -> getHijo(i) -> getTablero().imprimirTablero();
    }
}

void imprimirArbol(Nodo* raiz){
    imprimirHijos(raiz);
    if (raiz -> getNumHijos() == 0)
    {
        return;
    }
    
    for (int i = 0; i < raiz -> getNumHijos(); i++){
        imprimirArbol(raiz -> getHijo(i));
    }
}

Nodo* crearArbol(Nodo* raiz, int jugadorActual){
    int num = jugadorActual;
    Tablero* simulado = new Tablero();
    *simulado = raiz -> getTablero();
    
    for (int i = 0; i < 9; i++)
    {
        if(simulado -> getDato(i) == 0){
            simulado -> setDato(num,i);
            raiz -> agregarHijo(new Nodo(*simulado));
            simulado -> borrarDato(i);
        }
    }

    if(num == 1){
        num = -1;
    } else {
        num = 1;
    }

    for (int i = 0; i < raiz -> getNumHijos(); i++)
    {   
        crearArbol(raiz ->getHijo(i),num);
    }

    return raiz;
}

int main()
{
    Tablero* tab = new Tablero();
    Nodo* raiz = new Nodo(*tab);
    
    raiz = crearArbol(raiz,1);

    imprimirArbol(raiz);
    return 0;
}