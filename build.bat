@echo off
nasm -f win64 src/rutinas_asm.asm -o src/rutinas_asm.obj
gcc src/main.c src/logica_juego.c src/rutinas_asm.obj -o BitQuest.exe -lwinmm
if exist BitQuest.exe (
    BitQuest.exe
) else (
    echo [ERROR] No se pudo crear el archivo ejecutable.
)
pause