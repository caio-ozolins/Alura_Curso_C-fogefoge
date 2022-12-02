#ifndef FOGEFOGE_MAIN_H
#define FOGEFOGE_MAIN_H

#define CIMA 'w'
#define ESQUERDA 'a'
#define BAIXO 's'
#define DIREITA 'd'
#define BOMBA 'b'

int acabou();
void move(char direcao);
void fantasmas();
int praondefantasmavai(int xatual, int yatual, int* xdestino, int* ydestino);
void explodepilula();
void explodepilula2(int x, int y, int somax, int somay,int qtd);

#endif //FOGEFOGE_MAIN_H
