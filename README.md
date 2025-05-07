# 🎮 Ball Sort Puzzle

<div align="center">
  <img src="https://img.shields.io/badge/Ball%20Sort-Puzzle-brightgreen" alt="Ball Sort Puzzle"/>
  <img src="https://img.shields.io/badge/Versión-1.0-blue" alt="Versión"/>
  <img src="https://img.shields.io/badge/Lenguaje-C%2B%2B-orange" alt="C++"/>
  <img src="https://img.shields.io/badge/Plataforma-Windows-lightgrey" alt="Plataforma"/>
  
  <br>
  <h3>Un juego de lógica donde ordenarás bolas de colores en tubos</h3>
</div>

---

## 📋 Índice de Contenidos

- [📝 Descripción](#-descripción)
- [✨ Características](#-características)
- [⚙️ Requisitos del Sistema](#️-requisitos-del-sistema)
- [🚀 Compilación y Ejecución](#-compilación-y-ejecución)
- [🎮 Cómo Jugar](#-cómo-jugar)
- [🧩 Estructura del Proyecto](#-estructura-del-proyecto)
- [🧪 Pruebas](#-pruebas)
- [🛠️ Implementación Técnica](#️-implementación-técnica)
- [📊 Personalización](#-personalización)
- [❓ Preguntas Frecuentes](#-preguntas-frecuentes)

---

## 📝 Descripción

**Ball Sort Puzzle** es una implementación en C++ del popular juego de rompecabezas de lógica, donde el objetivo es ordenar bolas de diferentes colores en tubos, de manera que cada tubo contenga bolas de un único color o quede vacío.

Este proyecto ha sido desarrollado como aplicación práctica de los conceptos de Tipos Abstractos de Datos (TAD), implementando estructuras de datos como pilas para representar los tubos del juego y aplicando principios de diseño orientado a objetos.

<div align="center">
  <p><i>El juego perfecto para entrenar tu cerebro y disfrutar de horas de entretenimiento</i></p>
</div>

---

## ✨ Características

- 🎨 **Interfaz en consola con colores** que hace que el juego sea visualmente atractivo
- 🧠 **Diseño de niveles** mediante archivos de configuración externos (ballSort.cnf)
- 📊 **Contador de movimientos** para desafiarte a resolver cada nivel de la manera más eficiente
- 🚀 **Diseño modular** utilizando Tipos Abstractos de Datos (TAD)
- 💡 **Validación automática** de movimientos según las reglas del juego
- 🧪 **Conjuntos completos de pruebas** para los TADs utilizados
- 📜 **Documentación detallada** de cada componente del juego
- 🔄 **Detección automática** de victoria una vez que todas las bolas están ordenadas

---

## ⚙️ Requisitos del Sistema

- **Sistema Operativo**: Windows 10 o superior
- **Compilador**: MinGW-w64 con soporte para C++11 o superior
- **Terminal**: Con soporte para códigos ANSI de color
- **Espacio en Disco**: Mínimo 1 MB

---

## 🚀 Compilación y Ejecución

### Compilación

Para compilar el juego, ejecuta el siguiente comando en la terminal desde el directorio del proyecto:

```bash
g++ -o BallSortPuzzle.exe BallSortPuzzle.cpp
```

Alternativamente, si estás usando Visual Studio Code, puedes usar la tarea predefinida "C/C++: g++.exe compilar archivo activo".

### Ejecución

Una vez compilado, ejecuta el juego con:

```bash
./BallSortPuzzle.exe
```

> **Nota**: Asegúrate de tener el archivo `ballSort.cnf` en el mismo directorio o en alguna de las ubicaciones predefinidas para que el juego pueda cargar la configuración inicial.

---

## 🎮 Cómo Jugar

### 🎯 Objetivo

Ordenar todas las bolas de colores de manera que cada tubo contenga bolas de un solo color o esté completamente vacío.

### 📏 Reglas

1. Solo puedes mover la bola que está en la parte superior de cada tubo.
2. Solo puedes mover una bola a otro tubo si:
   - El tubo destino está vacío, o
   - La bola superior del tubo destino es del mismo color que la bola que deseas mover.
3. Un tubo está completo cuando contiene 4 bolas del mismo color.
4. El juego termina cuando todos los tubos contienen bolas de un solo color o están vacíos.

### 🎛️ Controles

- Para realizar un movimiento, introduce el número del tubo origen seguido del número del tubo destino:
  ```
  1 5
  ```
  (Esto moverá la bola superior del tubo 1 al tubo 5)

- Para salir del juego en cualquier momento, escribe `q`.

### 📺 Ejemplo de Juego

```
+----------------------------+
|  1   2   3   4   5   6    |
|  R   B   G   Y   .   .    |
|  G   R   B   Y   .   .    |
|  B   G   Y   R   .   .    |
|  Y   R   G   B   .   .    |
| === === === === === ===   |
+----------------------------+
Movimientos: 0
```

Donde:
- **R** = Rojo
- **G** = Verde
- **B** = Azul
- **Y** = Amarillo
- **.** = Espacio vacío

### 🎲 Estrategia

- Comienza liberando espacio creando tubos completamente vacíos.
- Intenta completar un color a la vez, empezando por los que ya tengan más bolas agrupadas.
- Piensa varios movimientos por adelantado, similar al ajedrez.
- A veces es necesario realizar movimientos temporales para desbloquear otras bolas.

---

## 🧩 Estructura del Proyecto

El proyecto está organizado en diferentes módulos, cada uno con responsabilidades específicas:

| Archivo | Descripción |
|---------|-------------|
| `BallSortPuzzle.cpp` | Programa principal que implementa la interfaz de usuario e interacción |
| `Pila.h`/`Pila.cpp` | TAD Pila que representa los tubos del juego |
| `Tablero.h`/`Tablero.cpp` | TAD Tablero que gestiona el conjunto de pilas |
| `Juego.h`/`Juego.cpp` | TAD Juego que controla la lógica y reglas del juego |
| `PilaPruebas.cpp` | Pruebas unitarias para el TAD Pila |
| `TableroPruebas.cpp` | Pruebas unitarias para el TAD Tablero |
| `ballSort.cnf` | Archivo de configuración con la disposición inicial de bolas |

---

## 🧪 Pruebas

El proyecto incluye conjuntos completos de pruebas para los TADs implementados:

### Pruebas del TAD Pila

Para ejecutar las pruebas del TAD Pila:

```bash
g++ -o PilaPruebas.exe PilaPruebas.cpp
./PilaPruebas.exe
```

### Pruebas del TAD Tablero

Para ejecutar las pruebas del TAD Tablero:

```bash
g++ -o TableroPruebas.exe TableroPruebas.cpp
./TableroPruebas.exe
```

Estas pruebas verifican el correcto funcionamiento de todas las operaciones de los TADs y garantizan la robustez del juego.

---

## 🛠️ Implementación Técnica

### Tipos Abstractos de Datos (TAD)

#### TAD Pila
- Representa cada tubo del juego
- Implementa operaciones como `apilar`, `desapilar`, `cimaPila`, etc.
- Mantiene el estado de cada tubo y verifica si está completo con bolas del mismo color

#### TAD Tablero
- Gestiona el conjunto de pilas (tubos) del juego
- Implementa la lógica para mover bolas entre tubos
- Valida movimientos según las reglas del juego
- Verifica si el juego ha terminado

#### TAD Juego
- Controla el flujo del juego
- Carga la configuración inicial desde el archivo
- Cuenta los movimientos realizados
- Determina cuándo ha terminado el juego

### Complejidad Algorítmica

- Las operaciones básicas de la pila son O(1)
- La verificación de fin de juego es O(n), donde n es el número de pilas
- El movimiento de bolas entre tubos es O(1)

---

## 📊 Personalización

### Archivo de Configuración

El juego utiliza un archivo llamado `ballSort.cnf` para definir la configuración inicial. El formato es el siguiente:

```
[número_total_de_tubos]
[colores_tubo_1]
[colores_tubo_2]
...
[colores_tubo_n]
```

Por ejemplo:
```
6
RBGY
GYRB
BYGR
RGBY
```

Esto crea un juego con 6 tubos (4 llenos y 2 vacíos) con las bolas distribuidas como se muestra.

### Colores Disponibles

- **R**: Rojo
- **G**: Verde
- **B**: Azul
- **Y**: Amarillo
- **M**: Magenta
- **C**: Cian

### Creación de Nuevos Niveles

Para crear nuevos niveles, modifica el archivo `ballSort.cnf` siguiendo estas pautas:
1. La primera línea debe ser el número total de tubos (incluyendo los vacíos)
2. Debe haber suficientes tubos vacíos (generalmente 2)
3. Cada color debe aparecer exactamente 4 veces

---

## ❓ Preguntas Frecuentes

### ¿Cómo sé si un nivel tiene solución?
Todos los niveles creados correctamente tienen solución. Sin embargo, algunos niveles pueden ser más difíciles que otros y requerir más movimientos.

### ¿Cuántos movimientos se necesitan para resolver un nivel?
El número mínimo de movimientos varía según el nivel. El juego cuenta tus movimientos para que puedas intentar mejorar tu puntuación.

### El juego no encuentra el archivo de configuración, ¿qué hago?
Asegúrate de que el archivo `ballSort.cnf` esté en la misma carpeta que el ejecutable del juego o en alguna de las rutas alternativas que el programa busca.

### ¿Puedo tener más de 6 tubos?
Sí, el juego soporta hasta 10 tubos en total. Modifica el archivo de configuración según sea necesario.

### ¿Cómo termino el juego antes de completarlo?
Escribe 'q' en cualquier momento para salir del juego.

---

<div align="center">
  <p>
    Desarrollado con ❤️ como parte de un proyecto académico de Estructuras de Datos<br>
    <b>© 2025 - [Nombre del Estudiante]</b>
  </p>
</div>