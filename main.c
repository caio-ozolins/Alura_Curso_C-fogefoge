#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

MAPA m;
POSICAO heroi;

int main(){

    lemapa(&m);
    encontramapa(&m, &heroi, '@');

    do {
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());

    liberamapa(&m);

    return 0;
}

int acabou(){
    return 0;
}

void move(char direcao){
    m.matriz[heroi.x][heroi.y] = '.';

    switch (direcao) {
        case 'w':
            m.matriz[heroi.x-1][heroi.y] = '@';
            heroi.x--;
            break;
        case 'a':
            m.matriz[heroi.x][heroi.y-1] = '@';
            heroi.y--;
            break;
        case 's':
            m.matriz[heroi.x+1][heroi.y] = '@';
            heroi.x++;
            break;
        case 'd':
            m.matriz[heroi.x][heroi.y+1] = '@';
            heroi.y++;
            break;
    }
}