#include "Tablero.hpp"
#include <iostream>
using namespace std;

Tablero::Tablero() {
        for (int i = 0; i < 9; i++)
        {
            lista[i] = 0;
        }
        
    }

void Tablero::setDato(int nuevo, int posicion) {
        lista[posicion] = nuevo;
    }

int Tablero::getDato(int posicion) {
        return lista[posicion];
    }

void Tablero::borrarDato(int posicion){
        lista[posicion] = 0;
}

void Tablero::imprimirTablero() {
        for (int f = 0; f < 3; f++) {
            for (int c = 0; c < 3; c++) {
                cout << lista[f*3 + c] << " "; 
            }
            cout << endl;
        }
        cout << "------------------" << endl;
    }

bool Tablero::espacio(){
    for (int i = 0; i < 9; i++)
    {
        if(lista[i] == 0){
            return true;
        }
    }
    return false; 
}

bool Tablero::compararCon(Tablero segundo){
    for(int i = 0 ; i < 9 ; i++){
        if(lista[i] != segundo.getDato(i)){
            return false;
        }
    }
    return true;
}
