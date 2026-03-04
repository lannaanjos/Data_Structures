#include <stdio.h>

/*2) Escreva um método recursivo tal que para um inteiro positivo n imprima números ímpares:
 *a. entre 1 e n
 *b. entre n e 1*/

int n_to_one(int n) {
    printf("%d\n", n);

    if (n == 1)
        return 1;

    return n_to_one(n - 1);
}
