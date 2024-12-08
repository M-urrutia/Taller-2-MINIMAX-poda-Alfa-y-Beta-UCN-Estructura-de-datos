#include "Nodo.hpp"

    Nodo::Nodo(Tablero tab, int Altura, int jugador, int Movimiento){
        hijos = std::vector<Nodo*>(0);
        asignado = new Tablero();
        *asignado = tab;
        valor = 900*jugador;
        altura = Altura;
        alfa = -900;
        beta = 900;
        movimiento = Movimiento;
        if(valor > 0){
            Estado = true;
        }
    };

    std::vector<Nodo*> Nodo::getListaHijos(){return hijos;}

    int Nodo::getMovimiento(){return movimiento;}

    Nodo* Nodo::getHijo(int num){return hijos[num];}

    Tablero Nodo::getTablero(){return *asignado;}

    int Nodo::getNumHijos(){return hijos.size();}

    void Nodo::agregarHijo(Nodo* nuevoHijo) {hijos.push_back(nuevoHijo);}

    void Nodo::setValor(int nuevoValor){valor = nuevoValor;}

    int Nodo::getValor(){return valor;}
    
    void Nodo::setAltura(int nuevoValor){altura = nuevoValor;}

    int Nodo::getAltura(){return altura;}

    bool Nodo::compararCon(Nodo* segundo){return this -> getTablero().compararCon(segundo -> getTablero());}

    int Nodo::getBeta(){return beta;}

    int Nodo::getAlfa(){return alfa;}

    void Nodo::setAlfa(int num){alfa = num;}

    void Nodo::setBeta(int num){beta = num;}

    bool Nodo::getEstado(){return Estado;}

    void Nodo::setEstado(bool nuevoEstado){Estado = nuevoEstado;}

    std::string Nodo::getMensaje(){return Mensaje;}

    void Nodo::setMensaje(std::string nuevoMensaje){Mensaje = nuevoMensaje;}

    Nodo::~Nodo() {
        delete asignado;
        if(hijos.size() != 0){
            for (Nodo* nodo : hijos) {
                delete nodo;
            }
            hijos.clear();
        }
    }
 
