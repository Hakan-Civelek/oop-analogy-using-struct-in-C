#include "Habitat.h"

void*** bosArrayOlustur(FILE *dosya, int satir_sayisi, int sutun_sayisi) {
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

void habitatElemanEkle(Habitat habitat, FILE *dosya) {
    char deger;
    int i = 0, j = 0;
    while ((deger = fgetc(dosya)) != EOF && i < habitat->satirSayisi && j < habitat->sutunSayisi) {
        for (int i = 0; i < habitat->satirSayisi; i++) {
            for (int j = 0; j < habitat->sutunSayisi; j++) {
                int deger;
                fscanf(dosya, "%d", &deger);
                Canli canli = NULL;
                if (deger < 11)
                {
                    habitat->array[i][j] = BitkiOlustur(1, deger, i, j);
                } else if (deger < 21) {
                    habitat->array[i][j] = BocekOlustur(2, deger, i, j);
                } else if (deger < 51) {
                    habitat->array[i][j] = SinekOlustur(3, deger, i, j);
                } else {
                    habitat->array[i][j] = PireOlustur(4, deger, i, j);
                } 
            }
        }
    }
}

Habitat habitatOlustur(FILE *dosya, int satir_sayisi, int sutun_sayisi){
    Habitat this;
    this = (Habitat)malloc(sizeof(struct HABITAT));

    this->array = bosArrayOlustur(dosya, satir_sayisi, sutun_sayisi);
    this->kazanan = NULL;
    this->satirSayisi = satir_sayisi;
    this->sutunSayisi = sutun_sayisi;

    return this;
}

void habitatYazdir(Habitat this){
    for (int i = 0; i < this->satirSayisi; i++) {
        for (int j = 0; j < this->sutunSayisi; j++) {
            Canli* canli = this->array[i][j];
            if ((*canli)->tur == 1) {
                Bitki bitki = (Bitki)canli;
                printf("%c ",(*canli)->gorunum());
            } else if ((*canli)->tur == 2) {
                Bocek bocek = (Bocek)canli;
                printf("%c ",(*canli)->gorunum());
            } else {
                Canli** canli = this->array[i][j];
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
}

/*void habitatBaslat(Habitat this){
    
    Canli* canli1 = this->array[0][0];
    for (int i = 0; i < this->satirSayisi; i++) {
        for (int j = 1; j < this->sutunSayisi; j++) {
            int can1, can2 = 0;
            char gorunum1, gorunum2;
            Canli* canli2 = this->array[i][j];

            if((*canli)->tur == 1 || (*canli)->tur == 2){
                if ((*canli)->tur == 1) {
                    gorunum1 = (*canli)->gorunum();
                } else if ((*canli)->tur == 2) {
                    Bocek bocek = (Bocek)canli;
                    printf("%c ",(*canli)->gorunum());
                }
            } else {
                Canli** canli = this->array[i][j];
                if((**canli)->tur == 3){
                    Sinek sinek = (Sinek)canli;
                    printf("%c ", (**canli)->gorunum());
                } else if((**canli)->tur == 4){
                    Pire pire = (Pire)canli;
                    printf("%c ", (**canli)->gorunum());
                }             
            }
        }
    }
}*/