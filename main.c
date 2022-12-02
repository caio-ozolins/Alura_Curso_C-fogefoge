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
    int proximox = heroi.x;
    int proximoy = heroi.y;

    switch (direcao) {
        case 'w':
            proximox--;
            break;
        case 'a':
            proximoy--;
            break;
        case 's':
            proximox++;
            break;
        case 'd':
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