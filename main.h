#ifndef FOGEFOGE_MAIN_H
#define FOGEFOGE_MAIN_H

void liberamapa();
void lemapa();
void alocamapa();
void imprimemapa();
int acabou();
void move(char direcao);

struct Mapa{
    char** matriz;
    int linhas, colunas;
};

#endif //FOGEFOGE_MAIN_H
