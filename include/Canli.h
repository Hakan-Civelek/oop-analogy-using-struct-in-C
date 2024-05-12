#ifndef CANLI_H
#define CANLI_H

#include <stdio.h>
#include <stdlib.h>

struct CANLI {
    int can;
    int satir;
    int sutun;
    int tur;

    void (*yoket)(struct CANLI*);
    char (*gorunum)();
};
typedef struct CANLI* Canli;

Canli CanliOlustur(int, int, int, int);
void CanliYokEt(Canli);

#endif
