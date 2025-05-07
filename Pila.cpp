/**
 * @file Pila.cpp
 * @brief Implementación del TAD Pila para el juego Ball Sort Puzzle
 * @author Ricardo Lucas Fernández
 * @date Mayo 2025
 *
 * Este archivo implementa las operaciones definidas en el TAD Pila (Pila.h).
 * Proporciona la lógica para manejar los tubos en el juego Ball Sort Puzzle,
 * incluyendo todas las operaciones básicas de una pila (apilar, desapilar),
 * así como funcionalidades específicas del juego como verificar si un tubo
 * está completo con bolas del mismo color.
 */

#include "Pila.h"

/**
 * Constructor por defecto
 * @complexity O(1)
 */
Pila::Pila()
{
    cima = -1; // Inicializa la pila como vacía
}

/**
 * Comprueba si la pila está vacía
 * @return bool - true si la pila está vacía
 * @complexity O(1)
 */
bool Pila::estaVacia() const
{
    return cima == -1;
}

/**
 * Comprueba si la pila está llena
 * @return bool - true si la pila está llena
 * @complexity O(1)
 */
bool Pila::estaLlena() const
{
    return cima == CAPACIDAD_MAXIMA - 1;
}

/**
 * Añade un elemento a la cima de la pila
 * @param elemento - El elemento (color) a añadir
 * @complexity O(1)
 */
void Pila::apilar(char elemento)
{
    if (!estaLlena())
    {
        cima++;
        elementos[cima] = elemento;
    }
}

/**
 * Elimina el elemento en la cima de la pila
 * @complexity O(1)
 */
void Pila::desapilar()
{
    if (!estaVacia())
    {
        cima--;
    }
}

/**
 * Devuelve el elemento en la cima de la pila
 * @return char - El elemento en la cima
 * @complexity O(1)
 */
char Pila::cimaPila() const
{
    if (!estaVacia())
    {
        return elementos[cima];
    }
    return ' '; // Devuelve espacio si la pila está vacía
}

/**
 * Devuelve el número de elementos en la pila
 * @return int - Número de elementos
 * @complexity O(1)
 */
int Pila::numElementos() const
{
    return cima + 1;
}

/**
 * Comprueba si la pila está completa con un solo color
 * @return bool - true si la pila contiene CAPACIDAD_MAXIMA elementos del mismo color
 * @complexity O(n) donde n es la cantidad de elementos en la pila
 */
bool Pila::estaCompleta() const
{
    // La pila debe estar llena
    if (!estaLlena())
    {
        return false;
    }

    // Todos los elementos deben ser del mismo color
    char primerColor = elementos[0];
    for (int i = 1; i < CAPACIDAD_MAXIMA; i++)
    {
        if (elementos[i] != primerColor)
        {
            return false;
        }
    }

    return true;
}

/**
 * Obtiene el elemento en una posición específica de la pila
 * @param posicion - La posición del elemento (0 es el fondo de la pila)
 * @return char - El elemento en la posición
 * @complexity O(1)
 */
char Pila::getElemento(int posicion) const
{
    if (posicion >= 0 && posicion <= cima)
    {
        return elementos[posicion];
    }
    return ' '; // Devuelve espacio si la posición es inválida
}