#include "Tablero.cpp"
using namespace std;
#include <vector>

class Nodo
{
private:
    vector<Nodo*> hijos;
    Tablero* asignado;
    int valor;
    int altura;
    int alfa;
    int beta;
    bool Estado;
    string Mensaje;

public:
    Nodo(Tablero tab, int Altura, int jugador){
        hijos = vector<Nodo*>(0);
        asignado = new Tablero();
        *asignado = tab;
        valor = 900*jugador;
        altura = Altura;
        alfa = -900;
        beta = 900;
        if(valor > 0){
            Estado = true;
        }
    };

    vector<Nodo*> getListaHijos(){
        return hijos;
    }

    Nodo* getHijo(int num){
        return hijos[num];
    }

    Tablero getTablero(){
        return *asignado;
    }

    int getNumHijos(){
        return hijos.size();
    }

    void agregarHijo(Nodo* nuevoHijo) {
        hijos.push_back(nuevoHijo);
    }

    void setValor(int nuevoValor){
        valor = nuevoValor;
    }

    int getValor(){
        return valor;
    }
    
    void setAltura(int nuevoValor){
        altura = nuevoValor;
    }

    int getAltura(){
        return altura;
    }

    void BorrarHijo(int i){
        delete hijos[i];
        hijos.erase(hijos.begin() + i);
    }

    void BorrarTodosHijos(){
        for (Nodo* nodo : hijos) {
            delete nodo;
        }
        hijos.clear();
    }

    void BorrarHijosDesde(int indice){
        while (hijos.size() != indice){
            BorrarHijo(hijos.size()-1);
        }
    }

    bool compararCon(Nodo* segundo){
        return this -> getTablero().compararCon(segundo -> getTablero());
    }

    int getBeta(){
        return beta;
    }

    int getAlfa(){
        return alfa;
    }

    void setAlfa(int num){
        alfa = num;
    }

    void setBeta(int num){
        beta = num;
    }

    bool getEstado(){
        return Estado;
    }

    void setEstado(bool nuevoEstado){
        Estado = nuevoEstado;
    }

    string getMensaje(){
        return Mensaje;
    }

    void setMensaje(string nuevoMensaje){
        Mensaje = nuevoMensaje;
    }

    ~Nodo() {
        delete asignado;
        if(hijos.size() != 0){
            this -> BorrarTodosHijos();
        }
    }
};
