#include "Pedro.hpp"

Nodo* Pedro::crearArbol(Nodo* raiz, int jugadorActual){
    int num = jugadorActual;
    
    for(int i = 0 ; i < 9 ; ++i){
        if(raiz -> getTablero().getDato(i) == 0){
            Tablero aux = raiz -> getTablero();
            aux.setDato(num , i);

            Nodo* nuevoHijo = new Nodo(aux, raiz -> getAltura() + 1 , num*-1);
            
            if (Juez::verificar(&aux, i, num)) {
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

void  Pedro::establecerMiniMax(Nodo* raiz) {
    for (Nodo* hijo : raiz -> getListaHijos()) {
        hijo -> setAlfa(raiz -> getAlfa());
        hijo -> setBeta(raiz -> getBeta());

        if (hijo -> getNumHijos() != 0) {
            establecerMiniMax(hijo);
        }

        if (raiz -> getEstado()) {
            raiz -> setAlfa(std::max(raiz -> getAlfa(), hijo -> getValor()));
            raiz -> setValor(raiz -> getAlfa());
        } else {
            raiz -> setBeta(std::min(raiz -> getBeta(), hijo -> getValor()));
            raiz -> setValor(raiz -> getBeta());
        }

        if (raiz -> getAlfa() >= raiz -> getBeta()) {
            break;
        }
    }
}

Nodo* Pedro::TurnoPedro(Nodo* situacionActual){
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

