#ifndef FOGEFOGE_MAPA_H
#define FOGEFOGE_MAPA_H

struct Mapa{
    char** matriz;
    int linhas, colunas;
};
typedef struct Mapa MAPA;

typedef struct{
    int x,y;
} POSICAO;

void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimemapa(MAPA* m);
void encontramapa(MAPA* m, POSICAO* p, char c);

#endif //FOGEFOGE_MAPA_H
