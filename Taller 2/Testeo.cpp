// main.cpp
#include <iostream>
#include "Tablero.hpp"  // Incluir la cabecera de Tablero

using namespace std;

int main() {
    // Crear una instancia de la clase Tablero
    Tablero* tablero = new Tablero();

    // Imprimir el tablero inicial (todos los valores deben ser 0)
    cout << "Tablero inicial:" << endl;
    tablero->imprimirTablero();

    // Establecer algunos valores
    tablero->setDato(1, 0);  // Colocar el valor 1 en la posición 0
    tablero->setDato(-1, 4); // Colocar el valor -1 en la posición 4

    // Imprimir el tablero después de modificar algunos valores
    cout << "\nTablero después de modificar algunas posiciones:" << endl;
    tablero->imprimirTablero();

    // Imprimir un dato específico
    cout << "\nDato en la posición 4: " << tablero->getDato(4) << endl;

    // Liberar la memoria
    delete tablero;

    return 0;
}
