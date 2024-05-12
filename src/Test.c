#include "Canli.h"
#include "Bitki.h"
#include "Bocek.h"
#include "Habitat.h"
#include "Sinek.h"
#include "Pire.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *dosya = fopen("doc/Veri2.txt", "r");
    int satirSayisi = 1;
    int sutunSayisi = 1;

    if (dosya == NULL) {
        printf("Dosya acma hatasi!");
        return 1;
    }

    satirVeSutunHesapla(dosya, &satirSayisi, &sutunSayisi);
    rewind(dosya);
    Habitat habitat = habitatOlustur(dosya, satirSayisi, sutunSayisi);
    habitatElemanEkle(habitat, dosya);
    habitatYazdir(habitat);
    /*habitatBaslat(habitat);*/

    return 0;
}