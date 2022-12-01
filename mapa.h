#ifndef FOGEFOGE_MAPA_H
#define FOGEFOGE_MAPA_H

struct Mapa{
    char** matriz;
    int linhas, colunas;
};
typedef struct Mapa MAPA;

void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void alocamapa(MAPA* m);
void imprimemapa(MAPA* m);

#endif //FOGEFOGE_MAPA_H
