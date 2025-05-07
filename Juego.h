/**
 * @file Juego.h
 * @brief TAD Juego para el juego Ball Sort Puzzle
 * @author Ricardo Lucas Fernández
 * @date Mayo 2025
 *
 * Este archivo define el Tipo Abstracto de Datos (TAD) Juego, que representa
 * la lógica principal del juego Ball Sort Puzzle. El TAD Juego encapsula
 * un objeto Tablero y añade la lógica para gestionar el flujo del juego,
 * cargar la configuración desde un archivo, realizar movimientos y determinar
 * cuándo ha terminado el juego.
 *
 * Es el componente de nivel más alto en la arquitectura del juego y sirve
 * como punto de entrada para la interfaz de usuario.
 */

#ifndef JUEGO_H
#define JUEGO_H

#include "Tablero.h"
#include <fstream>
#include <string>

/**
 * @brief TAD Juego para gestionar la lógica del juego Ball Sort Puzzle
 *
 * Este TAD se encarga de la inicialización del juego, la gestión de movimientos
 * y la interacción con el archivo de configuración.
 */
class Juego
{
private:
    Tablero tablero;    // Tablero del juego
    int numMovimientos; // Contador de movimientos realizados
    bool juegoEnCurso;  // Indica si el juego está en curso

    /**
     * @brief Carga la configuración desde un archivo
     * @pre No hay precondiciones
     * @post Carga la configuración del juego desde el archivo especificado
     * @param nombreArchivo - Nombre del archivo de configuración
     * @return bool - true si la carga fue exitosa
     * @complexity O(n) donde n es el número de líneas en el archivo
     */
    bool cargarConfiguracion(const std::string &nombreArchivo);

public:
    /**
     * @brief Constructor por defecto
     * @pre No hay precondiciones
     * @post Crea un juego sin inicializar
     * @complexity O(1)
     */
    Juego();

    /**
     * @brief Inicializa el juego cargando la configuración
     * @pre No hay precondiciones
     * @post Inicializa el juego cargando la configuración desde el archivo especificado
     * @param nombreArchivo - Nombre del archivo de configuración
     * @return bool - true si la inicialización fue exitosa
     * @complexity O(n) donde n es el número de líneas en el archivo
     */
    bool inicializar(const std::string &nombreArchivo);

    /**
     * @brief Realiza un movimiento en el juego
     * @pre El juego está en curso
     * @post Realiza un movimiento desde la pila origen a la pila destino si es válido
     * @param origen - Índice de la pila origen
     * @param destino - Índice de la pila destino
     * @return bool - true si el movimiento fue exitoso
     * @complexity O(1)
     */
    bool realizarMovimiento(int origen, int destino);

    /**
     * @brief Comprueba si el juego ha terminado
     * @pre No hay precondiciones
     * @post Determina si el juego ha terminado
     * @return bool - true si el juego ha terminado
     * @complexity O(n) donde n es el número de pilas
     */
    bool juegoTerminado() const;

    /**
     * @brief Termina el juego (por ejemplo, cuando el usuario pulsa Escape)
     * @pre No hay precondiciones
     * @post Marca el juego como terminado
     * @complexity O(1)
     */
    void terminarJuego();

    /**
     * @brief Comprueba si el juego está en curso
     * @pre No hay precondiciones
     * @post Determina si el juego está en curso
     * @return bool - true si el juego está en curso
     * @complexity O(1)
     */
    bool estaEnCurso() const;

    /**
     * @brief Obtiene el número de movimientos realizados
     * @pre No hay precondiciones
     * @post Devuelve el número de movimientos realizados
     * @return int - El número de movimientos
     * @complexity O(1)
     */
    int getNumMovimientos() const;

    /**
     * @brief Obtiene una referencia constante al tablero
     * @pre No hay precondiciones
     * @post Devuelve una referencia constante al tablero
     * @return const Tablero& - Referencia constante al tablero
     * @complexity O(1)
     */
    const Tablero &getTablero() const;
};

#endif // JUEGO_H