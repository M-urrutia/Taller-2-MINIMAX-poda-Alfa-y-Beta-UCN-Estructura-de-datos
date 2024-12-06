#include "Tablero.hpp"
#include <iostream>
using namespace std;

Tablero::Tablero() {
        for (int i = 0; i < 9; i++)
        {
            listaVisual[i] = "0";
            lista[i] = 0;
        }
        
    }

void Tablero::setDato(int nuevo, int posicion) {
        lista[posicion] = nuevo;
        if(nuevo == 1){listaVisual[posicion] = "O";}
        else {listaVisual[posicion] = "X";}
    }

int Tablero::getDato(int posicion) {
        return lista[posicion];
    }

void Tablero::borrarDato(int posicion){
        lista[posicion] = 0;
        listaVisual[posicion] = "0";
}

void Tablero::imprimirTablero() {
        for (int f = 0; f < 3; f++) {
            for (int c = 0; c < 3; c++) {
                cout << listaVisual[f*3 + c] << " "; 
            }
            cout << endl;
        }
        cout << "------------------" << endl;
    }

bool Tablero::compararCon(Tablero segundo){
    for(int i = 0 ; i < 9 ; i++){
        if(lista[i] != segundo.getDato(i)){
            return false;
        }
    }
    return true;
}

bool Tablero::tableroLleno(){
    for (int i = 0; i < 9; i++)
    {
        if (lista[i] == 0)
        {
            return false;
        }
        
    }
    return true;
}
