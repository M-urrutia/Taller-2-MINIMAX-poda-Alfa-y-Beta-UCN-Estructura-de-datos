#include "Tablero.cpp"

class Nodo
{
private:
    Nodo** hijos;
    int numHijos;
    Tablero asignado;

public:
    Nodo(Tablero tab){
        hijos = nullptr;
        numHijos = 0;;
        asignado = tab;
    };

    Nodo* getHijo(int num){
        return hijos[num];
    }

    Tablero getTablero(){
        return asignado;
    }

    int getNumHijos(){
        return numHijos;
    }

    void agregarHijo(Nodo* nuevoHijo) {

        Nodo** nuevoArreglo = new Nodo*[numHijos + 1];
        
        for (int i = 0; i < numHijos; ++i) {
            nuevoArreglo[i] = hijos[i];
        }
        
        nuevoArreglo[numHijos] = nuevoHijo;
        
        delete[] hijos;
        hijos = nuevoArreglo;
        ++numHijos;
    }

    ~Nodo() {
        delete[] hijos;
    }
};
