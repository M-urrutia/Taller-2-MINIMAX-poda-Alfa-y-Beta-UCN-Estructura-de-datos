#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 class Tablero
{
private:
    //Las posiciones en el tablero 3x3 van del 0 al 8, 
     std::vector<std::vector<int>> combinacionesGanadoras; //Vector de vectores que contiene las combinaciones de 3 posiciones que dan una victoria
     int lista[9]; //Una lista de datos que representa el tablero de 3x3, 0 si el espacio esta libre, 1 o -1 dependiendo de que jugador haya usado ese espacio

public:
    Tablero(); //Constructor del Tablero, inicia dejando ambas listas con todos sus elementos como 0 o "0"
     void setDato(int nuevo, int posicion); //Cambia un dato en la lista, y dependiendo si la jugada fue de -1 o 1, coloca una X o O en el lugar correspondiente
     int getDato(int posicion); //Devuelve el dato ubicado en una posicion en especifico
     void borrarDato(int posicion); //Establece el dato en una posicion como 0 en lista o "0" en la listaVisual
     void imprimirTablero(); //Imprime el tablero 
     bool compararCon(Tablero comparado); //Compara este tablero con un segundo tablero dato por dato en la lista principal, al encontrar un dato que sea distinto retorna falso ya que no son iguales, de lo contrario se asume que ambos son iguales y se retorna verdadero
     bool tableroLleno(); //Revisa si el tablero tiene todos los espacios ocupados, si es asi, retorna verdadero, de lo contrario retorna falso.
     int Ganador(); //Verifica si es que hay un ganador en el tablero, retornarndo 1 si el ganador es Max, -1 si es Min, o 0 si es que hay empate o no hay un ganador definido.
};