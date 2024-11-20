#include <iostream>
using namespace std;
#include "Tablero.cpp"
#include "windows.h"

bool esquina1(Tablero* tablero, int posicion, int jugador, int direccion){
    int dato1, dato2;
    int importante[] = {1,4,3};

    for (int i = 0; i < 3; i++)
    {
        dato1 = tablero -> getDato(posicion + (direccion) * importante[i]);
        dato2 = tablero -> getDato(posicion + (direccion) * (importante[i]*2));
        if (dato1 == dato2 && dato1 == jugador){
            return true;
        } 
    }
    return false;
}

bool esquina2(Tablero* tablero, int posicion, int jugador, int direccion){
    int dato1, dato2;
    int importante[] = {-1,2,3};

    for (int i = 0; i < 3; i++)
    {
        dato1 = tablero -> getDato(posicion + (direccion) * importante[i]);
        dato2 = tablero -> getDato(posicion + (direccion) * (importante[i]*2));
        if (dato1 == dato2 && dato1 == jugador){
            return true;
        }   
    }
    return false;
}

bool bordeFila(Tablero* tablero, int posicion, int jugador, int direccion){
    int dato1, dato2;
    
    dato1 = tablero -> getDato(posicion-1);
    dato2 = tablero -> getDato(posicion+1);
    if (dato1 == dato2 && dato1 == jugador){
        return true;
    } 
    
    dato1 = tablero -> getDato(posicion + (direccion)*3);
    dato2 = tablero -> getDato(posicion + (direccion)*6);
    if (dato1 == dato2 && dato1 == jugador){
        return true;
    } 
    return false;
}

bool bordeColumna(Tablero* tablero, int posicion, int jugador, int direccion){
    int dato1, dato2;
    
    dato1 = tablero -> getDato(posicion-3);
    dato2 = tablero -> getDato(posicion+3);
    if (dato1 == dato2 && dato1 == jugador){
        return true;
    } 
    
    dato1 = tablero -> getDato(posicion + (direccion)*1);
    dato2 = tablero -> getDato(posicion + (direccion)*2);
    if (dato1 == dato2 && dato1 == jugador){
        return true;
    } 
    return false;
}

bool centro(Tablero* tablero, int posicion, int jugador){
    int dato1, dato2;
    
    for (int i = 1; i < 5; i++)
    {
        dato1 = tablero -> getDato(posicion-i);
        dato2 = tablero -> getDato(posicion+i);
        if(dato1 == dato2 && dato1 == jugador){
            return true;
        }
    }
    return false;
}

bool verificar(Tablero* tablero, int posicion, int jugador){
    switch(posicion){
        case 0: return esquina1(tablero, posicion, jugador, 1); break;
        case 1: return bordeFila(tablero, posicion, jugador, 1); break;
        case 2: return esquina2(tablero, posicion, jugador,1); break;
        case 3: return bordeColumna(tablero, posicion, jugador, 1); break;
        case 4: return centro(tablero, posicion, jugador); break;
        case 5: return bordeColumna(tablero, posicion, jugador, -1); break;
        case 6: return esquina2(tablero, posicion, jugador, -1); break;
        case 7: return bordeFila(tablero, posicion, jugador, -1); break;
        case 8: return esquina1(tablero, posicion, jugador, -1); break;
        default: return false;
    }
}

bool Jugada(Tablero* tablero, int jugador){
    int posicion;
    bool lel;
    do
    {
        cout << "ingrese la posición en la que desea jugar" << endl;
        cin >> posicion;
        lel = tablero->getDato(posicion) != 0;
    } while (posicion < 0 || posicion > 8 || lel != 0);
    
    tablero -> setDato(jugador, posicion);
    tablero -> imprimirTablero();
    return verificar(tablero, posicion, jugador);
}

int main() {
    Tablero* tablero = new Tablero();
    int Jugador1 = 1;
    int Jugador2 = -1;
    int JugadorActual = -1;
    
    tablero -> imprimirTablero();
    cout << tablero -> getDato(2) << endl;
    do
    {
        if (JugadorActual == Jugador1){
            JugadorActual = Jugador2;
        }else{
           JugadorActual = Jugador1;
        }
        tablero -> imprimirTablero();

    } while (!Jugada(tablero, JugadorActual));
    



    delete tablero;
    return 0;
}
