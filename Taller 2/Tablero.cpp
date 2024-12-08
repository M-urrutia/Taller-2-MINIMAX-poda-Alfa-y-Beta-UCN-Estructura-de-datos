#include "Tablero.hpp"

Tablero::Tablero() {
        for (int i = 0; i < 9; i++)
        {
            lista[i] = 0;
        }
        combinacionesGanadoras = {
            // que es esto ??
            {0,4,8},
            {6,4,2},
            {0,1,2},
            {3,4,5},
            {6,7,8},
            {0,3,6},
            {1,4,7},
            {2,5,8}
        };        
    }

void Tablero::setDato(int nuevo, int posicion) {
        Tablero::lista[posicion] = nuevo;
        
    }

int Tablero::getDato(int posicion) {
        return Tablero::lista[posicion];
    }

void Tablero::borrarDato(int posicion){
        Tablero::lista[posicion] = 0;
}

void Tablero::imprimirTablero() {

        int tablero[9];
        std::copy(Tablero::lista, Tablero::lista + 9, tablero);
        for (int f = 0; f < 3; f++) {
            for (int c = 0; c < 3; c++) {
                if(tablero[f*3 + c] == 1) std::cout << "O" << " ";
                if(tablero[f*3 + c] == -1)std::cout << "X" << " ";
                if(tablero[f*3 + c] == 0)std::cout << "0" << " ";
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

int Tablero::Ganador(){
    for (std::vector<int> i : Tablero::combinacionesGanadoras)
    {
        if ((lista[i[0]] == lista[i[1]] && lista[i[0]] != 0) && (lista[i[1]] == lista[i[2]] && lista[i[1]] != 0) && (lista[i[2]] == lista[i[0]] && lista[i[2]] != 0))
        {
            return lista[i[0]];
        }
    }
    return 0;
    
}

