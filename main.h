#ifndef FOGEFOGE_MAIN_H
#define FOGEFOGE_MAIN_H

#define CIMA 'w'
#define ESQUERDA 'a'
#define BAIXO 's'
#define DIREITA 'd'
#define BOMBA 'b'

int gameover();
void move(char direction);
void fantasmas();
int movementDirection(int xOrigin, int yOrigin, int* xDestiny, int* yDestiny);
void usePill();
void explode(int x, int y, int sumX, int sumY, int qty);

#endif //FOGEFOGE_MAIN_H
