/**
 * @file Juego.cpp
 * @brief Implementación del TAD Juego para el juego Ball Sort Puzzle
 * @author Ricardo Lucas Fernández
 * @date Mayo 2025
 *
 * Este archivo implementa las operaciones definidas en el TAD Juego (Juego.h).
 * Proporciona la implementación de la lógica de alto nivel del juego, incluyendo
 * la carga de configuración desde un archivo, la gestión del flujo de juego,
 * y la determinación del estado del juego (en curso, terminado).
 *
 * Es el componente principal que coordina todos los elementos del juego y sirve
 * como interfaz entre la lógica del juego y la interfaz de usuario.
 */

#include "Juego.h"

/**
 * Constructor por defecto
 * @complexity O(1)
 */
Juego::Juego()
{
    numMovimientos = 0;
    juegoEnCurso = false;
}

/**
 * Inicializa el juego cargando la configuración
 * @param nombreArchivo - Nombre del archivo de configuración
 * @return bool - true si la inicialización fue exitosa
 * @complexity O(n) donde n es el número de líneas en el archivo
 */
bool Juego::inicializar(const std::string &nombreArchivo)
{
    numMovimientos = 0;
    if (cargarConfiguracion(nombreArchivo))
    {
        juegoEnCurso = true;
        return true;
    }
    juegoEnCurso = false;
    return false;
}

/**
 * Realiza un movimiento en el juego
 * @param origen - Índice de la pila origen
 * @param destino - Índice de la pila destino
 * @return bool - true si el movimiento fue exitoso
 * @complexity O(1)
 */
bool Juego::realizarMovimiento(int origen, int destino)
{
    if (!juegoEnCurso)
    {
        return false;
    }

    if (tablero.moverBola(origen, destino))
    {
        numMovimientos++;

        // Verificar si el juego ha terminado después del movimiento
        if (tablero.juegoTerminado())
        {
            juegoEnCurso = false;
        }

        return true;
    }

    return false;
}

/**
 * Comprueba si el juego ha terminado
 * @return bool - true si el juego ha terminado
 * @complexity O(n) donde n es el número de pilas
 */
bool Juego::juegoTerminado() const
{
    return !juegoEnCurso || tablero.juegoTerminado();
}

/**
 * Termina el juego
 * @complexity O(1)
 */
void Juego::terminarJuego()
{
    juegoEnCurso = false;
}

/**
 * Comprueba si el juego está en curso
 * @return bool - true si el juego está en curso
 * @complexity O(1)
 */
bool Juego::estaEnCurso() const
{
    return juegoEnCurso;
}

/**
 * Obtiene el número de movimientos realizados
 * @return int - El número de movimientos
 * @complexity O(1)
 */
int Juego::getNumMovimientos() const
{
    return numMovimientos;
}

/**
 * Obtiene una referencia constante al tablero
 * @return const Tablero& - Referencia constante al tablero
 * @complexity O(1)
 */
const Tablero &Juego::getTablero() const
{
    return tablero;
}

/**
 * Carga la configuración desde un archivo
 * @param nombreArchivo - Nombre del archivo de configuración
 * @return bool - true si la carga fue exitosa
 * @complexity O(n) donde n es el número de líneas en el archivo
 */
bool Juego::cargarConfiguracion(const std::string &nombreArchivo)
{
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open())
    {
        return false;
    }

    int numPilas = 0;
    archivo >> numPilas;

    // Verificar que el número de pilas sea válido
    if (numPilas < 2 || numPilas > 10)
    {
        archivo.close();
        return false;
    }

    // Inicializar el tablero
    tablero.inicializar(numPilas);

    // Leer la configuración de cada pila
    for (int i = 0; i < numPilas - 2; i++)
    { // Las dos últimas pilas siempre están vacías
        for (int j = 0; j < 4; j++)
        { // Cada pila tiene 4 bolas
            char color;
            archivo >> color;

            if (!archivo.good())
            {
                archivo.close();
                return false;
            }

            // Colocar la bola en la pila (desde el fondo hacia la cima)
            tablero.colocarBola(i, color);
        }
    }

    archivo.close();
    return true;
}