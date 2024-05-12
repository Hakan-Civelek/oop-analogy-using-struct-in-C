#include "Bitki.h"
#include <stdlib.h>

Bitki BitkiOlustur(int tur, int can, int satir, int sutun) {
    Bitki this;
    this = (Bitki)malloc(sizeof(struct BITKI));
    this->super = CanliOlustur(tur, can, satir, sutun); // Canli yapısının kopyası oluşturuluyor
    this->super->gorunum = &bitkiGorunum; // Bitki nesnesinin gorunum fonksiyonu atanıyor
    this->gorunum = &bitkiGorunum;
    return this;
}

char bitkiGorunum() {
    return 'B';
}

void BitkiYoket(Bitki this) {
    if (this == NULL) return;
    CanliYokEt((Canli)this);
    free(this);
}
