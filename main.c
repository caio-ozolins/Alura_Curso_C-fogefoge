#include "main.h"
#include "mapa.h"
#include "ui.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

MAP map;
POSITION hero;
int hasPill = 0;

int main(){

    readMap(&map);
    findInMap(&map, &hero, HERO);

    do {
        printf("Tem pilula: %s\n", (hasPill ? "SIM" : "NAO"));
        printMap(&map);

        char comando;
        scanf(" %c", &comando);
        move(comando);
        if (comando == BOMBA) usePill();

        fantasmas();

    } while (!gameover());

    freeMap(&map);

    return 0;
}

int gameover(){
    POSITION position;
    return !(findInMap(&map, &position, HERO));
}

void move(char direction){
    int xDestiny = hero.x;
    int yDestiny = hero.y;

    switch (direction) {
        case CIMA:
            xDestiny--;
            break;
        case ESQUERDA:
            yDestiny--;
            break;
        case BAIXO:
            xDestiny++;
            break;
        case DIREITA:
            yDestiny++;
            break;
        default:
            return;
    }
    if (!canGoToTile(&map, HERO, xDestiny, yDestiny))
        return;

    if(isCharacter(&map, PILL, xDestiny, yDestiny))
        hasPill = 1;

    moveTo(&map, hero.x, hero.y, xDestiny, yDestiny);
    hero.x = xDestiny;
    hero.y = yDestiny;
}

void fantasmas(){
    MAP mapCopy;
    copyMap(&mapCopy, &map);

    for (int i = 0; i < map.lines; ++i) {
        for (int j = 0; j < map.columns; ++j) {
            if (mapCopy.matrix[i][j] == GHOST){
                int xDestiny, yDestiny;
                int movementIsValid = movementDirection(i, j, &xDestiny, &yDestiny);
                if (movementIsValid)
                    moveTo(&map, i, j, xDestiny, yDestiny);
            }
        }
    }
    freeMap(&mapCopy);
}

int movementDirection(int xOrigin, int yOrigin, int* xDestiny, int* yDestiny){
    int direction[4][2] = {
            {xOrigin,     yOrigin + 1},
            {xOrigin + 1, yOrigin},
            {xOrigin,     yOrigin - 1},
            {xOrigin - 1, yOrigin}
    };

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int position = rand() % 4;

        if (canGoToTile(&map, GHOST, direction[position][0], direction[position][1])){
            *xDestiny = direction[position][0];
            *yDestiny = direction[position][1];
            return 1;
        }
    }
    return 0;
}

void usePill(){
    if (!hasPill) return;

    explode(hero.x, hero.y, 0, 1, 3);
    explode(hero.x, hero.y, 0, -1, 3);
    explode(hero.x, hero.y, 1, 0, 3);
    explode(hero.x, hero.y, -1, 0, 3);

    hasPill = 0;
}

void explode(int x, int y, int sumX, int sumY, int qty){
    if (qty == 0) return;

    int newX = x + sumX;
    int newY = y + sumY;

    if (!isValid(&map, newX, newY)) return;
    if (isWall(&map, newX, newY)) return;

    map.matrix[newX][newY] = EMPTY;
    explode(newX, newY, sumX, sumY, qty - 1);
}