// main.c
#include "Bitki.h"
#include "Canli.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Bitki bitki = BitkiOlustur(1, 100, 0, 0);
    printf("Bitki gorunumu: %c\n", bitki->super.gorunum());
    BitkiYoket(bitki);
    return 0;
}
