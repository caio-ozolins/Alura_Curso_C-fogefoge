#ifndef FOGEFOGE_MAPA_H
#define FOGEFOGE_MAPA_H

#define HEROI '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

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
int encontramapa(MAPA* m, POSICAO* p, char c);
int ehvalida(MAPA* m, int x, int y);
int ehvazia(MAPA* m, int x, int y);
void andanomapa(MAPA* m, int xorigem, int yorigem, int xdestino, int ydestino);
void copiamapa(MAPA* destino, MAPA* origem);
int podeandar(MAPA* m, char personagem, int x, int y);
int ehparede(MAPA* m, int x, int y);
int ehpersonagem(MAPA* m, char personagem, int x, int y);

#endif //FOGEFOGE_MAPA_H
