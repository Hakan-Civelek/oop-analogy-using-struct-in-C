// Bitki.h
#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"

struct BITKI {
    struct CANLI super;

    void (*yoket)(struct BITKI*);
};
typedef struct BITKI* Bitki;

Bitki BitkiOlustur(int, int, int, int);
void BitkiYoket(Bitki);
char bitkiGorunum();

#endif
