#pragma once

class Tablero
{
private:
    //Las posiciones en el tablero 3x3 van del 0 al 8, 
    int lista[9]; //Una lista de datos que representa el tablero de 3x3, 0 si el espacio esta libre, 1 o -1 dependiendo de que jugador haya usado ese espacio
    string listaVisual[9]; //La misma lista pero de manera visual, 0 si el espacio esta vacio, X para el jugador -1 y O para el jugador 1

public:
    Tablero(); //Constructor del Tablero, inicia dejando ambas listas con todos sus elementos como 0 o "0"
    void setDato(int nuevo, int posicion); //Cambia un dato en la lista, y dependiendo si la jugada fue de -1 o 1, coloca una X o O en el lugar correspondiente
    int getDato(int posicion); //Devuelve el dato ubicado en una posicion en especifico
    void borrarDato(int posicion); //Establece el dato en una posicion como 0 en lista o "0" en la listaVisual
    void imprimirTablero(); //Imprime el tablero 
    bool compararCon(Tablero comparado); //Compara este tablero con un segundo tablero dato por dato en la lista principal, al encontrar un dato que sea distinto retorna falso ya que no son iguales, de lo contrario se asume que ambos son iguales y se retorna verdadero
    bool tableroLleno(); //Revisa si el tablero tiene todos los espacios ocupados, si es asi, retorna verdadero, de lo contrario retorna falso.
};