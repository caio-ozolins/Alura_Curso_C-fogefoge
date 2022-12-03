#ifndef FOGEFOGE_MAPA_H
#define FOGEFOGE_MAPA_H

#define HERO '@'
#define GHOST 'F'
#define EMPTY '.'
#define VERTICAL_WALL '|'
#define HORIZONTAL_WALL '-'
#define PILL 'P'

typedef struct{
    char** matrix;
    int lines, columns;
} MAP;
typedef struct{
    int x,y;
} POSITION;

void freeMap(MAP* map);
void readMap(MAP* map);
void allocateMap(MAP* map);
int findInMap(MAP* map, POSITION* position, char c);
int isValid(MAP* map, int x, int y);
int isWall(MAP* map, int x, int y);
int isCharacter(MAP* map, char character, int x, int y);
void moveTo(MAP* map, int xOrigin, int yOrigin, int xDestiny, int yDestiny);
void copyMap(MAP* destiny, MAP* origin);
int canGoToTile(MAP* map, char character, int x, int y);

#endif //FOGEFOGE_MAPA_H
