#include "Canli.h"
#include <stdlib.h>

Canli CanliOlustur(int tur, int can, int satir, int sutun) {
    Canli this;
    this = (Canli)malloc(sizeof(struct CANLI));
    this->tur = tur;
    this->can = can;
    this->satir = satir;
    this->sutun = sutun;

    this->yoket = &CanliYokEt;
    return this;
}

void CanliYokEt(Canli this) {
    if (this == NULL) return;
    free(this);
}
