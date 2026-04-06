#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* esquerda;
    struct No* direita;
}
