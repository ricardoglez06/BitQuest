#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "mapas.h"

char mapa[MAP_SIZE][MAP_SIZE];

void cargar_mapa() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            mapa[i][j] = nivel1_mapa[i][j];
        }
    }
}

int main() {
    int px = 1, py = 1; 
    int tiene_llave = 0;
    int nivel_completado = 0;
    int dx = 0, dy = 0;

    cargar_mapa();

    while (!nivel_completado) {
        imprimir_ventana(px, py);
        printf("Llaves: %d | WASD = Mover | Q = Salir\n", tiene_llave);
        
        dx = 0; dy = 0;
        char tecla = _getch();
        if (tecla == 'w' || tecla == 'W') dy = -1;
        else if (tecla == 's' || tecla == 'S') dy = 1;
        else if (tecla == 'a' || tecla == 'A') dx = -1;
        else if (tecla == 'd' || tecla == 'D') dx = 1;
        else if (tecla == 'q' || tecla == 'Q') break;

    }

    system("cls");
    if (nivel_completado) {
        printf("\n===================================\n");
        printf("  ¡NIVEL COMPLETADO CON EXITO!\n");
        printf("===================================\n\n");
    } else {
        printf("\nJuego terminado.\n\n");
    }
    return 0;
}