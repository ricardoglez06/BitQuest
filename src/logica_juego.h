#ifndef LOGICA_JUEGO_H
#define LOGICA_JUEGO_H

#define MAP_SIZE 60
extern char mapa[MAP_SIZE][MAP_SIZE];

void cargar_mapa(int nivel, int *px, int *py);
void imprimir_ventana(int jugador_x, int jugador_y);

extern long long contar_caracteres(char* mapa, long long total_celdas, long long caracter);
extern long long validar_movimiento(char* mapa, long long columnas, long long fila, long long col);
extern long long calcular_puntaje(long long monedas, long long pasos, long long niveles);
extern long long detectar_objeto(char* mapa, long long columnas, long long fila, long long col, long long objeto);
extern long long contar_celdas_libres(char* mapa, long long total_celdas);

#endif