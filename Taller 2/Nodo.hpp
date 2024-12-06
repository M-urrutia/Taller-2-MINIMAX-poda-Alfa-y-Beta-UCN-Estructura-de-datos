#pragma once
#include "Tablero.cpp"
#include <vector>
using namespace std;

class Nodo
{
private:
    vector<Nodo*> hijos; //Una lista con los vectores con todos los hijos de este nodo
    Tablero* asignado; //El tablero que representa este Nodo
    int valor; //Valor necesario para las comparaciones MiniMax, 0 si es un empate, >0 para Max, <0 para Min
    int altura; //Altura a la que se encuentra el nodo del arbol, desde 1 hasta 10
    int alfa; //Para el uso de poda alfa en MiniMax
    int beta; //Para el uso de poda beta en MiniMax
    bool Estado; // true si es que este nodo es Max, false si el nodo es Min
    string Mensaje; //Un mensaje para imprimir en consola si es que gana uno de los jugadores o un empate

public:
    Nodo(Tablero tab, int Altura, int jugador); //Constructor con un tablero, la altura del nodo y un "jugador" [-1 o 1] que sirve para asignar un valor base
    vector<Nodo*> getListaHijos(); //devuelve la lista de hijos
    Nodo* getHijo(int num); //Devuelve un Nodo hijo en especifico, requiere del indice de dicho nodo en la lista de hijos
    Tablero getTablero(); //Devuelve el tablero asignado a este nodo.
    int getNumHijos(); //Devuelve el numero de hijos que tiene este nodo.
    void agregarHijo(Nodo* nuevoHijo); //Agrega un Nodo hijo a la lista de hijos.
    void setValor(int nuevoValor); //Cambia el valor por uno nuevo.
    int getValor(); //Devuelve el valor.
    void setAltura(int nuevoValor); //Cambia la altura por una nueva.
    int getAltura(); //Devuelve la altura del nodo.
    bool compararCon(Nodo* segundo); //Compara este Nodo con otro al comparar los tableros asignados de cada uno
    int getBeta(); //Devuelve el valor beta.
    int getAlfa(); //Devuelve el valor alfa.
    void setAlfa(int num); //Cambia el valor alfa por uno nuevo.
    void setBeta(int num); //Cambia el valor beta por uno nuevo.
    bool getEstado(); //Devuelve el estado del Nodo.
    void setEstado(bool nuevoEstado); //Cambia el estado de este nodo por uno nuevo.
    string getMensaje(); //Devuelve el mensaje de este nodo.
    void setMensaje(string nuevoMensaje); //Cambia el mensaje de este nodo por uno nuevo.
    ~Nodo(); //Destructor del Nodo, al destruirse, destruye todas las ramas que salgan a partir de este Nodo de manera recursiva.
};
