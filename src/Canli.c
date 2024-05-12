#include "Canli.h"
#include "Bocek.h"
#include "Sinek.h"
#include <stdlib.h>

Canli CanliOlustur(int tur, int can, int satir, int sutun) { 
    Canli this;
    this = (Canli)malloc(sizeof(struct CANLI));
    this->tur = tur;
    this->can = can;
    this->satir = satir;
    this->sutun = sutun;

    this->yoket = &CanliYokEt;
    return this;
}

/*int canGetir(Canli *this){

    int can = 0;
    int gorunum = ' ';
    if((*this)->tur == 1 || (*this)->tur == 2){
                if ((*this)->tur == 1) {
                    gorunum = (*this)->gorunum();
                } else if ((*this)->tur == 2) {
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
}*/

void CanliYokEt(Canli this) {
    if (this == NULL) return;
    free(this);
}
