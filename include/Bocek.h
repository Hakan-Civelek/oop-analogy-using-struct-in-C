#ifndef BOCEK_H
#define BOCEK_H

#include <stdlib.h>
#include "Canli.h"

struct BOCEK {
    Canli super;

    char (*gorunum)();
    void (*yoket)(struct BOCEK*);
};
typedef struct BOCEK* Bocek;

Bocek BocekOlustur(int, int, int, int);
void BocekYoket(Bocek);
char bocekGorunum();

#endif
