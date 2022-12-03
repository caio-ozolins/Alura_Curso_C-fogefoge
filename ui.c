#include "ui.h"
#include "mapa.h"

#include <stdio.h>

char tileWall[4][7] = {
        {"......" },
        {"......" },
        {"......" },
        {"......" }
};

char tileGhost[4][7] = {
        {" .-.  " },
        {"| OO| " },
        {"|   | " },
        {"'^^^' " }
};

char tileHero[4][7] = {
        {" .--. "  },
        {"/ _.-'"  },
        {"\\  '-." },
        {" '--' "  }
};

char tilePill[4][7] = {
        {"      "},
        {" .-.  "},
        {" '-'  "},
        {"      "}
};

char tileEmpty[4][7] = {
        {"      "},
        {"      "},
        {"      "},
        {"      "}
};

void printTile(char tile[4][7], int tileLine){
    printf("%s", tile[tileLine]);
}
void printMap(MAP* map){
    for (int i = 0; i < map->lines; i++) {
        for (int tileLine = 0; tileLine < 4; ++tileLine) {
            for (int j = 0; j < map->columns; ++j) {
                switch (map->matrix[i][j]) {
                    case GHOST:
                        printTile(tileGhost, tileLine);
                        break;
                    case HERO:
                        printTile(tileHero, tileLine);
                        break;
                    case PILL:
                        printTile(tilePill, tileLine);
                        break;
                    case VERTICAL_WALL:
                    case HORIZONTAL_WALL:
                        printTile(tileWall, tileLine);
                        break;
                    case EMPTY:
                        printTile(tileEmpty, tileLine);
                        break;
                }
            }
            printf("\n");
        }
    }
}