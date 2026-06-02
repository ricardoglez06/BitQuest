#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 60

char mapa[MAP_SIZE][MAP_SIZE];

void cargar_mapa(const char* nombre_archivo) {
    FILE* file = fopen(nombre_archivo, "r");
    if (!file) {
        printf("Error: No se pudo abrir %s\n", nombre_archivo);
        return;
    }
    for (int i = 0; i < MAP_SIZE; i++) {
        fgets(mapa[i], MAP_SIZE + 2, file); 
    }
    fclose(file);
}

void dibujar_ventana(int jugador_x, int jugador_y) {
    int inicio_x = jugador_x - 10;
    int inicio_y = jugador_y - 10;

    // ajustar bordes
    if (inicio_x < 0) inicio_x = 0;
    if (inicio_y < 0) inicio_y = 0;
    if (inicio_x > MAP_SIZE - 20) inicio_x = MAP_SIZE - 20;
    if (inicio_y > MAP_SIZE - 20) inicio_y = MAP_SIZE - 20;

    for (int i = inicio_y; i < inicio_y + 20; i++) {
        for (int j = inicio_x; j < inicio_x + 20; j++) {
            printf("%c", mapa[i][j]);
        }
        printf("\n");
    }
}

int main() {
    cargar_mapa("../mapas/nivel1.txt");
    
    int player_x = 1; 
    int player_y = 1;
    
    int juego_activo = 1;
    char input;

    while(juego_activo) {
        system("cls"); 
        
        printf("~BitQuest~\n");
        printf("Posicion: %d, %d\n", player_x, player_y);
        
        dibujar_ventana(player_x, player_y);
        
        printf("\nPresiona WASD para mover, 'q' para salir: ");
        input = getch(); 

        if(input == 'w') player_y--;
        if(input == 's') player_y++;
        if(input == 'a') player_x--;
        if(input == 'd') player_x++;
        if(input == 'q') juego_activo = 0;
    }

    printf("Juego terminado\n");
    return 0;
}