#include <stdio.h>
#include "logica_juego.h"
#include "mapas.h"

extern int es_colision(char caracter);

char mapa[MAP_SIZE][MAP_SIZE];

void cargar_mapa() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            mapa[i][j] = nivel1_mapa[i][j];
        }
    }
}

void imprimir_ventana(int jugador_x, int jugador_y) {
    int inicio_x = jugador_x - 10;
    int inicio_y = jugador_y - 10;

    if (inicio_x < 0) inicio_x = 0;
    if (inicio_y < 0) inicio_y = 0;
    if (inicio_x > MAP_SIZE - 20) inicio_x = MAP_SIZE - 20;
    if (inicio_y > MAP_SIZE - 20) inicio_y = MAP_SIZE - 20;

    for (int i = inicio_y; i < inicio_y + 20; i++) {
        for (int j = inicio_x; j < inicio_x + 20; j++) {
            if (i == jugador_y && j == jugador_x) {
                printf("P");
            } else {
                printf("%c", mapa[i][j]);
            }
        }
        printf("\n");
    }
}