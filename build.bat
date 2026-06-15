@echo off
:: Definimos las rutas a las herramientas de MSYS2 UCRT64
set PATH=C:\msys64\ucrt64\bin;%PATH%

:: Ensamblamos con NASM
nasm -f win64 src/rutinas_asm.asm -o src/rutinas_asm.obj

:: Compilamos con GCC (usando las mismas rutas)
gcc src/main.c src/logica_juego.c src/rutinas_asm.obj -o BitQuest.exe -lwinmm

:: Verificación
if exist BitQuest.exe (
    echo [EXITO] Ejecutable creado.
    BitQuest.exe
) else (
    echo [ERROR] No se pudo crear el archivo ejecutable.
)
pause