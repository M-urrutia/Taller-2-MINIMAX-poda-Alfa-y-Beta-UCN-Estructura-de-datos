#include "Nodo.cpp"
#include "Juez.cpp"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

Nodo* crearArbol(Nodo* raiz, int jugadorActual){
    int num = jugadorActual;
    
    for(int i = 0 ; i < 9 ; ++i){
        if(raiz -> getTablero().getDato(i) == 0){
            Tablero aux = raiz -> getTablero();
            aux.setDato(num , i);

            Nodo* nuevoHijo = new Nodo(aux, raiz -> getAltura() + 1 , num*-1);
            
            if (verificar(&aux, i, num)) {
                nuevoHijo -> setValor(num * (10 - nuevoHijo -> getAltura()));
                if(nuevoHijo -> getValor() < 0 ){
                    nuevoHijo -> setMensaje("El ganador es el jugador -1");
                } else {
                    nuevoHijo -> setMensaje("El ganador es el jugador 1");
                }
                raiz -> agregarHijo(nuevoHijo);
                
            } else if(aux.tableroLleno()){
                nuevoHijo -> setValor(0);
                nuevoHijo -> setMensaje("Esto es un empate!");
                raiz -> agregarHijo(nuevoHijo);
            } else {
                raiz -> agregarHijo(crearArbol(nuevoHijo, num*-1));
            }
            
            aux.borrarDato(i);
        }
    }
    return raiz;
}

void establecerMiniMax(Nodo* raiz) {
    for (Nodo* hijo : raiz -> getListaHijos()) {
        hijo -> setAlfa(raiz -> getAlfa());
        hijo -> setBeta(raiz -> getBeta());

        if (hijo -> getNumHijos() != 0) {
            establecerMiniMax(hijo);
        }

        if (raiz -> getEstado()) {
            raiz -> setAlfa(max(raiz -> getAlfa(), hijo -> getValor()));
            raiz -> setValor(raiz -> getAlfa());
        } else {
            raiz -> setBeta(min(raiz -> getBeta(), hijo -> getValor()));
            raiz -> setValor(raiz -> getBeta());
        }

        if (raiz -> getAlfa() >= raiz -> getBeta()) {
            break;
        }
    }
}

Nodo* TurnoPedro(Nodo* situacionActual){
    situacionActual -> setAlfa(-900);
    situacionActual -> setBeta(900);
    establecerMiniMax(situacionActual);
    for(Nodo* hijo : situacionActual -> getListaHijos()){
        if(situacionActual -> getValor() == hijo -> getValor()){
            situacionActual = hijo;
            break;
        }
    }
    return situacionActual;
}

