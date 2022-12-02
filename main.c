#include "main.h"
#include "mapa.h"

#include <stdio.h>
#include <stdlib.h>

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
    return 0;
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
    if (!ehvalida(&m, proximox, proximoy))
        return;
    if (!ehvazia(&m, proximox, proximoy))
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
                if (ehvalida(&m, i, j+1) && ehvazia(&m, i, j+1)){
                    andanomapa(&m, i, j, i, j+1);
                }
            }
        }
    }

    liberamapa(&copia);
}