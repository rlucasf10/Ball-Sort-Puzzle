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

    std::string linea;

    // Ignorar comentarios y líneas vacías
    while (std::getline(archivo, linea))
    {
        // Eliminar espacios en blanco al inicio y final
        linea.erase(0, linea.find_first_not_of(" \t"));
        if (linea.empty())
            continue;

        // Ignorar líneas que comienzan con // o /* o *
        if (linea.substr(0, 2) == "//" || linea.substr(0, 2) == "/*" || linea[0] == '*')
        {
            continue;
        }

        // Encontramos una línea que no es comentario
        break;
    }

    // La primera línea no comentada debe contener el número de pilas
    int numPilas = 0;
    try
    {
        numPilas = std::stoi(linea);
    }
    catch (const std::exception &e)
    {
        archivo.close();
        return false;
    }

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
        // Leer la siguiente línea no comentada
        while (std::getline(archivo, linea))
        {
            // Eliminar espacios en blanco al inicio y final
            linea.erase(0, linea.find_first_not_of(" \t"));
            if (linea.empty())
                continue;

            // Ignorar líneas de comentarios
            if (linea.substr(0, 2) == "//" || linea.substr(0, 2) == "/*" || linea[0] == '*')
            {
                continue;
            }

            // Encontramos una línea que no es comentario
            break;
        }

        if (linea.length() < 4)
        {
            archivo.close();
            return false;
        }

        // Colocar las bolas en la pila (desde el fondo hacia la cima)
        for (int j = 0; j < 4; j++)
        {
            char color = linea[j];
            if (!tablero.colocarBola(i, color))
            {
                archivo.close();
                return false;
            }
        }
    }

    archivo.close();
    return true;
}