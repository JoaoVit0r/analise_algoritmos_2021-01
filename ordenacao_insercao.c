#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void changePosition(int*, int*);

int main(int argc, char const* argv[]) {
    int* v, n = 10;

    if (argc > 1) {
        n = atoi(argv[argc - 1]);
    }

    v = (int*)malloc(n * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        // gerando valores aleatórios entr 0 e 100
        v[i] = rand() % 100;
        printf("%d ", v[i]);
    }

    for (int i = 1; i < n; i++) {
        // vai percorrendo para esquerda para is comparando
        for (int j = i; j > 0; j--) {
            // pegar o anterior e comparar com o atual
            if (v[j] >= v[j - 1]) {
                break;
            }
            // precisa trocar os dois
            changePosition(&v[j], &v[j - 1]);
        }
    }
    printf("\n----------\n");

    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);
    return 0;
}

void changePosition(int* ptr1, int* ptr2) {
    int aux = *ptr2;
    *ptr2 = *ptr1;
    *ptr1 = aux;
}
