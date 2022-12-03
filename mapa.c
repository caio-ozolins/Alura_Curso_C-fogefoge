#include "mapa.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void freeMap(MAP* map){
    for (int i = 0; i < map->lines; ++i) {
        free(map->matrix[i]);
    }
    free(map->matrix);
}
void readMap(MAP* map){
    FILE* f;
    f = fopen("..\\mapa.txt", "r");
    if(f == 0) {
        printf("Erro na leitura do mapa");
        exit(1);
    }

    fscanf(f, "%d %d", &(map->lines), &(map->columns));
    allocateMap(map);

    for (int i = 0; i < map->lines; i++) {
        fscanf(f, "%s", map->matrix[i]);
    }
    fclose(f);
}
void allocateMap(MAP* map){
    map->matrix = malloc(sizeof(char*) * map->lines);
    for (int i = 0; i < map->lines; ++i) {
        map->matrix[i] = malloc(sizeof(char) * map->columns + 1);
    }
}
int findInMap(MAP* map, POSITION* position, char c){
    for (int i = 0; i < map->lines; ++i) {
        for (int j = 0; j < map->columns; ++j) {
            if (map->matrix[i][j] == c){
                position->x = i;
                position->y = j;
                return 1;
            }
        }
    }
    return 0;
}
int isValid(MAP* map, int x, int y){
    return !(x >= map->lines || y >= map->columns);
}
int isWall(MAP* map, int x, int y){
    return map->matrix[x][y] == HORIZONTAL_WALL || map->matrix[x][y] == VERTICAL_WALL;
}
int isCharacter(MAP* map, char character, int x, int y){
    return map->matrix[x][y] == character;
}
void moveTo(MAP* map, int xOrigin, int yOrigin, int xDestiny, int yDestiny){
    char character = map->matrix[xOrigin][yOrigin];
    map->matrix[xDestiny][yDestiny] = character;
    map->matrix[xOrigin][yOrigin] = EMPTY;
}
void copyMap(MAP* destiny, MAP* origin){
    destiny->lines = origin->lines;
    destiny->columns = origin->columns;

    allocateMap(destiny);

    for (int i = 0; i < origin->lines; ++i) {
        strcpy(destiny->matrix[i], origin->matrix[i]);
    }
}
int canGoToTile(MAP* map, char character, int x, int y){
    return isValid(map, x, y) && !isWall(map, x, y) && !isCharacter(map, character, x, y);
}