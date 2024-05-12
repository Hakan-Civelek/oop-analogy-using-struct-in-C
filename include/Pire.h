#ifndef PIRE_H
#define PIRE_H

#include <stdlib.h>
#include "Bocek.h"

struct PIRE {
    Bocek super;

    char (*gorunum)();
    void (*yoket)(struct PIRE*);
};
typedef struct PIRE* Pire;

Pire PireOlustur(int, int, int, int);
void PireYoket(Pire);
char pireGorunum();

#endif
