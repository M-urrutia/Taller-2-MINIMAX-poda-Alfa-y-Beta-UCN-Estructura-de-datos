#include "Tablero.hpp"
#include <string>

class Juez {
public:
    // Constructor
    static bool esquina1(Tablero* tablero, int posicion, int jugador, int direccion);
    static bool esquina2(Tablero* tablero, int posicion, int jugador, int direccion);
    static bool bordeFila(Tablero* tablero, int posicion, int jugador, int direccion);
    static bool bordeColumna(Tablero* tablero, int posicion, int jugador, int direccion);
    static bool centro(Tablero* tablero, int posicion, int jugador);
    static bool verificar(Tablero* tablero, int posicion, int jugador);
 
    
};
 