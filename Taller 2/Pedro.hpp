#include "Nodo.hpp"
#include <queue>
#include <stack>
#include <string>
#include <iostream>

class Pedro {
public:
    // Constructor
   
    static Nodo* crearArbol(Nodo* raiz, int jugadorActual, std::vector<int> movimientosPosibles);
    static void  establecerMiniMax(Nodo* raiz);
    static Nodo* TurnoPedro(Nodo* situacionActual);
    // Member functions
 

};

 