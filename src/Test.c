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
    int satir_sayisi = 1;
    int sutun_sayisi = 1;
    if (dosya == NULL) {
        printf("Dosya acma hatasi!");
        return 1;
    }

    countRowsAndColumns(dosya, &satir_sayisi, &sutun_sayisi);

    // Dosyanın okuma konumunu başlangıç konumuna sıfırla
    rewind(dosya);

    void*** array = habitatOlustur(dosya, satir_sayisi, sutun_sayisi);

    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            int deger;
            fscanf(dosya, "%d", &deger);
            Canli canli = NULL;
            if (deger < 11)
            {
                array[i][j] = BitkiOlustur(1, deger, i, j);
            } else if (deger < 21) {
                array[i][j] = BocekOlustur(2, deger, i, j);
            } else if (deger < 51) {
                array[i][j] = SinekOlustur(3, deger, i, j);
            } else {
                array[i][j] = PireOlustur(4, deger, i, j);
            } 
        }
    }

    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            Canli* canli = array[i][j];
            if ((*canli)->tur == 1) {
                Bitki bitki = (Bitki)canli;
                printf("%c ",(*canli)->gorunum());
            } else if ((*canli)->tur == 2) {
                Bocek bocek = (Bocek)canli;
                printf("%c ",(*canli)->gorunum());
            } else {
                Canli** canli = array[i][j];
                if((**canli)->tur == 3){
                    Sinek sinek = (Sinek)canli;
                    printf("%c ", (**canli)->gorunum());
                } else if((**canli)->tur == 4){
                    Pire pire = (Pire)canli;
                    printf("%c ", (**canli)->gorunum());
                }             
            }
        }
        printf("\n");
    }

    // Array'deki her elemanın yok edilmesi
    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            BitkiYoket((Bitki)array[i][j]);
        }
    }

    return 0;
}