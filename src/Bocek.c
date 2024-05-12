#include "Bocek.h"
#include <stdlib.h>

Bocek BocekOlustur(int tur, int can, int satir, int sutun) {
    Bocek this;
    
    this = (Bocek)malloc(sizeof(struct BOCEK));
    this->super = CanliOlustur(tur, can, satir, sutun);
    this->super->gorunum = &bocekGorunum;
    this->gorunum = &bocekGorunum;
    this->yoket = &BocekYoket;
    return this;
}

char bocekGorunum() {
    return 'C';
}

void BocekYoket(Bocek this) {
    if (this == NULL) return;
    CanliYokEt((Canli)this); // Canli yapısını silebilmek için Bitki yapısını Canli yapısına dönüştürüyoruz
    free(this);
}
