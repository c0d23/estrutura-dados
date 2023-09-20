#include <stdio.h>
#include <string.h>

// Função para trocar dois elementos em um vetor de ponteiros para strings
void trocar(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Função para escolher o pivô e particionar o vetor
int particionar(char *arr[], int baixo, int alto, int *comparacoes, int *trocas) {
    char *pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        (*comparacoes)++;
        if (strcmp(arr[j], pivo) < 0) {
            i++;
            (*trocas)++;
            trocar(&arr[i], &arr[j]);
        }
    }
    (*trocas)++;
    trocar(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

// Função QuickSort
void quickSort(char *arr[], int baixo, int alto, int *comparacoes, int *trocas) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto, comparacoes, trocas);

        quickSort(arr, baixo, pi - 1, comparacoes, trocas);
        quickSort(arr, pi + 1, alto, comparacoes, trocas);
    }
}

int main() {
    char *arr[20] = {
        "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi", "cereja",
        "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };

    int comparacoes = 0;
    int trocas = 0;
    int tamanho = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("(%d) %s\n", i + 1, arr[i]);
    }

    quickSort(arr, 0, tamanho - 1, &comparacoes, &trocas);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("(%d) %s\n", i + 1, arr[i]);
    }

    printf("Número de comparações: %d\n", comparacoes);
    printf("Número de trocas: %d\n", trocas);

    return 0;
}
