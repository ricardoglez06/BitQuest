#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "logica_juego.h"

extern int es_colision(char caracter);

int main() {
    int px = 1, py = 1; 
    int tiene_llave = 0;
    int nivel_completado = 0;
    int dx = 0, dy = 0;

    cargar_mapa();

    while (!nivel_completado) {
        system("cls"); 
        
        imprimir_ventana(px, py);
        printf("Llaves: %d | WASD = Mover | Q = Salir\n", tiene_llave);
        
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