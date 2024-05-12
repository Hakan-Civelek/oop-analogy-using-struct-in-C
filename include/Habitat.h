#ifndef HABITAT_H
#define HABITAT_H

#include "Bitki.h"
#include "Canli.h"
#include "File.h"
#include "Bocek.h"
#include "Habitat.h"
#include "Sinek.h"
#include "Pire.h"
#include <stdio.h>
#include <stdlib.h>

struct HABITAT {
    void*** array;
    Canli kazanan;
    int satirSayisi, sutunSayisi;

};
typedef struct HABITAT* Habitat;

Habitat habitatOlustur(FILE*, int, int);
void*** bosArrayOlustur(FILE*, int, int);
void habitatElemanEkle(Habitat, FILE*);
void habitatYazdir(Habitat);
/*void habitatBaslat(Habitat);*/

#endif
