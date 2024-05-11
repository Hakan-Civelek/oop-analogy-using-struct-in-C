#include "Canli.h"
#include <stdlib.h>

Canli CanliOlustur(int tur, int can, int konumX, int konumY) {
    Canli this;
    this = (Canli)malloc(sizeof(struct CANLI));
    this->tur = tur;
    this->can = can;
    this->x = konumX;
    this->y = konumY;

    this->yoket = &CanliYokEt;
    return this;
}

void CanliYokEt(Canli this) {
    if (this == NULL) return;
    free(this);
}
