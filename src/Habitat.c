#include "Habitat.h"

void*** habitatOlustur(FILE *dosya, int satir_sayisi, int sutun_sayisi) {
    void*** array = (void***)malloc(satir_sayisi * sizeof(void**));
    if (array == NULL) {
        fprintf(stderr, "Satır dizisi için bellek tahsis edilemedi!\n");
        exit(1);
    }
    for (int i = 0; i < satir_sayisi; i++) {
        array[i] = (void**)malloc(sutun_sayisi * sizeof(void*));
        if (array[i] == NULL) {
            fprintf(stderr, "Sütun dizisi için bellek tahsis edilemedi!\n");
            exit(1);
        }
        for (int j = 0; j < sutun_sayisi; j++) {
            array[i][j] = NULL; // Her elemanı NULL olarak başlat
        }
    }
    return array;
}

/*void habitatElemanEkle(FILE *dosya, void*** array, int satir_sayisi, int sutun_sayisi) {
    char deger;
    int i = 0, j = 0;
    while ((deger = fgetc(dosya)) != EOF && i < satir_sayisi && j < sutun_sayisi) {
        array[i][j] = (void*)BitkiOlustur(1, deger, i, j);
        j++;
        if (j == sutun_sayisi) {
            j = 0;
            i++;
        }
    }
}*/

/*void callGorunumMethod(void *ptr) {
    struct CANLI *canli = (struct CANLI *)ptr;
    // Assume there is a common method named 'commonMethod' in CANLI struct
    canli->gorunum();
}*/
