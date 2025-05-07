/**
 * @file BallSortPuzzle.cpp
 * @brief Programa principal para el juego Ball Sort Puzzle
 * @author Ricardo Lucas Fernández
 * @date Mayo 2025
 *
 * Este archivo contiene el programa principal (función main) del juego Ball Sort Puzzle.
 * Se encarga de la interfaz de usuario en consola, mostrando el estado del tablero con
 * colores, procesando la entrada del usuario para realizar movimientos, y controlando
 * el flujo general del juego.
 *
 * El programa intenta cargar la configuración del juego desde un archivo llamado
 * ballSort.cnf, buscándolo en varias ubicaciones posibles. Una vez cargado, permite
 * al usuario jugar moviendo bolas entre tubos según las reglas del juego, hasta que
 * se complete el puzzle o el usuario decida salir.
 */

#include "Juego.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

// Incluir las implementaciones directamente para evitar errores de "undefined reference"
#include "Pila.cpp"
#include "Tablero.cpp"
#include "Juego.cpp"

// Definiciones para los colores en la consola (para Windows)
#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_WHITE "\033[37m"

/**
 * @brief Muestra el estado actual del tablero en la consola
 * @param juego - Referencia al objeto Juego
 */
void mostrarTablero(const Juego &juego)
{
    const Tablero &tablero = juego.getTablero();
    int numPilas = tablero.getNumPilas();

    std::cout << "\n+----------------------------+" << std::endl;

    // Mostrar números de tubo en la parte superior
    std::cout << "| ";
    for (int i = 0; i < numPilas; i++)
    {
        std::cout << " " << i + 1 << "  ";
    }
    std::cout << " |" << std::endl;

    // Mostrar contenido de los tubos
    for (int fila = 3; fila >= 0; fila--)
    {
        std::cout << "| ";

        for (int pila = 0; pila < numPilas; pila++)
        {
            const Pila &p = tablero.getPila(pila);

            if (p.numElementos() > fila)
            {
                char color = p.getElemento(fila);

                // Asignar color según el carácter
                switch (color)
                {
                case 'R':
                    std::cout << COLOR_RED;
                    break;
                case 'G':
                    std::cout << COLOR_GREEN;
                    break;
                case 'B':
                    std::cout << COLOR_BLUE;
                    break;
                case 'Y':
                    std::cout << COLOR_YELLOW;
                    break;
                case 'M':
                    std::cout << COLOR_MAGENTA;
                    break;
                case 'C':
                    std::cout << COLOR_CYAN;
                    break;
                default:
                    break;
                }

                std::cout << " " << color << " " << COLOR_RESET;
            }
            else
            {
                std::cout << " . ";
            }

            std::cout << " ";
        }

        std::cout << " |" << std::endl;
    }

    // Mostrar base de los tubos
    std::cout << "| ";
    for (int i = 0; i < numPilas; i++)
    {
        std::cout << "=== ";
    }
    std::cout << " |" << std::endl;

    std::cout << "+----------------------------+" << std::endl;
    std::cout << "Movimientos: " << juego.getNumMovimientos() << std::endl;
}

/**
 * @brief Muestra las instrucciones del juego
 */
void mostrarInstrucciones()
{
    std::cout << "\n============= BALL SORT PUZZLE =============\n"
              << std::endl;
    std::cout << "El objetivo del juego es ordenar las bolas de colores" << std::endl;
    std::cout << "para que cada tubo contenga bolas de un solo color." << std::endl;
    std::cout << "\nInstrucciones:" << std::endl;
    std::cout << "- Ingresa el número del tubo origen y destino (1-N)" << std::endl;
    std::cout << "- Solo puedes mover bolas si son del mismo color que la cima del tubo destino" << std::endl;
    std::cout << "  o si el tubo destino está vacío" << std::endl;
    std::cout << "- Para salir del juego, pulsa 'q'" << std::endl;
    std::cout << "\n===========================================\n"
              << std::endl;
}

