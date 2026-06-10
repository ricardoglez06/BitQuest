@echo off

echo [1/3] Ensamblando ASM (Modo 32-bits)...
nasm -f win32 src/rutinas_asm.asm -o src/rutinas_asm.obj

echo [2/3] Compilando C y enlazando modulos...
gcc src/main.c src/logica_juego.c src/rutinas_asm.obj -o BitQuest.exe

echo [3/3] Ejecutando juego...
if exist BitQuest.exe (
    BitQuest.exe
) else (
    echo.
    echo [ERROR] No se pudo crear el archivo ejecutable.
)

pause