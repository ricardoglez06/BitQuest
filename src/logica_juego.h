#ifndef LOGICA_JUEGO_H
#define LOGICA_JUEGO_H

#define MAP_SIZE 60
extern char mapa[MAP_SIZE][MAP_SIZE];

void cargar_mapa();
void imprimir_ventana(int jugador_x, int jugador_y);

#endif