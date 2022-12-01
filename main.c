#include "main.h"
#include <stdio.h>
#include <stdlib.h>

MAPA m;

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
    for (int i = 0; i < m.linhas; ++i) {
        free(m.matriz[i]);
    }
    free(m.matriz);
}

void lemapa(){
    FILE* f;
    f = fopen("..\\mapa.txt", "r");
    if(f == 0) {
        printf("Erro na leitura do mapa");
        exit(1);
    }

    fscanf(f, "%d %d", &m.linhas, &m.colunas);
    alocamapa();

    for (int i = 0; i < m.linhas; i++) {
        fscanf(f, "%s", m.matriz[i]);
    }
    fclose(f);
}

void alocamapa(){
    m.matriz = malloc(sizeof(char*) * m.linhas);
    for (int i = 0; i < m.linhas; ++i) {
        m.matriz[i] = malloc(sizeof(char) * m.colunas + 1);
    }
}

void imprimemapa(){
    for (int i = 0; i < m.linhas; i++) {
        printf("%s\n", m.matriz[i]);
    }
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