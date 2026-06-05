#include <stdio.h>
#include <stdlib.h>
#include "logica_juego.h"
#include "mapas.h"

void imprimir_ventana(int px, int py) {
    system("cls"); 
    
    // calcular los limites de la ventana
    int inicio_x = px - (VIEW_SIZE / 2);
    int fin_x = px + (VIEW_SIZE / 2);
    int inicio_y = py - (VIEW_SIZE / 2);
    int fin_y = py + (VIEW_SIZE / 2);

    for (int i = inicio_y; i < fin_y; i++) {
        for (int j = inicio_x; j < fin_x; j++) {
            if (i < 0 || i >= MAP_SIZE || j < 0 || j >= MAP_SIZE) {
                printf(" "); // fuera de los limites del mapa
            } else {
                if (i == py && j == px) {
                    printf("\033[1;32mP\033[0m"); 
                } else {
                    printf("%c", mapa[i][j]);
                }
            }
        }
        printf("\n");
    }
    printf("\nCoordenadas: (%d, %d)\n", px, py);
}