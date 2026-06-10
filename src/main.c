#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "logica_juego.h"

extern int es_colision(char caracter);

void ocultar_cursor_y_reset() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(hConsole, pos);
}

int main() {
    int px = 1, py = 1; 
    int tiene_llave = 0;
    int nivel_completado = 0;
    int dx = 0, dy = 0;

    cargar_mapa();
    system("cls");

    while (!nivel_completado) {
        ocultar_cursor_y_reset(); 
        
        printf("=======================================\n");
        printf("   BitQuest - Escapa del Laberinto     \n");
        printf("=======================================\n");
        
        imprimir_ventana(px, py);
        
        printf("=======================================\n");
        printf(" Llaves: %d/1 | WASD: Mover | Q: Salir\n", tiene_llave);
        printf("=======================================\n");
        
        dx = 0; dy = 0;
        char tecla = _getch();
        if (tecla == 'w' || tecla == 'W') dy = -1;
        else if (tecla == 's' || tecla == 'S') dy = 1;
        else if (tecla == 'a' || tecla == 'A') dx = -1;
        else if (tecla == 'd' || tecla == 'D') dx = 1;
        else if (tecla == 'q' || tecla == 'Q') break;

        int nx = px + dx;
        int ny = py + dy;

        if (nx >= 0 && nx < MAP_SIZE && ny >= 0 && ny < MAP_SIZE) {
            char celda_siguiente = mapa[ny][nx];

            if (es_colision(celda_siguiente) == 0) {
                if (celda_siguiente == 'c') {
                    mapa[ny][nx] = '.'; 
                    px = nx; py = ny;   
                }
                else if (celda_siguiente == 'K') {
                    tiene_llave = 1;
                    mapa[ny][nx] = '.'; 
                    px = nx; py = ny;
                }
                else if (celda_siguiente == 'D') {
                    if (tiene_llave) {
                        tiene_llave = 0;    
                        mapa[ny][nx] = '.'; 
                        px = nx; py = ny;
                    } else {
                        continue; 
                    }
                }
                else if (celda_siguiente == 'E') {
                    nivel_completado = 1;
                    px = nx; py = ny;
                }
                else {
                    px = nx; py = ny;
                }
            }
        }
    }

    system("cls");
    if (nivel_completado) {
        printf("\n===================================\n");
        printf("   ¡NIVEL COMPLETADO CON EXITO!\n");
        printf("===================================\n\n");
    } else {
        printf("\nJuego terminado.\n\n");
    }
    return 0;
}