#include "Tablero.hpp"

 

Tablero::Tablero() {
        for (int i = 0; i < 9; i++)
        {
            Tablero::listaVisual[i] = "0";
            lista[i] = 0;
        }
        
    }

void Tablero::setDato(int nuevo, int posicion) {
        Tablero::lista[posicion] = nuevo;
        if(nuevo == 1){Tablero::listaVisual[posicion] = "O";}
        else {Tablero::listaVisual[posicion] = "X";}
    }

int Tablero::getDato(int posicion) {
        return Tablero::lista[posicion];
    }

void Tablero::borrarDato(int posicion){
        Tablero::lista[posicion] = 0;
        Tablero::listaVisual[posicion] = "0";
}

void Tablero::imprimirTablero() {
        for (int f = 0; f < 3; f++) {
            for (int c = 0; c < 3; c++) {
                std::cout << Tablero::listaVisual[f*3 + c] << " "; 
            }
            std::cout << std::endl;
        }
        std::cout << "------------------" << std::endl;
    }

bool Tablero::compararCon(Tablero segundo){
    for(int i = 0 ; i < 9 ; i++){
        if(Tablero::lista[i] != segundo.getDato(i)){
            return false;
        }
    }
    return true;
}

bool Tablero::tableroLleno(){
    for (int i = 0; i < 9; i++)
    {
        if (Tablero::lista[i] == 0)
        {
            return false;
        }
        
    }
    return true;
}
