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

    // Dosyanın okuma konumunu başlangıç konumuna sıfırla
    rewind(dosya);

    void*** array = habitatOlustur(dosya, satir_sayisi, sutun_sayisi);

    printf("Array:\n");
    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            int deger;
            fscanf(dosya, "%d", &deger); // Boşluk karakteriyle okuma yapıldı
            array[i][j] = BitkiOlustur(1, deger, i, j); // ASCII'den gerçek değere dönüşüm
            printf("Bitki gorunumu[%d][%d]: %c\n",i,j, bitkiGorunum());
            printf("can: %d\n\n", ((Bitki)array[i][j])->super->can);
        }
    }

    
    // Array'deki her elemanın yok edilmesi
    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            BitkiYoket((Bitki)array[i][j]);
        }
    }

    return 0;
}


    /*Canli* canli = array[0][0];
    (*canli)->tur == 1;
    if ((*canli)->tur == 1) {
        Bitki bitki = (Bitki)canli;
        printf("Bitki gorunumu: %c\n", bitkiGorunum());
        printf("can: %d", bitki->super->can);
    }*/
    /*printf("canli->tur: %d\n", canli->tur);
    if (canli->tur == 1) {
        Bitki bitki = (Bitki)canli;
        printf("Bitki gorunumu: %c\n", bitkiGorunum());
    }*/
