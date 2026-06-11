#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "logica_juego.h"

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
    int nivel_actual = 1;
    long long monedas_totales_recolectadas = 0;
    long long monedas_totales_juego = 0;
    long long pasos_totales = 0;
    int juego_interrumpido = 0;

    system("cls");

    while (nivel_actual <= 3 && !juego_interrumpido) {
        int px = 1, py = 1;
        int tiene_llave = 0;
        int nivel_completado = 0;
        long long pasos_nivel = 0;
        long long monedas_recolectadas_nivel = 0;

        cargar_mapa(nivel_actual, &px, &py);

        long long total_monedas_nivel = contar_caracteres((char*)mapa, MAP_SIZE * MAP_SIZE, 'M');
        long long celdas_libres_nivel = contar_celdas_libres((char*)mapa, MAP_SIZE * MAP_SIZE);
        monedas_totales_juego += total_monedas_nivel;

        system("cls");

        while (!nivel_completado) {
            ocultar_cursor_y_reset();

            printf("=======================================\n");
            printf("   BitQuest - Nivel: %d                 \n", nivel_actual);
            printf("=======================================\n");
            printf(" Celdas Caminables en el Mapa: %lld\n", celdas_libres_nivel);
            printf("---------------------------------------\n");

            imprimir_ventana(px, py);

            printf("=======================================\n");
            printf(" Llave: %s | Monedas: %lld/%lld\n", tiene_llave ? "Si" : "No", monedas_recolectadas_nivel, total_monedas_nivel);
            printf(" Pasos: %lld | WASD: Mover | Q: Salir\n", pasos_nivel);
            printf("=======================================\n");

            int dx = 0, dy = 0;
            char tecla = _getch();
            if (tecla == 'w' || tecla == 'W') dy = -1;
            else if (tecla == 's' || tecla == 'S') dy = 1;
            else if (tecla == 'a' || tecla == 'A') dx = -1;
            else if (tecla == 'd' || tecla == 'D') dx = 1;
            else if (tecla == 'q' || tecla == 'Q') {
                juego_interrumpido = 1;
                break;
            }

            if (dx != 0 || dy != 0) {
                pasos_nivel++;
                pasos_totales++;

                int nx = px + dx;
                int ny = py + dy;

                if (nx >= 0 && nx < MAP_SIZE && ny >= 0 && ny < MAP_SIZE) {
                    if (validar_movimiento((char*)mapa, MAP_SIZE, ny, nx) == 1) {
                        if (detectar_objeto((char*)mapa, MAP_SIZE, ny, nx, 'M') == 1) {
                            monedas_recolectadas_nivel++;
                            mapa[ny][nx] = '.';
                            px = nx; py = ny;
                        }
                        else if (detectar_objeto((char*)mapa, MAP_SIZE, ny, nx, 'K') == 1) {
                            tiene_llave = 1;
                            mapa[ny][nx] = '.';
                            px = nx; py = ny;
                        }
                        else if (detectar_objeto((char*)mapa, MAP_SIZE, ny, nx, 'D') == 1) {
                            if (tiene_llave) {
                                tiene_llave = 0;
                                mapa[ny][nx] = '.';
                                px = nx; py = ny;
                            }
                        }
                        else if (detectar_objeto((char*)mapa, MAP_SIZE, ny, nx, 'E') == 1) {
                            nivel_completado = 1;
                            px = nx; py = ny;
                        }
                        else {
                            px = nx; py = ny;
                        }
                    }
                }
            }
        }

        if (nivel_completado) {
            monedas_totales_recolectadas += monedas_recolectadas_nivel;
            system("cls");
            printf("=================================\n");
            printf("Nivel %d completado\n", nivel_actual);
            printf("Monedas recolectadas: %lld/%lld\n", monedas_recolectadas_nivel, total_monedas_nivel);
            printf("Pasos realizados: %lld\n", pasos_nivel);
            printf("=================================\n\n");
            printf("Presiona cualquier tecla para continuar...");
            _getch();
            nivel_actual++;
        }
    }

    system("cls");
    if (!juego_interrumpido && nivel_actual > 3) {
        long long puntaje_final = calcular_puntaje(monedas_totales_recolectadas, pasos_totales, 3);
        printf("=======\n");
        printf("Juego completado\n");
        printf("=================\n");
        printf("Monedas totales recolectadas: %lld/%lld\n", monedas_totales_recolectadas, monedas_totales_juego);
        printf("Pasos totales: %lld\n", pasos_totales);
        printf("Niveles completados: 3\n");
        printf("Puntaje final: %lld\n", puntaje_final);
        printf("=================\n\n");
    } else {
        printf("\nJuego terminado anticipadamente.\n\n");
    }

    return 0;
}