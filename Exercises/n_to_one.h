#include <stdio.h>

/*2) Escreva um método recursivo tal que para um inteiro positivo n imprima números ímpares:
 *a. entre 1 e n
 *b. entre n e 1*/

void n_to_one(int n) {
    printf("%d\n", n);

    if (n == 1)
        return;

    return n_to_one(n - 1);
}

void one_to_n(int n) {
    if (n == 0)
        return;

    one_to_n(n - 1);

    printf("%d\n", n);
}