/*
** Fun��o : Manipula��o de registros de aeroportos
** Autor : David Ramalho Teixeira de Carvalho
** Data : 30/05/2024
** Observa��es: Este programa define e manipula registros de aeroportos usando uma estrutura em C.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char sigla[4];
    char cidade[51];
    char pais[31];
    float taxa;
    int capacidade;
} aeroporto;

typedef aeroporto Aeroporto;

void ler_aeroporto(Aeroporto *a) {
    printf("Sigla: ");
    scanf("%3s", a->sigla);
    getchar(); 

    printf("Cidade: ");
    fgets(a->cidade, sizeof(a->cidade), stdin);
    a->cidade[strcspn(a->cidade, "\n")] = '\0'; 

    printf("Pa�s: ");
    fgets(a->pais, sizeof(a->pais), stdin);
    a->pais[strcspn(a->pais, "\n")] = '\0'; 

    printf("Taxa: ");
    scanf("%f", &a->taxa);
    getchar(); 

    printf("Capacidade: ");
    scanf("%d", &a->capacidade);
    getchar(); 
}

void escrever_aeroporto(const Aeroporto *a) {
    printf("\nSigla: %s\n", a->sigla);
    printf("Cidade: %s\n", a->cidade);
    printf("Pa�s: %s\n", a->pais);
    printf("Taxa: %.2f\n", a->taxa);
    printf("Capacidade: %d\n", a->capacidade);
}

void excluir_aeroporto(Aeroporto *a) {
    a->sigla[0] = '\0';
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    int n, i, opcao, index;
    printf("N�mero de aeroportos: ");
    scanf("%d", &n);
    getchar(); 

    Aeroporto *aeroportos = (Aeroporto*) malloc(n * sizeof(Aeroporto));

    for (i = 0; i < n; i++) {
        printf("\n--- Aeroporto %d ---\n", i+1);
        ler_aeroporto(&aeroportos[i]);
    }

    printf("\nLista de aeroportos:\n");
    for (i = 0; i < n; i++) {
        escrever_aeroporto(&aeroportos[i]);
    }

    printf("\nDeseja excluir algum aeroporto? (1-Sim, 0-N�o): ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("�ndice do aeroporto para excluir (0 a %d): ", n-1);
        scanf("%d", &index);
        if (index >= 0 && index < n) {
            excluir_aeroporto(&aeroportos[index]);
            printf("Aeroporto exclu�do.\n");
        } else {
            printf("�ndice inv�lido.\n");
        }
    }

    printf("\nLista de aeroportos atualizada:\n");
    for (i = 0; i < n; i++) {
        if (aeroportos[i].sigla[0] != '\0') {
            escrever_aeroporto(&aeroportos[i]);
        }
    }

    free(aeroportos);
    return 0;
}
