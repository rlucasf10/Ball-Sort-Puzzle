/**
 * @file Tablero.cpp
 * @brief Implementación del TAD Tablero para el juego Ball Sort Puzzle
 * @author Ricardo Lucas Fernández
 * @date Mayo 2025
 *
 * Este archivo implementa las operaciones definidas en el TAD Tablero (Tablero.h).
 * Proporciona la lógica para gestionar el conjunto de pilas (tubos) del juego,
 * permitiendo mover bolas entre ellas, verificar movimientos válidos y determinar
 * cuándo se ha completado el juego (todas las pilas están completas con un solo
 * color o vacías).
 */

#include "Tablero.h"

/**
 * Constructor por defecto
 * @complexity O(1)
 */
Tablero::Tablero()
{
    numPilas = 0;
}

/**
 * Inicializa el tablero con un número dado de pilas
 * @param numPilasIniciales - Número de pilas a inicializar
 * @complexity O(1)
 */
void Tablero::inicializar(int numPilasIniciales)
{
    if (numPilasIniciales >= 2 && numPilasIniciales <= MAX_PILAS)
    {
        numPilas = numPilasIniciales;
    }
}

/**
 * Coloca una bola en una pila específica
 * @param indicePila - Índice de la pila donde colocar la bola
 * @param color - Color de la bola a colocar
 * @return bool - true si se pudo colocar la bola, false en caso contrario
 * @complexity O(1)
 */
bool Tablero::colocarBola(int indicePila, char color)
{
    // Verificar que el índice de la pila sea válido
    if (indicePila >= 0 && indicePila < numPilas)
    {
        // Verificar que la pila no esté llena
        if (!pilas[indicePila].estaLlena())
        {
            pilas[indicePila].apilar(color);
            return true;
        }
    }
    return false;
}

/**
 * Realiza un movimiento entre dos pilas
 * @param origen - Índice de la pila origen
 * @param destino - Índice de la pila destino
 * @return bool - true si el movimiento se realizó correctamente
 * @complexity O(1)
 */
bool Tablero::moverBola(int origen, int destino)
{
    // Verificar que el movimiento sea válido
    if (movimientoValido(origen, destino))
    {
        // Obtener el color de la bola en la cima de la pila origen
        char color = pilas[origen].cimaPila();

        // Desapilar de la pila origen
        pilas[origen].desapilar();

        // Apilar en la pila destino
        pilas[destino].apilar(color);

        return true;
    }
    return false;
}

/**
 * Comprueba si un movimiento es válido
 * @param origen - Índice de la pila origen
 * @param destino - Índice de la pila destino
 * @return bool - true si el movimiento es válido
 * @complexity O(1)
 */
bool Tablero::movimientoValido(int origen, int destino) const
{
    // Verificar que los índices sean válidos
    if (origen < 0 || origen >= numPilas || destino < 0 || destino >= numPilas || origen == destino)
    {
        return false;
    }

    // Verificar que la pila origen no esté vacía
    if (pilas[origen].estaVacia())
    {
        return false;
    }

    // Verificar que la pila destino no esté llena
    if (pilas[destino].estaLlena())
    {
        return false;
    }

    // Verificar que la pila destino esté vacía o tenga el mismo color en la cima
    if (!pilas[destino].estaVacia() && pilas[destino].cimaPila() != pilas[origen].cimaPila())
    {
        return false;
    }

    return true;
}

/**
 * Comprueba si el juego ha terminado (todas las pilas están completas o vacías)
 * @return bool - true si el juego ha terminado
 * @complexity O(n) donde n es el número de pilas
 */
bool Tablero::juegoTerminado() const
{
    for (int i = 0; i < numPilas; i++)
    {
        // Si una pila no está vacía y no está completa, el juego no ha terminado
        if (!pilas[i].estaVacia() && !pilas[i].estaCompleta())
        {
            return false;
        }
    }
    return true;
}

/**
 * Obtiene el número de pilas en el tablero
 * @return int - El número de pilas
 * @complexity O(1)
 */
int Tablero::getNumPilas() const
{
    return numPilas;
}

/**
 * Obtiene una referencia constante a una pila específica
 * @param indicePila - Índice de la pila a obtener
 * @return const Pila& - Referencia constante a la pila
 * @complexity O(1)
 */
const Pila &Tablero::getPila(int indicePila) const
{
    static Pila pilaVacia; // Pila vacía para devolver en caso de error

    if (indicePila >= 0 && indicePila < numPilas)
    {
        return pilas[indicePila];
    }

    // Si el índice es inválido, devolver una pila vacía
    return pilaVacia;
}