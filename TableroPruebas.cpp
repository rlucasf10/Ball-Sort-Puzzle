/**
 * @file TableroPruebas.cpp
 * @brief Pruebas para el TAD Tablero del juego Ball Sort Puzzle
 * @author Ricardo Lucas Fernández
 * @date Mayo 2025
 *
 * Este archivo contiene un conjunto completo de pruebas unitarias para verificar
 * el correcto funcionamiento del TAD Tablero (Tablero.h/Tablero.cpp). Las pruebas
 * comprueban la inicialización del tablero, la colocación de bolas en las pilas,
 * la validación y ejecución de movimientos entre pilas, y la detección de cuando
 * el juego ha terminado.
 *
 * Cada prueba utiliza assert para verificar que el comportamiento sea correcto,
 * y muestra mensajes informativos sobre el progreso de las pruebas en la consola.
 */

#include "Tablero.h"
#include <iostream>
#include <cassert>

// Incluir las implementaciones directamente para evitar errores de "undefined reference"
#include "Pila.cpp"
#include "Tablero.cpp"

/**
 * @brief Ejecuta las pruebas del TAD Tablero
 * @return int - 0 si todas las pruebas pasan correctamente
 */
int main()
{
    std::cout << "Iniciando pruebas del TAD Tablero..." << std::endl;

    // Prueba 1: Crear un tablero vacío
    Tablero tablero;
    assert(tablero.getNumPilas() == 0);
    std::cout << "Prueba 1 superada: Constructor y estado inicial" << std::endl;

    // Prueba 2: Inicializar el tablero
    tablero.inicializar(5); // 5 pilas
    assert(tablero.getNumPilas() == 5);
    std::cout << "Prueba 2 superada: Inicializar tablero" << std::endl;

    // Prueba 3: Colocar bolas en las pilas
    assert(tablero.colocarBola(0, 'R')); // Pila 0, color rojo
    assert(tablero.colocarBola(0, 'G')); // Pila 0, color verde
    assert(tablero.colocarBola(1, 'B')); // Pila 1, color azul
    assert(tablero.colocarBola(1, 'Y')); // Pila 1, color amarillo

    // Verificar las bolas colocadas
    assert(tablero.getPila(0).numElementos() == 2);
    assert(tablero.getPila(1).numElementos() == 2);
    assert(tablero.getPila(0).getElemento(0) == 'R');
    assert(tablero.getPila(0).getElemento(1) == 'G');
    assert(tablero.getPila(1).getElemento(0) == 'B');
    assert(tablero.getPila(1).getElemento(1) == 'Y');
    std::cout << "Prueba 3 superada: Colocar bolas" << std::endl;

    // Prueba 4: Comprobar movimientos válidos
    assert(tablero.movimientoValido(0, 2));  // De pila 0 a pila 2 (vacía)
    assert(!tablero.movimientoValido(2, 0)); // De pila 2 a pila 0 (vacía a no vacía)
    assert(!tablero.movimientoValido(0, 1)); // De pila 0 a pila 1 (colores diferentes)
    std::cout << "Prueba 4 superada: Comprobar movimientos válidos" << std::endl;

    // Prueba 5: Realizar movimientos
    assert(tablero.moverBola(0, 2)); // Mover G de pila 0 a pila 2
    assert(tablero.getPila(0).numElementos() == 1);
    assert(tablero.getPila(2).numElementos() == 1);
    assert(tablero.getPila(0).cimaPila() == 'R');
    assert(tablero.getPila(2).cimaPila() == 'G');

    assert(tablero.moverBola(0, 3)); // Mover R de pila 0 a pila 3
    assert(tablero.getPila(0).estaVacia());
    assert(tablero.getPila(3).cimaPila() == 'R');
    std::cout << "Prueba 5 superada: Realizar movimientos" << std::endl;

    // Prueba 6: Comprobar juego terminado
    assert(!tablero.juegoTerminado()); // El juego no ha terminado aún

    // Vaciar todas las pilas excepto una
    tablero.moverBola(1, 0); // Y de pila 1 a pila 0
    tablero.moverBola(1, 4); // B de pila 1 a pila 4
    tablero.moverBola(2, 1); // G de pila 2 a pila 1
    tablero.moverBola(3, 2); // R de pila 3 a pila 2

    // Llenar una pila con el mismo color
    Tablero tableroCompleto;
    tableroCompleto.inicializar(3);
    for (int i = 0; i < 4; i++)
    {
        tableroCompleto.colocarBola(0, 'R');
    }

    // Las demás pilas están vacías, por lo que el juego debe estar terminado
    assert(tableroCompleto.juegoTerminado());
    std::cout << "Prueba 6 superada: Comprobar juego terminado" << std::endl;

    std::cout << "¡Todas las pruebas del TAD Tablero han sido superadas!" << std::endl;
    return 0;
}