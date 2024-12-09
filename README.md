# Juego de Tic-Tac-Toe con Minimax y Poda Alfa-Beta
Integrantes: 
* Ferran Rojas Andreu, 21.642.668-1, ferran.rojas@alumnos.ucn.cl, Paralelo C2
* Maximiliano Alberto Urrutia Araya, 21.573.565-6, maximiliano.urrutia@alumnos.ucn.cl, Paralelo C1

Este proyecto implementa el algoritmo **Minimax** con optimización mediante **poda alfa-beta** para jugar Tic-Tac-Toe (tres en línea). El objetivo es demostrar cómo un agente inteligente puede tomar decisiones óptimas en un juego clásico de tablero.

## Características del Proyecto

- Juego de Tic-Tac-Toe jugable en consola.
- Algoritmo Minimax para la toma de decisiones de la IA.
- Optimización del algoritmo mediante poda alfa-beta para mejorar el rendimiento.
- Interfaz simple para jugar contra la inteligencia artificial.

## Requisitos

### Herramientas necesarias
- **Lenguaje:** C++
- **Entorno de desarrollo:** Visual Studio Code, IntelliJ IDEA, o cualquier editor compatible.
- **Control de versiones:** Git/GitHub.

## Instrucciones de Uso
1. **Abra la terminal dentro de la carpeta de este repositorio**

2. **Linea de compilacion**
   ```bash
    g++ -g -o main .\Tablero.cpp .\Nodo.cpp .\Pedro.cpp .\Gato.cpp
   ```
3. **Ejecute el programa**
    ```
      .\main.exe
    ```
## Estructura del Código
- **Gato.cpp**: Control del flujo del juego y turnos de jugadores (humano e IA).
- **Pedro.cpp**: Implementación del algoritmo Minimax con poda alfa-beta.
- **Tablero.cpp**: Representación y manipulación del tablero.
- **Juez.cpp**: Verificación de condiciones de victoria o empate.
- **Nodo.cpp**: Gestión de nodos del árbol de juego.
## Ejemplo del Árbol de Juego
Diagrama de un árbol de juego para las primeras 3 jugadas:
```yaml
                                        0  |  0  |  0
                                        0  |  0  |  0
                                        0  |  0  |  0
                                     Turno de Min (Humano)
               ------------------------------------------------------------------
              /    /         |           |      |            |         \          \

                       X  |  0  |  0                    0  |  X  |  0
                       0  |  0  |  0                    0  |  0  |  0
                       0  |  0  |  0                    0  |  0  |  0
                                  Turno de Max (Pedro/IA)
     -----------------------------                     -----------------------------------           
    |        | | | | | | |        |                    |           | | | | | | |          |
 X  |  O  |  0             X  |  0  |  O            O  |  X  |  0                   0  |  X  |  O 
 0  |  0  |  0             0  |  0  |  0            0  |  0  |  0                   0  |  0  |  0 
 0  |  0  |  0             0  |  0  |  0            0  |  0  |  0                   0  |  0  |  0
      |                          |                        |                               |
--------------             --------------          ----------------                 --------------
/ / / /|\ \ \ \            / / / /|\ \ \ \         / / / /|\ \ \ \                  / / / /|\ \ \ \
```
## Leyenda:
- **Tablero Inicial** es el estado del juego al comienzo.
- Los niveles alternan entre **jugadores Max** (X) y **jugadores Min** (O).
- Las evaluaciones numéricas indican qué tan favorable es un tablero para el jugador actual.
- La poda ocurre donde se marca con "P", indicando que esa rama no se evalúa debido a la poda alfa-beta.

## Detalles:
- Cada movimiento de X o O genera un nuevo estado del tablero.
- Se evalúan tableros completos para calcular las evaluaciones.
- La poda reduce el número de nodos analizados, optimizando el tiempo de cómputo.

Nota: Para representar un árbol completo, este se expandiría en más niveles hasta alcanzar las hojas (estados finales del juego). La cantidad de nodos podados depende de la heurística y el orden en que se generan los movimientos.

## Complejidad Temporal
Implementación:
- Complejidad Temporal Minimax (sin poda)	``` O(b^d) ```
- Minimax con poda alfa-beta cuando los nodos estan ordenados de menor a mayor (o vice versa) ``` O(b^(d/2)) ```
- b: Número de ramas posibles por nodo.
- d: Profundidad del árbol.
