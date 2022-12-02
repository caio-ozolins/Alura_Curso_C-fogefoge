#ifndef FOGEFOGE_MAIN_H
#define FOGEFOGE_MAIN_H

#define CIMA 'w'
#define ESQUERDA 'a'
#define BAIXO 's'
#define DIREITA 'd'

int acabou();
void move(char direcao);
void fantasmas();
int praondefantasmavai(int xatual, int yatual, int* xdestino, int* ydestino);

#endif //FOGEFOGE_MAIN_H
