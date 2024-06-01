/*
** Fun��o: Ordena��o de vetor usando BubbleSort com contagem de compara��es e trocas
** Autor: David Ramalho Teixeira de Carvalho
** Data: 01/06/2024
** Observa��es: Este programa ordena elementos de um vetor usando o m�todo BubbleSort e conta o n�mero de compara��es e trocas realizadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

void bubble_sort(int vetor[], int tamanho, int *comparacoes, int *trocas) {
    int i, j, temp;
    *comparacoes = 0;
    *trocas = 0;

    for (i = 0; i < tamanho-1; i++) {
        for (j = 0; j < tamanho-i-1; j++) {
            (*comparacoes)++;
            if (vetor[j] > vetor[j+1]) {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                (*trocas)++;
            }
        }
    }
}

void imprime_vetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    srand(time(NULL));

    int tamanho, comparacoes, trocas;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int*)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro de aloca��o de mem�ria.\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }

    printf("Vetor original:\n");
    imprime_vetor(vetor, tamanho);

    bubble_sort(vetor, tamanho, &comparacoes, &trocas);

    printf("Vetor ordenado:\n");
    imprime_vetor(vetor, tamanho);

    printf("N�mero de compara��es (ifs) realizadas: %d\n", comparacoes);
    printf("N�mero de trocas realizadas: %d\n", trocas);

    free(vetor);
    return 0;
}
