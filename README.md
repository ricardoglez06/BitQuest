# BitQuest

Nuestro juego trata sobre exploracion, este siendo ejecutado en consola desarrollado en el lenguaje C junto con algunas rutinas optimizadas en lenguaje ensamblador (NASM) de 64 bits.

## Requisitos Previos

Para poder compilar nuestro proyecto, tu sistema debe tener las siguientes herramientas configuradas en las variables de entorno (`PATH`):
* **Sistema Operativo:** Windows
* **Compilador C:** GCC 
* **Ensamblador:** NASM

## Como compilar y ejecutar el proyecto

El proyecto incluye un script automatizado llamado (`build.bat`) que va a ayudar en la construccion del ejecutable sin tener que introducir los comandos a mano. Solo sigue estos pasos:

1. Abre la carpeta del proyecto en el explorador de archivos o terminal.
2. Ejecuta el archivo `build.bat` (doble clic o escribiendo `build.bat` en la consola).
3. El script va a realizar los siguientes pasos automaticamente:
   * Ensamblara `rutinas_asm.asm` creando el archivo objeto `rutinas_asm.obj`.
   * Compilara los archivos fuente en C (`main.c`, `logica_juego.c`) y los cordinara con el codigo de NASM.
4. Una vez que la consola indique que la compilacion tuvo exitosa, se generara el archivo `BitQuest.exe`.
5. Ejecuta `BitQuest.exe` para empezar el juego el juego.