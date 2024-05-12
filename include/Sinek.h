#ifndef SINEK_H
#define SINEK_H

#include <stdlib.h>
#include "Bocek.h"

struct SINEK {
    Bocek super;
    
    char (*gorunum)();
    void (*yoket)(struct SINEK*);
};
typedef struct SINEK* Sinek;

Sinek SinekOlustur(int, int, int, int);
void SinekYoket(Sinek);
char sinekGorunum();

#endif
