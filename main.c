#include <stdio.h>
#include <stdlib.h>

#include "hanoiTower.h"
#include "n_to_one.h"

int main() {
    torreHanoi(5, 'A', 'B', 'C');
    printf("\n");
    n_to_one(5);
    return 0;
}