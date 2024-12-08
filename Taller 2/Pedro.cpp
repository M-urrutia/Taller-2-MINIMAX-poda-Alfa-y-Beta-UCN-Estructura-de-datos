#include "Pedro.hpp"
#include <cmath>

Nodo *Pedro::crearArbol(Nodo *raiz, int jugadorActual, std::vector<int> movimientosPosibles)
{
    int num = jugadorActual; //Cual de los jugadores corresponde de turno.
    int cont = 0; //Contador para la cantidad de movimientos posibles y moverse en el vector a la hora de hacer copias
    for (int i : movimientosPosibles)
    {
        Tablero aux = raiz->getTablero();
        aux.setDato(num, i); //Tablero derivado de la raiz con un dato extra en una posicion libre (i)

        Nodo *nuevoHijo = new Nodo(aux, raiz->getAltura() + 1, num * -1, i); //El nuevo hijo del nodo raiz

        //Ya sea que en el nuevo hijo haya un ganador o el tablero este lleno, indicara que el nuevo hijo es una hoja
        //Pensando que Pedro es Max, se penalizara cuando gane Min o se llegue a un empate

        if (aux.Ganador() == 1)
        {
            nuevoHijo->setValor(1); //Si el ganador es Max, el nodo tiene un valor de 1
            raiz->agregarHijo(nuevoHijo);
        }
        else if (aux.Ganador() == -1)
        {
            nuevoHijo->setValor(-2); //Si el ganador es Min, el nodo tiene un valor de -2
            raiz->agregarHijo(nuevoHijo);
        }
        else if (aux.tableroLleno())
        {
            nuevoHijo->setValor(-1); //Si hay un empate, el nodo tiene un valor de -1
            raiz->agregarHijo(nuevoHijo);
        }
        else
        {   
            // si el nuevo nodo no es hoja se crean noodos hijos y se agregan a la lista de hijos del nuevo nodo.
            
            std::vector<int> copia = movimientosPosibles;
            copia.erase(copia.begin() + cont);

            // copia es un vector que copia los movimientos posibles pero que 
            // le quita el movimiento ya usado para crear a Nuevo hijo.
            raiz->agregarHijo(crearArbol(nuevoHijo, num * -1, copia));
        }
        cont++;
    }
    return raiz;
}

Nodo *Pedro::establecerMiniMax(Nodo *raiz)
{
    if (raiz->getNumHijos() == 0)
    {
        return raiz; // Si no hay hijos, retorna el nodo
    }

    int alfa = raiz->getAlfa();
    int beta = raiz->getBeta();
    int bestVal;

    if (raiz->getEstado())
    { // Es el turno del Max
        bestVal = INT_MIN;
        for (Nodo *hijo : raiz->getListaHijos())
        {

            // se establece el valor del hijo con minimax hasta encontrar una hoja,
            //  entonces se comparara dicho valor con el mejor max 
            hijo = establecerMiniMax(hijo);
            bestVal = std::max(bestVal, hijo->getValor());
            alfa = std::max(alfa, bestVal);
            raiz->setValor(bestVal);
            if (beta <= alfa)
            {
                break; // Poda 
            }
        }
    }
    else
    { // Es el turno de Min
        bestVal = INT_MAX;
        for (Nodo *hijo : raiz->getListaHijos())
        {
            // se establece el valor del hijo con minimax hasta encontrar una hoja,
            //  entonces se compara dicho valor con el mejor para min
            hijo = establecerMiniMax(hijo);
            bestVal = std::min(bestVal, hijo->getValor());
            beta = std::min(beta, bestVal);
            raiz->setValor(bestVal);
            if (beta <= alfa)
            {
                break; // Poda
            }
        }
    }
    return raiz;
}

 
 
Nodo* Pedro::TurnoPedro(Nodo* situacionActual) {
         
        situacionActual->setAlfa(-900);
        situacionActual->setBeta(900);
        situacionActual = Pedro::establecerMiniMax(situacionActual);
        for (Nodo* hijo : situacionActual->getListaHijos()) {
            if (situacionActual->getValor() == hijo->getValor()) {
                situacionActual = hijo; // Selecciona el mejor movimiento
                break;
            }
        }
        return situacionActual;
}
