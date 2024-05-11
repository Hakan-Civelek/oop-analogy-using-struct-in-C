#include "File.h"

void countRowsAndColumns(FILE *dosya, int *satir_sayisi, int *sutun_sayisi) {
    if (dosya == NULL) {
        printf("Dosya açma hatasi!");
    }

    char karakter;
    int newLineCheck = 0;
    while ((karakter = fgetc(dosya)) != EOF) {
        if (karakter == '\n') {
            newLineCheck = 1;
            (*satir_sayisi)++;
        }
        if (newLineCheck == 0 && karakter == ' ') {
            (*sutun_sayisi)++;
        }
    }
}