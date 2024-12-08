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

Nodo* JugarHumanos(int turnoActual, int humano1, int humano2, Nodo* situacionActual){
    cout << "turno del jugador " << turnoActual << endl;
    situacionActual -> getTablero().imprimirTablero();
    

    if (turnoActual == humano1)
    {
        turnoActual = humano2;
        return Pedro::TurnoPedro(situacionActual);
    } else {
        turnoActual = humano1;
        return Pedro::TurnoPedro(situacionActual);
    }
}

int Menu(){
    cout << "Ingrese la opcion que desee:" << endl;
    cout << "1) Humano v/s IA" << endl;
    cout << "2) IA v/s IA" << endl;
    cout << "3) Humano v/s Humano" << endl;
    cout << "4) Terminar Programa" << endl;
    int decision;
    cin >> decision;

    while(decision < 1 || decision > 4){
        cout << "opcion no valida, intente otra vez" << endl;
        cin >> decision;
    }

    return decision;
}


int main() {
    Tablero* inicial = new Tablero();
    Nodo* raiz = new Nodo(*inicial, 1 , 1, -1);

    raiz = Pedro::crearArbol(raiz, 1);
    Nodo* actual = raiz;
    
    int utilidad = Menu();

    while (utilidad != 4)
    {
        int turnoInicial = 1;
        switch (utilidad){
            case 1: while (actual -> getNumHijos() != 0)
            {
                actual = Jugar(turnoInicial, 1, -1, actual);
                turnoInicial = turnoInicial*-1;
            } break;
            

            case 2: while (actual -> getNumHijos() != 0)
            {
                actual = JugarIAS(turnoInicial, 1, -1, actual);
                turnoInicial = turnoInicial*-1;
            } break;
            

            case 3: while (actual -> getNumHijos() != 0)
            {
                actual = JugarHumanos(turnoInicial, 1, -1, actual);
                turnoInicial = turnoInicial*-1;
            } break;
            

            default: break; 
        }
        actual -> getTablero().imprimirTablero();
        cout << actual -> getMensaje() << endl;
        actual = raiz;
        utilidad = Menu();
    }
    

    delete inicial;
    delete raiz;
    
    return 0;
}
