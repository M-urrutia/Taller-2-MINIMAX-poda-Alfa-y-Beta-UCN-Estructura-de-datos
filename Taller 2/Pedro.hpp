#include "Nodo.hpp"
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <limits>

class Pedro {
public:
    // Constructor
   
    static Nodo* crearArbol(Nodo* raiz, int jugadorActual, std::vector<int> movimientosPosibles); //Crea todas las ramas (con sus respectivas subramas) de una raíz de manera recursiva.
    static Nodo* TurnoPedro(Nodo* situacionActual); //Pedro utiliza Minimax con poda alfa y beta para decidir a cual es el mejor nodo al que puede moverse
    static Nodo* establecerMiniMax(Nodo* raiz);//Establece el valor de un nodo segun MiniMax con poda alfa y beta.
    // Member functions
 

};

 