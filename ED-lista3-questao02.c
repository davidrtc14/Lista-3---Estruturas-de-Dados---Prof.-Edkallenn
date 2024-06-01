/*
** Função : Manipulação de registros de empregados
** Autor : David Ramalho Teixeira de Carvalho
** Data : 30/05/2024
** Observações: Este programa define e manipula registros de empregados usando uma estrutura em C.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct {
    char nome[50];
    char data_nascimento[11];
    char RG[20];
    char data_admissao[11];
    float salario;
} Empregado;

void ler_empregado(Empregado *emp) {
    printf("Nome: ");
    fgets(emp->nome, sizeof(emp->nome), stdin);
    emp->nome[strcspn(emp->nome, "\n")] = '\0'; 

    printf("Data de Nascimento (dd/mm/yyyy): ");
    fgets(emp->data_nascimento, sizeof(emp->data_nascimento), stdin);
    emp->data_nascimento[strcspn(emp->data_nascimento, "\n")] = '\0';

    printf("RG: ");
    fgets(emp->RG, sizeof(emp->RG), stdin);
    emp->RG[strcspn(emp->RG, "\n")] = '\0'; 


    printf("Data de Admissão (dd/mm/yyyy): ");
    fgets(emp->data_admissao, sizeof(emp->data_admissao), stdin);
    emp->data_admissao[strcspn(emp->data_admissao, "\n")] = '\0';

    printf("Salário: ");
    scanf("%f", &emp->salario);
    getchar(); 
}

void escrever_empregado(const Empregado *emp) {
    printf("\nNome: %s\n", emp->nome);
    printf("Data de Nascimento: %s\n", emp->data_nascimento);
    printf("RG: %s\n", emp->RG);
    printf("Data de Admissão: %s\n", emp->data_admissao);
    printf("Salário: %.2f\n", emp->salario);
}

void excluir_empregado(Empregado *emp) {
    emp->nome[0] = '\0';
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int n, i, opcao, index;
    printf("Número de empregados: ");
    scanf("%d", &n);
    getchar(); 

    Empregado *empregados = (Empregado*) malloc(n * sizeof(Empregado));

    for (i = 0; i < n; i++) {
        printf("\n--- Empregado %d ---\n", i+1);
        ler_empregado(&empregados[i]);
    }

    printf("\nLista de empregados:\n");
    for (i = 0; i < n; i++) {
        escrever_empregado(&empregados[i]);
    }

    printf("\nDeseja excluir algum empregado? (1-Sim, 0-Não): ");
    scanf("%d", &opcao);
    if (opcao == 1) {
        printf("Índice do empregado para excluir (0 a %d): ", n-1);
        scanf("%d", &index);
        if (index >= 0 && index < n) {
            excluir_empregado(&empregados[index]);
            printf("Empregado excluído.\n");
        } else {
            printf("Índice inválido.\n");
        }
    }

    printf("\nLista de empregados atualizada:\n");
    for (i = 0; i < n; i++) {
        if (empregados[i].nome[0] != '\0') {
            escrever_empregado(&empregados[i]);
        }
    }

    free(empregados);
    return 0;
}
