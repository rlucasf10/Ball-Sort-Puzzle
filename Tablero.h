/**
 * @file Tablero.h
 * @brief TAD Tablero para el juego Ball Sort Puzzle
 * @author Ricardo Lucas Fernández
 * @date Mayo 2025
 *
 * Este archivo define el Tipo Abstracto de Datos (TAD) Tablero, que representa
 * el estado completo del juego Ball Sort Puzzle. El tablero contiene un conjunto
 * de pilas (tubos) y gestiona las operaciones para mover bolas entre ellas,
 * verificar movimientos válidos y determinar cuándo se ha completado el juego.
 *
 * El tablero se implementa como un array de objetos Pila, con un límite máximo
 * de 10 pilas por juego. Proporciona métodos para inicializar el tablero, colocar
 * bolas, realizar movimientos y verificar el estado del juego.
 */

#ifndef TABLERO_H
#define TABLERO_H

#include "Pila.h"

/**
 * @brief TAD Tablero para representar el estado del juego Ball Sort Puzzle
 *
 * El tablero consta de un conjunto de pilas (tubos) que contienen bolas de colores.
 * El objetivo es ordenar las bolas para que cada tubo tenga bolas de un solo color.
 */
class Tablero
{
private:
    static const int MAX_PILAS = 10; // Número máximo de pilas (tubos) en el tablero
    Pila pilas[MAX_PILAS];           // Array de pilas
    int numPilas;                    // Número actual de pilas en el tablero

public:
    /**
     * @brief Constructor por defecto
     * @pre No hay precondiciones
     * @post Crea un tablero vacío
     * @complexity O(1)
     */
    Tablero();

    /**
     * @brief Inicializa el tablero con un número dado de pilas
     * @pre 2 <= numPilas <= MAX_PILAS
     * @post El tablero se inicializa con el número especificado de pilas
     * @param numPilasIniciales - Número de pilas a inicializar
     * @complexity O(1)
     */
    void inicializar(int numPilasIniciales);

    /**
     * @brief Coloca una bola en una pila específica
     * @pre 0 <= indicePila < numPilas y la pila no está llena
     * @post Se añade una bola del color especificado a la pila indicada
     * @param indicePila - Índice de la pila donde colocar la bola
     * @param color - Color de la bola a colocar
     * @return bool - true si se pudo colocar la bola, false en caso contrario
     * @complexity O(1)
     */
    bool colocarBola(int indicePila, char color);

    /**
     * @brief Realiza un movimiento entre dos pilas
     * @pre 0 <= origen < numPilas y 0 <= destino < numPilas
     * @post Mueve la bola de la cima de la pila origen a la pila destino si es válido
     * @param origen - Índice de la pila origen
     * @param destino - Índice de la pila destino
     * @return bool - true si el movimiento se realizó correctamente
     * @complexity O(1)
     */
    bool moverBola(int origen, int destino);

    /**
     * @brief Comprueba si un movimiento es válido
     * @pre 0 <= origen < numPilas y 0 <= destino < numPilas
     * @post Determina si se puede mover una bola de la pila origen a la pila destino
     * @param origen - Índice de la pila origen
     * @param destino - Índice de la pila destino
     * @return bool - true si el movimiento es válido
     * @complexity O(1)
     */
    bool movimientoValido(int origen, int destino) const;

    /**
     * @brief Comprueba si el juego ha terminado (todas las pilas están completas o vacías)
     * @pre No hay precondiciones
     * @post Determina si el juego ha terminado
     * @return bool - true si el juego ha terminado
     * @complexity O(n) donde n es el número de pilas
     */
    bool juegoTerminado() const;

    /**
     * @brief Obtiene el número de pilas en el tablero
     * @pre No hay precondiciones
     * @post Devuelve el número de pilas en el tablero
     * @return int - El número de pilas
     * @complexity O(1)
     */
    int getNumPilas() const;

    /**
     * @brief Obtiene una referencia constante a una pila específica
     * @pre 0 <= indicePila < numPilas
     * @post Devuelve una referencia constante a la pila especificada
     * @param indicePila - Índice de la pila a obtener
     * @return const Pila & - Referencia constante a la pila
     * @complexity O(1)
     */
    const Pila &getPila(int indicePila) const;
};

#endif // TABLERO_H