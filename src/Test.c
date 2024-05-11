#include "Bitki.h"
#include "Canli.h"
#include "Habitat.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *dosya = fopen("doc/Veri2.txt", "r");
    int satir_sayisi = 1;
    int sutun_sayisi = 1;
    if (dosya == NULL) {
        printf("Dosya acma hatasi!");
        return 1;
    }

    countRowsAndColumns(dosya, &satir_sayisi, &sutun_sayisi);

    void*** array = habitatOlustur(dosya, satir_sayisi, sutun_sayisi);

    array[0][0] = BitkiOlustur(1, 100, 2, 3);

    Canli* canli = array[0][0];
    (*canli)->tur == 1;
    if ((*canli)->tur == 1) {
        Bitki bitki = (Bitki)canli;
        printf("Bitki gorunumu: %c\n", bitkiGorunum());
        printf("can: %d", bitki->super->can);
    }
    /*printf("canli->tur: %d\n", canli->tur);
    if (canli->tur == 1) {
        Bitki bitki = (Bitki)canli;
        printf("Bitki gorunumu: %c\n", bitkiGorunum());
    }*/

    BitkiYoket((Bitki)array[0][0]);
    return 0;
}
