#include "Pire.h"

Pire PireOlustur(int tur, int can, int satir, int sutun) {
    Pire this;
    this = (Pire)malloc(sizeof(struct PIRE));
    this->super = BocekOlustur(4, can, satir, sutun);
    this->super->super->gorunum = &pireGorunum;
    this->super->gorunum = &pireGorunum;
    this->gorunum = &pireGorunum;
    this->yoket = &PireYoket;
    return this;
}

char pireGorunum() {
    return 'P';
}

void PireYoket(Pire this) {
    if (this == NULL) return;
    CanliYokEt(this->super->super);
    BocekYoket(this->super);
    free(this);
}
