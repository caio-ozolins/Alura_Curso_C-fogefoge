#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char** mapa;
int linhas, colunas;

int main(){

    lemapa();

    do {
        imprimemapa();

        char comando;
        scanf(" %c", &comando);
        move(comando);

    } while (!acabou());

    liberamapa();

    return 0;
}

void liberamapa(){
    for (int i = 0; i < linhas; ++i) {
        free(mapa[i]);
    }
    free(mapa);
}

void lemapa(){
    FILE* f;
    f = fopen("..\\mapa.txt", "r");
    if(f == 0) {
        printf("Erro na leitura do mapa");
        exit(1);
    }

    fscanf(f, "%d %d", &linhas, &colunas);
    alocamapa();

    for (int i = 0; i < linhas; i++) {
        fscanf(f, "%s", mapa[i]);
    }
    fclose(f);
}

void alocamapa(){
    mapa = malloc(sizeof(char*) * linhas);
    for (int i = 0; i < linhas; ++i) {
        mapa[i] = malloc(sizeof(char) * colunas + 1);
    }
}

void imprimemapa(){
    for (int i = 0; i < linhas; i++) {
        printf("%s\n", mapa[i]);
    }
}

int acabou(){
    return 0;
}

void move(char direcao){
    int x, y;

    // acha o foge foge
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            if (mapa[i][j] == '@'){
                x = i;
                y = j;
                break;
            }
        }
    }

    switch (direcao) {
        case 'w':
            mapa[x-1][y] = '@';
            break;
        case 'a':
            mapa[x][y-1] = '@';
            break;
        case 's':
            mapa[x+1][y] = '@';
            break;
        case 'd':
            mapa[x][y+1] = '@';
            break;
    }

    mapa[x][y] = '.';

}