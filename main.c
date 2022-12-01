#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include "mapa.h"

MAPA m;

int main(){

    lemapa(&m);

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
    int x, y;

    // acha o foge foge
    for (int i = 0; i < m.linhas; ++i) {
        for (int j = 0; j < m.colunas; ++j) {
            if (m.matriz[i][j] == '@'){
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direcao) {
        case 'w':
            m.matriz[x-1][y] = '@';
            break;
        case 'a':
            m.matriz[x][y-1] = '@';
            break;
        case 's':
            m.matriz[x+1][y] = '@';
            break;
        case 'd':
            m.matriz[x][y+1] = '@';
            break;
    }

    m.matriz[x][y] = '.';

}