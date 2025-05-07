/**
 * @file PilaPruebas.cpp
 * @brief Pruebas para el TAD Pila del juego Ball Sort Puzzle
 * @author Ricardo Lucas Fernández
 * @date Mayo 2025
 *
 * Este archivo contiene un conjunto completo de pruebas unitarias para verificar
 * el correcto funcionamiento del TAD Pila (Pila.h/Pila.cpp). Las pruebas cubren
 * todas las operaciones básicas de la pila, como apilar, desapilar, consultar la
 * cima, verificar si está vacía o llena, y comprobar si la pila está completa
 * con un solo color.
 *
 * Cada prueba utiliza assert para verificar que el comportamiento sea correcto,
 * y muestra mensajes informativos sobre el progreso de las pruebas en la consola.
 */

#include "Pila.h"
#include <iostream>
#include <cassert>

// Incluir la implementación directamente para evitar errores de "undefined reference"
#include "Pila.cpp"

/**
 * @brief Ejecuta las pruebas del TAD Pila
 * @return int - 0 si todas las pruebas pasan correctamente
 */
int main()
{
    std::cout << "Iniciando pruebas del TAD Pila..." << std::endl;

    // Prueba 1: Crear una pila vacía
    Pila pila;
    assert(pila.estaVacia());
    assert(!pila.estaLlena());
    assert(pila.numElementos() == 0);
    std::cout << "Prueba 1 superada: Constructor y estado inicial" << std::endl;

    // Prueba 2: Apilar elementos
    pila.apilar('R'); // Rojo
    assert(!pila.estaVacia());
    assert(!pila.estaLlena());
    assert(pila.numElementos() == 1);
    assert(pila.cimaPila() == 'R');

    pila.apilar('G'); // Verde
    assert(pila.numElementos() == 2);
    assert(pila.cimaPila() == 'G');
    std::cout << "Prueba 2 superada: Apilar elementos" << std::endl;

    // Prueba 3: Desapilar elementos
    pila.desapilar();
    assert(pila.numElementos() == 1);
    assert(pila.cimaPila() == 'R');

    pila.desapilar();
    assert(pila.estaVacia());
    assert(pila.numElementos() == 0);
    std::cout << "Prueba 3 superada: Desapilar elementos" << std::endl;

    // Prueba 4: Llenar la pila
    pila.apilar('R');
    pila.apilar('G');
    pila.apilar('B');
    pila.apilar('Y');
    assert(pila.estaLlena());
    assert(pila.numElementos() == 4);
    assert(pila.cimaPila() == 'Y');
    std::cout << "Prueba 4 superada: Llenar la pila" << std::endl;

    // Prueba 5: Intentar apilar en una pila llena
    pila.apilar('P'); // No debería tener efecto
    assert(pila.numElementos() == 4);
    assert(pila.cimaPila() == 'Y');
    std::cout << "Prueba 5 superada: Intentar apilar en una pila llena" << std::endl;

    // Prueba 6: Comprobar getElemento
    assert(pila.getElemento(0) == 'R');
    assert(pila.getElemento(1) == 'G');
    assert(pila.getElemento(2) == 'B');
    assert(pila.getElemento(3) == 'Y');
    std::cout << "Prueba 6 superada: getElemento" << std::endl;

    // Prueba 7: Comprobar pila completa (del mismo color)
    assert(!pila.estaCompleta()); // No está completa porque tiene colores diferentes

    // Vaciar la pila
    pila.desapilar();
    pila.desapilar();
    pila.desapilar();
    pila.desapilar();
    assert(pila.estaVacia());

    // Crear una pila con un solo color
    pila.apilar('R');
    pila.apilar('R');
    pila.apilar('R');
    pila.apilar('R');
    assert(pila.estaCompleta()); // Ahora está completa con un solo color
    std::cout << "Prueba 7 superada: Comprobar pila completa" << std::endl;

    std::cout << "¡Todas las pruebas del TAD Pila han sido superadas!" << std::endl;
    return 0;
}