/**
 * @brief Muestra un mensaje de fin de juego
 * @param victoria - true si el juego terminó con victoria
 * @param numMovimientos - Número de movimientos realizados
 */
void mostrarFinJuego(bool victoria, int numMovimientos)
{
    if (victoria)
    {
        std::cout << "\n¡FELICIDADES! Has completado el puzzle en " << numMovimientos << " movimientos." << std::endl;
    }
    else
    {
        std::cout << "\nJuego terminado. Gracias por jugar." << std::endl;
    }
}

/**
 * @brief Función principal
 * @return int - Estado de salida del programa
 */
int main()
{
    // Lista de ubicaciones donde buscar el archivo de configuración
    const int NUM_RUTAS = 1;
    std::string rutasPosibles[NUM_RUTAS] = {
        "ballSort.cnf" // Solo la ruta correcta en la ubicación actual
    };

    bool configuracionCargada = false;
    Juego juego;

    // Intentar cargar el archivo desde cada posible ubicación
    for (int i = 0; i < NUM_RUTAS; i++)
    {
        const std::string &ruta = rutasPosibles[i];
        std::cout << "Intentando cargar configuración desde: " << ruta << std::endl;

        // Verificar si el archivo existe antes de intentar cargarlo
        std::ifstream verificarArchivo(ruta);
        if (verificarArchivo.good())
        {
            std::cout << "El archivo existe en la ruta: " << ruta << std::endl;
            verificarArchivo.close();
        }
        else
        {
            std::cout << "El archivo NO existe en la ruta: " << ruta << std::endl;
            continue; // Intentar la siguiente ruta
        }

        if (juego.inicializar(ruta))
        {
            std::cout << "Configuración cargada correctamente desde: " << ruta << std::endl;
            configuracionCargada = true;
            break;
        }
        else
        {
            std::cout << "El archivo existe pero no se pudo cargar la configuración." << std::endl;
        }
    }

    // Verificar si se pudo cargar la configuración
    if (!configuracionCargada)
    {
        std::cerr << "Error: No se pudo cargar la configuración del juego." << std::endl;
        std::cerr << "Por favor, asegúrate de que el archivo ballSort.cnf existe en alguna de estas ubicaciones:" << std::endl;
        for (int i = 0; i < NUM_RUTAS; i++)
        {
            std::cerr << " - " << rutasPosibles[i] << std::endl;
        }
        std::cerr << "Presiona Enter para salir...";
        std::cin.get();
        return 1;
    }

    // Mostrar instrucciones
    mostrarInstrucciones();

    // Bucle principal del juego
    while (juego.estaEnCurso())
    {
        // Mostrar el estado actual del tablero
        mostrarTablero(juego);

        // Solicitar movimiento
        std::cout << "Ingresa tubo origen y destino (o 'q' para salir): ";
        std::string entrada;
        std::cin >> entrada;

        // Comprobar si el usuario quiere salir
        if (entrada == "q" || entrada == "Q")
        {
            juego.terminarJuego();
            mostrarFinJuego(false, juego.getNumMovimientos());
            break;
        }

        // Procesar movimiento
        int origen, destino;

        try
        {
            origen = std::stoi(entrada) - 1; // Restar 1 para convertir a índice base 0

            std::cin >> entrada;
            if (entrada == "q" || entrada == "Q")
            {
                juego.terminarJuego();
                mostrarFinJuego(false, juego.getNumMovimientos());
                break;
            }

            destino = std::stoi(entrada) - 1; // Restar 1 para convertir a índice base 0

            if (!juego.realizarMovimiento(origen, destino))
            {
                std::cout << "Movimiento no válido. Inténtalo de nuevo." << std::endl;
            }
        }
        catch (const std::invalid_argument &)
        {
            std::cout << "Entrada no válida. Ingresa números o 'q' para salir." << std::endl;
        }

        // Comprobar si el juego ha terminado
        if (juego.juegoTerminado())
        {
            mostrarTablero(juego);
            mostrarFinJuego(true, juego.getNumMovimientos());
            break;
        }
    }

    return 0;
}