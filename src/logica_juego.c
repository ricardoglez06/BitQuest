#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "logica_juego.h"
#include "mapas.h"

char mapa[MAP_SIZE][MAP_SIZE];

void cargar_mapa(int nivel, int *px, int *py) {
    char nombre_archivo[32];
    // nombre del archivo dinamico:nivel1.txt, nivel2.txt....
    sprintf(nombre_archivo, "nivel%d.txt", nivel);

    FILE *file = fopen(nombre_archivo, "r");
    if (file == NULL) {
        system("cls");
        printf("==================================================\n");
        printf(" ERROR: No se pudo abrir el archivo: %s\n", nombre_archivo);
        printf(" Asegurate de que el archivo exista en la misma carpeta.\n");
        printf("==================================================\n");
        printf("Presiona cualquier tecla para salir...");
        _getch();
        exit(1);
    }

    char linea[128];
    int fila = 0;

    // Lee linea por linea hasta completar el tamaño del mapa
    while (fila < MAP_SIZE && fgets(linea, sizeof(linea), file)) {
        for (int j = 0; j < MAP_SIZE; j++) {
            // en caso de que la línea del archivo sea más corta de lo esperado o tenga saltos 
            if (linea[j] == '\n' || linea[j] == '\r' || linea[j] == '\0') {
                for (int k = j; k < MAP_SIZE; k++) {
                    mapa[fila][k] = '#'; // Rellena con pared si falta información
                }
                break;
            }

            mapa[fila][j] = linea[j];

            // checa la posición inicial del jugador
            if (mapa[fila][j] == 'P') {
                *px = j;
                *py = fila;
                mapa[fila][j] = '.'; // Reemplaza por suelo caminable
            }
        }
        fila++;
    }
    fclose(file);
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
                printf("\033[1;32mP\033[0m");
            } else if (mapa[i][j] == '#') {
                printf("#");
            } else if (mapa[i][j] == 'M') {
                printf("\033[1;33mM\033[0m");
            } else if (mapa[i][j] == 'K') {
                printf("\033[1;35mK\033[0m");
            } else if (mapa[i][j] == 'D') {
                printf("\033[1;31mD\033[0m");
            } else if (mapa[i][j] == 'E') {
                printf("\033[1;36mE\033[0m");
            }else if(mapa [i][j] == 'C'){
                printf("\033[1;31mC\033[0m");
            }else {
                printf("%c", mapa[i][j]);
            }
        }
        printf("\n");
    }
}
void mover_enemigos(int jugador_x, int jugador_y){
    int ya_movido[MAP_SIZE][MAP_SIZE] = {0}; //marca cuando ya se movio

    for (int i=0; i<MAP_SIZE; i++){
        for(int j=0; j < MAP_SIZE; j++){
            if(mapa[i][j] == 'C' && !ya_movido[i][j]){
                int dist_x = abs(jugador_x -j);
                int dist_y = abs(jugador_y -i);
                int distancia_total = dist_x + dist_y;

                if (distancia_total <= 6){
                    int nuevo_x = j;
                    int nuevo_y = i;
                    if(jugador_x <j && mapa[i][j-1] == '.')nuevo_x = j-1;
                    else if(jugador_x > j && mapa[i][j+1] == '.')nuevo_x = j+1;
                    else if(jugador_y < i && mapa[i-1][j] == '.')nuevo_y = i-1;
                    else if(jugador_y > i && mapa[i+1][j] == '.')nuevo_y = i+1;

                    if (nuevo_x !=j || nuevo_y !=i){
                        mapa[i][j]='.';
                        mapa[nuevo_y][nuevo_x]='C';
                        ya_movido[nuevo_y][nuevo_x]=1;                
                    }
                }
        }   }
}
}