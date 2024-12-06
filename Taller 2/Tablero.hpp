#pragma once

class Tablero
{
private:
    int lista[9];

public:
    Tablero();
    void setDato(int nuevo, int posicion);
    int getDato(int posicion);
    void borrarDato(int posicion);
    void imprimirTablero();
    bool espacio();
    bool compararCon(Tablero comparado);
    bool tableroLleno();
};