#include "Bitki.h"
#include <stdlib.h>

Bitki BitkiOlustur(int tur, int can, int konumX, int konumY) {
    Bitki this;
    this = (Bitki)malloc(sizeof(struct BITKI));
    this->super = CanliOlustur(tur, can, konumX, konumY); // Canli yapısının kopyası oluşturuluyor
    this->super->gorunum = &bitkiGorunum; // Bitki nesnesinin gorunum fonksiyonu atanıyor
    return this;
}

char bitkiGorunum() {
    return 'B';
}

void BitkiYoket(Bitki this) {
    if (this == NULL) return;
    CanliYokEt((Canli)this); // Canli yapısını silebilmek için Bitki yapısını Canli yapısına dönüştürüyoruz
    free(this);
}
