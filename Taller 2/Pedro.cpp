#include "Nodo.cpp"
#include "Juez.cpp"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void imprimirHijos(Nodo* raiz){
    for(int i = 0 ; i < raiz -> getNumHijos() ; i++){
        raiz -> getHijo(i) -> getTablero().imprimirTablero();
    }
}

Nodo* crearHijos(Nodo* raiz, int jugadorActual){
    int num = jugadorActual * -1;
    
    for(int i = 0 ; i < 9 ; ++i){
        if(raiz -> getTablero().getDato(i) == 0){
            Tablero aux = raiz -> getTablero();
            aux.setDato(num , i);

            Nodo* nuevoHijo = new Nodo(aux, raiz -> getAltura() + 1 , num*-1);
            
            if (verificar(&aux, i, num)){
                nuevoHijo -> setValor(num * (10 - nuevoHijo -> getAltura()));
                raiz -> agregarHijo(nuevoHijo);
            }else{
                raiz -> agregarHijo(crearHijos(nuevoHijo,num));
                }
            aux.borrarDato(i);
        }
    }
    return raiz;
}

Nodo* establecerMiniMax(Nodo* raiz, bool MAX){
    for(Nodo* hijo : raiz -> getListaHijos()){
        hijo -> setAlfa(raiz -> getAlfa());
        hijo -> setBeta(raiz -> getBeta());

        if(MAX){
            return raiz;
        }
    }
    return raiz;
}

int contarArbol(Nodo* raiz){
    int contador = 0;
    queue<Nodo*> cola;
    cola.push(raiz);

    while (!cola.empty()){
        Nodo* actual = cola.front();
        cola.pop();
        contador++;
        for (int i = 0 ; i < actual-> getNumHijos() ; ++i){
            cola.push(actual -> getHijo(i));
        }
    }   
    return contador;
}

void encontrarGanador(Nodo* raiz){
    Nodo* actual = raiz;
    queue<Nodo*> cola;
    cola.push(actual);

    while (!cola.empty()){
        actual = cola.front();
        cola.pop();

        if (actual -> getValor() != 0){
            cout << actual -> getValor() << endl;
            actual -> getTablero().imprimirTablero();
            break;
        }

        for (int i = 0 ; i < actual-> getNumHijos() ; ++i){
            cola.push(actual -> getHijo(i));
        }
    }

    actual -> getTablero().imprimirTablero();
    cout << actual -> getValor() << endl;
}

void DFS(Nodo*raiz){
    cout<< raiz -> getValor() << endl;
    raiz -> getTablero().imprimirTablero();
    
    if(raiz -> getNumHijos() == 0){
        return;
    } 
    DFS(raiz -> getHijo(0));
}

int main()
{
    Tablero* tab = new Tablero();
    Nodo* raiz = new Nodo(*tab, 0, -1);
    
    raiz = crearHijos(raiz, 1);
    DFS(raiz);

    return 0;
}