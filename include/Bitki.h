#ifndef BITKI_H
#define BITKI_H

#include <stdlib.h>
#include "Canli.h"

struct BITKI {
    Canli super;

    char (*gorunum)();
    void (*yoket)(struct BITKI*);
};
typedef struct BITKI* Bitki;

Bitki BitkiOlustur(int, int, int, int);
void BitkiYoket(Bitki);
char bitkiGorunum();

#endif
