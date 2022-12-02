#include "main.h"
#include "mapa.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

MAPA m;
POSICAO heroi;

int main(){

    lemapa(&m);
    encontramapa(&m, &heroi, HEROI);

    do {
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);
        move(comando);
        fantasmas();

    } while (!acabou());

    liberamapa(&m);

    return 0;
}

int acabou(){
    POSICAO pos;
    return !(encontramapa(&m, &pos, HEROI));
}

void move(char direcao){
    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch (direcao) {
        case CIMA:
            proximox--;
            break;
        case ESQUERDA:
            proximoy--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;
        default:
            return;
    }
    if (!podeandar(&m, proximox, proximoy))
        return;

    andanomapa(&m, heroi.x, heroi.y, proximox, proximoy);
    heroi.x = proximox;
    heroi.y = proximoy;
}

void fantasmas(){
    MAPA copia;
    copiamapa(&copia, &m);

    for (int i = 0; i < m.linhas; ++i) {
        for (int j = 0; j < m.colunas; ++j) {
            if (copia.matriz[i][j] == FANTASMA){
                int xdestino, ydestino;

                int encontrou = praondefantasmavai(i, j, &xdestino, &ydestino);

                if (encontrou)
                    andanomapa(&m, i, j, xdestino, ydestino);
            }
        }
    }

    liberamapa(&copia);
}

int praondefantasmavai(int xatual, int yatual, int* xdestino, int* ydestino){
    int opcoes[4][2] = {
            {xatual, yatual+1},
            {xatual+1, yatual},
            {xatual, yatual-1},
            {xatual-1, yatual}
    };

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int posicao = rand() % 4;

        if (podeandar(&m, opcoes[posicao][0], opcoes[posicao][1])){
            *xdestino = opcoes[posicao][0];
            *ydestino = opcoes[posicao][1];
            return 1;
        }
    }
    return 0;
}