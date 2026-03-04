#include <stdio.h>

void torreHanoi(int n, char origem, char destino, char auxiliar){
    if (n == 1)
        return;

    torreHanoi(n-1, origem, auxiliar, destino);
    printf("Disco %d, %c -> %c\n", n, origem, destino);
    torreHanoi(n-1, auxiliar, destino, origem);
}

int main(void) {
    torreHanoi(5, 'A', 'B', 'C');
    return 0;
}