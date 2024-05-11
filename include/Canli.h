#ifndef CANLI_H
#define CANLI_H

struct CANLI {
    int can;
    int x;
    int y;
    int tur;

    void (*yoket)(struct CANLI*);
    char (*gorunum)();
};
typedef struct CANLI* Canli;

Canli CanliOlustur(int, int, int, int);
void CanliYokEt(Canli);

#endif
