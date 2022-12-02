#ifndef FOGEFOGE_MAPA_H
#define FOGEFOGE_MAPA_H

#define HEROI '@'
#define VAZIO '.'

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
int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA* m, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);

#endif //FOGEFOGE_MAPA_H
