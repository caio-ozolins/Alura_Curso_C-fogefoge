#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    // matriz 5x10
    char mapa[5][10+1];

    FILE* f;
    f = fopen("..\\mapa.txt", "r");
    if(f == 0) {
        printf("Erro na leitura do mapa");
        exit(1);
    }
    for (int i = 0; i <= 5; i++) {
        fscanf(f, "%s", mapa[i]);
    }

    for (int i = 0; i <= 5; i++) {
        printf("%s\n", mapa[i]);
    }
    
    fclose(f);
    
    return 0;
}