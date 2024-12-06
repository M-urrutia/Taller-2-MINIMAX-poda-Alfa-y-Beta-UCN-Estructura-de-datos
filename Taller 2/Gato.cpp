#pragma once
#include <iostream>
#include "Pedro.hpp"
#include "windows.h"
#include <ctime>
using namespace std;

Nodo* TurnoHumano(Nodo* situacionActual, int jugador){
    Tablero aux = situacionActual -> getTablero();
    int posicion;
    bool libre;
    do
    {
        cout << "ingrese la posición en la que desea jugar" << endl;
        cin >> posicion;
        libre = aux.getDato(posicion) != 0;
    } while (posicion < 0 || posicion > 8 || libre != 0);
    
    aux.setDato(jugador, posicion);

    for(Nodo* hijo: situacionActual -> getListaHijos()){
        if(hijo -> getTablero().compararCon(aux)){
            situacionActual = hijo;
            break;
        }
    }
    return situacionActual;
}

Nodo* Jugar(int turnoActual,int jugadorHumano, int Pedro, Nodo* situacionActual){
    situacionActual -> getTablero().imprimirTablero();

    if (turnoActual == jugadorHumano)
    {
        turnoActual = Pedro;
        return TurnoHumano(situacionActual, jugadorHumano);
    } else {
        turnoActual = jugadorHumano;
        return Pedro::TurnoPedro(situacionActual);
    }
}

Nodo* JugarIAS(int turnoActual, int Pedro1, int Pedro2, Nodo* situacionActual){
    cout << "turno del jugador " << turnoActual << endl;
    situacionActual -> getTablero().imprimirTablero();
    

    if (turnoActual == Pedro1)
    {
        turnoActual = Pedro2;
        return Pedro::TurnoPedro(situacionActual);
    } else {
        turnoActual = Pedro1;
        return Pedro::TurnoPedro(situacionActual);
    }
}

int main() {
    Tablero* inicial = new Tablero();
    Nodo* raiz = new Nodo(*inicial, 1 , 1);
    unsigned t0, t1;
    t0 = clock();
    // Code to execute
    t1 = clock();
    raiz = Pedro::crearArbol(raiz, 1);

    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;

    Nodo* actual = raiz;
    int turnoInicial = 1;
    while (actual -> getNumHijos() != 0)
    {
        actual = Jugar(turnoInicial , 1 , -1 , actual);
        turnoInicial = turnoInicial * -1;
    }
    actual -> getTablero().imprimirTablero();
    cout << actual -> getMensaje() << endl;

    delete inicial;
    delete raiz;
    
    return 0;
}
