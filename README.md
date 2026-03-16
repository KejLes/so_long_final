*Este proyecto ha sido creado como parte del currículo de 42 por kcanales.*

# so_long

## Descripción

`so_long` es un pequeño juego 2D desarrollado en C como parte del currículo de 42.  
El objetivo del juego es controlar a un personaje en un mapa cerrado, recoger todos los coleccionables y llegar a la salida.  
El mapa se carga desde un archivo con extensión `.ber`, se valida (forma, contenido y paredes) y después se renderiza utilizando la librería gráfica MLX42.  
El proyecto pone el foco en la gestión correcta de memoria, el diseño de estructuras de datos, el manejo de errores y el uso de una librería gráfica mínima.

## Instrucciones

### Requisitos

- Compilador C compatible (`cc`, `clang` o `gcc`).
- `make`.
- `cmake` para compilar MLX42.
- Librerías del sistema:
  - En Linux: `glfw`, `X11`, `Xrandr`, `Xi`, `dl`, `pthread`, `m`.
  - En macOS: frameworks `Cocoa`, `OpenGL`, `IOKit` y `glfw`.
- Submódulos / carpetas:
  - `libs/MLX42` (MLX42).
  - `libs/libft` (libft).
  - `libs/ft_printf` (ft_printf).

### Compilación

Desde la raíz del repositorio:

```bash
make
```

Este comando:

- Compila `libft` y `ft_printf`.
- Compila y construye MLX42 en `libs/MLX42/build`.
- Compila los archivos fuente de `src/` y genera el ejecutable `so_long`.

Comandos de limpieza:

```bash
make clean      # elimina archivos objeto
make fclean     # elimina objetos, ejecutable y build de MLX42
make re         # recompila todo desde cero
make norminette # ejecuta norminette sobre src/ y so_long.h
```

### Ejecución

El programa se ejecuta pasando un mapa en formato `.ber` como argumento:

```bash
./so_long path/al_mapa.ber
```

Reglas básicas del mapa:

- El archivo debe tener extensión `.ber`.
- El mapa debe ser un rectángulo (todas las filas del mismo ancho).
- Debe estar completamente rodeado de paredes.
- Debe contener:
  - 1 sola posición de jugador.
  - 1 sola salida.
  - Al menos 1 coleccionable.
- Solo se admiten caracteres válidos (pared, vacío, jugador, salida, coleccionable y saltos de línea).

Si el mapa es inválido, el archivo no existe o ocurre algún error al leer o renderizar, el programa muestra un mensaje descriptivo y finaliza liberando la memoria reservada.

### Controles

> Sustituye por las teclas exactas que uses en tu implementación.

- Movimiento: `W`, `A`, `S`, `D` o flechas de dirección.
- Salir del juego: tecla `ESC` o cerrar la ventana.

## Recursos

### Documentación y artículos

- Documentación oficial de 42 para el proyecto `so_long` (intra de 42).
- Documentación de MLX42:
  - Guía de uso de MLX42 (estructuras, `mlx_load_png`, `mlx_texture_to_image`, manejo de ventanas y eventos).
- Documentación de `glfw` y librerías gráficas relacionadas (según el sistema operativo).
- Referencias de C estándar:
  - `cppreference.com` (sección de C).
  - Tutoriales de gestión de memoria dinámica en C (uso de `malloc`, `calloc`, `free`).
- Normas de estilo de 42 (Norminette) para la organización del código y los ficheros.

### Uso de IA en el proyecto

En este proyecto se ha utilizado IA principalmente como soporte de documentación y redacción:

- Ayuda para redactar y estructurar este archivo `README.md` (descripción, instrucciones y sección de recursos).
- Resolución puntual de dudas sobre:
  - Comandos de compilación y enlaces con MLX42 y librerías del sistema.
  - Ajustes en la línea de compilación y en el `Makefile`.
- La lógica del juego, el diseño de las estructuras, la validación del mapa y la implementación del código en C se han realizado de forma manual, utilizando la documentación oficial y recursos clásicos de aprendizaje de C.  
- No se ha utilizado IA para generar directamente funciones completas críticas del proyecto (como la lógica de movimiento, la gestión de memoria o la validación del mapa), sino como apoyo para aclarar conceptos y mejorar la claridad de los mensajes de error y la documentación.