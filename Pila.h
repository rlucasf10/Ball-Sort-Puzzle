/**
 * @file Pila.h
 * @brief TAD Pila para el juego Ball Sort Puzzle
 * @author Ricardo Lucas Fernández
 * @date Mayo 2025
 *
 * Este archivo define el Tipo Abstracto de Datos (TAD) Pila, que representa
 * los tubos individuales en el juego Ball Sort Puzzle. Cada pila puede contener
 * hasta 4 bolas (caracteres que representan colores) y proporciona operaciones
 * básicas como apilar, desapilar, consultar la cima, verificar si está vacía o llena,
 * y comprobar si la pila está completa (todas las bolas del mismo color).
 *
 * La implementación utiliza un array estático para almacenar los elementos y
 * un índice para controlar la posición de la cima de la pila.
 */

#ifndef PILA_H
#define PILA_H

#include <iostream>

/**
 * @brief TAD Pila para representar un tubo en el juego Ball Sort Puzzle
 *
 * La pila representa un tubo que puede contener bolas de diferentes colores.
 * Se implementa con un array de caracteres donde cada carácter representa un color.
 */
class Pila
{
private:
    static const int CAPACIDAD_MAXIMA = 4; // Capacidad máxima de cada tubo
    char elementos[CAPACIDAD_MAXIMA];      // Array para almacenar los colores
    int cima;                              // Índice del elemento en la cima de la pila (-1 si está vacía)

public:
    /**
     * @brief Constructor por defecto
     * @pre No hay precondiciones
     * @post Crea una pila vacía
     * @complexity O(1)
     */
    Pila();

    /**
     * @brief Comprueba si la pila está vacía
     * @pre No hay precondiciones
     * @post Devuelve true si la pila está vacía, false en caso contrario
     * @return bool - true si la pila está vacía
     * @complexity O(1)
     */
    bool estaVacia() const;

    /**
     * @brief Comprueba si la pila está llena
     * @pre No hay precondiciones
     * @post Devuelve true si la pila está llena, false en caso contrario
     * @return bool - true si la pila está llena
     * @complexity O(1)
     */
    bool estaLlena() const;

    /**
     * @brief Añade un elemento a la cima de la pila
     * @pre La pila no está llena
     * @post Se añade el elemento a la cima de la pila
     * @param elemento - El elemento (color) a añadir
     * @complexity O(1)
     */
    void apilar(char elemento);

    /**
     * @brief Elimina el elemento en la cima de la pila
     * @pre La pila no está vacía
     * @post Se elimina el elemento de la cima de la pila
     * @complexity O(1)
     */
    void desapilar();

    /**
     * @brief Devuelve el elemento en la cima de la pila
     * @pre La pila no está vacía
     * @post Devuelve el elemento en la cima de la pila
     * @return char - El elemento en la cima
     * @complexity O(1)
     */
    char cimaPila() const;

    /**
     * @brief Devuelve el número de elementos en la pila
     * @pre No hay precondiciones
     * @post Devuelve el número de elementos en la pila
     * @return int - Número de elementos
     * @complexity O(1)
     */
    int numElementos() const;

    /**
     * @brief Comprueba si la pila está completa con un solo color
     * @pre No hay precondiciones
     * @post Devuelve true si la pila está completa con un solo color
     * @return bool - true si la pila contiene CAPACIDAD_MAXIMA elementos del mismo color
     * @complexity O(n) donde n es la cantidad de elementos en la pila
     */
    bool estaCompleta() const;

    /**
     * @brief Obtiene el elemento en una posición específica de la pila
     * @pre 0 <= posicion < numElementos()
     * @post Devuelve el elemento en la posición especificada
     * @param posicion - La posición del elemento (0 es el fondo de la pila)
     * @return char - El elemento en la posición
     * @complexity O(1)
     */
    char getElemento(int posicion) const;
};

#endif // PILA_H