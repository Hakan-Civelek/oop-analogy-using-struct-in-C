#include "Sinek.h"

Sinek SinekOlustur(int tur, int can, int satir, int sutun) {
    Sinek this;
    this = (Sinek)malloc(sizeof(struct SINEK));
    this->super = BocekOlustur(3, can, satir, sutun);
    this->super->super->gorunum = &sinekGorunum;
    this->super->gorunum = &sinekGorunum;
    this->gorunum = &sinekGorunum;
    this->yoket = &SinekYoket;
    return this;
}

char sinekGorunum() {
    return 'S';
}

void SinekYoket(Sinek this) {
    if (this == NULL) return;
    CanliYokEt(this->super->super);
    BocekYoket(this->super);
    free(this);
}
