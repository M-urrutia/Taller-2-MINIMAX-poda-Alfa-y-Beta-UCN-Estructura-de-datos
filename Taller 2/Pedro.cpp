#include "Pedro.hpp"

Nodo* Pedro::crearArbol(Nodo* raiz, int jugadorActual, std::vector<int> movimientosPosibles){
    int num = jugadorActual;
    int cont = 0;
    for(int i: movimientosPosibles){
        Tablero aux = raiz -> getTablero();
        aux.setDato(num , i);

        Nodo* nuevoHijo = new Nodo(aux, raiz -> getAltura() + 1 , num*-1, i);
            
        if (aux.Ganador() != 0) {
            nuevoHijo -> setValor(num * (10 - nuevoHijo -> getAltura()));
            raiz -> agregarHijo(nuevoHijo);
            
        } else if(aux.tableroLleno()){
            nuevoHijo -> setValor(0);
            raiz -> agregarHijo(nuevoHijo);
        } else {
            std::vector<int> copia = movimientosPosibles;
            copia.erase(copia.begin() + cont);
            raiz -> agregarHijo(crearArbol(nuevoHijo, num*-1, copia));
        }
        cont++;
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






