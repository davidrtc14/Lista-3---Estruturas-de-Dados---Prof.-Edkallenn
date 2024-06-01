/*
** Função: Operações com números complexos
** Autor: David Ramalho Teixeira de Carvalho
** Data: 01/06/2024
** Observações: Este programa define e manipula números complexos usando um TAD em C.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
    double real;
    double imag;
} Complexo;

Complexo* criar_complexo(double real, double imag) {
    Complexo* c = (Complexo*)malloc(sizeof(Complexo));
    if (c == NULL) {
        printf("Erro de alocação de memória.\n");
        exit(1);
    }
    c->real = real;
    c->imag = imag;
    return c;
}

void destruir_complexo(Complexo* c) {
    free(c);
}

Complexo* ler_complexo() {
    double real, imag;
    printf("Digite a parte real: ");
    scanf("%lf", &real);
    printf("Digite a parte imaginária: ");
    scanf("%lf", &imag);
    return criar_complexo(real, imag);
}

Complexo* somar_complexos(Complexo* c1, Complexo* c2) {
    return criar_complexo(c1->real + c2->real, c1->imag + c2->imag);
}

Complexo* subtrair_complexos(Complexo* c1, Complexo* c2) {
    return criar_complexo(c1->real - c2->real, c1->imag - c2->imag);
}

Complexo* multiplicar_complexos(Complexo* c1, Complexo* c2) {
    double real = c1->real * c2->real - c1->imag * c2->imag;
    double imag = c1->real * c2->imag + c1->imag * c2->real;
    return criar_complexo(real, imag);
}

Complexo* dividir_complexos(Complexo* c1, Complexo* c2) {
    double denom = c2->real * c2->real + c2->imag * c2->imag;
    if (denom == 0) {
        printf("Erro: divisão por zero.\n");
        exit(1);
    }
    double real = (c1->real * c2->real + c1->imag * c2->imag) / denom;
    double imag = (c1->imag * c2->real - c1->real * c2->imag) / denom;
    return criar_complexo(real, imag);
}

void mostrar_complexo(Complexo* c) {
    printf("(%.2f, %.2f)\n", c->real, c->imag);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Complexo *c1, *c2, *resultado;
    int opcao;

    printf("Calculadora de Números Complexos\n");
    printf("1. Criar números complexos\n");
    printf("2. Somar números complexos\n");
    printf("3. Subtrair números complexos\n");
    printf("4. Multiplicar números complexos\n");
    printf("5. Dividir números complexos\n");
    printf("6. Sair\n");

    while (1) {
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                c1 = ler_complexo();
                c2 = ler_complexo();
                printf("Números complexos criados:\n");
                mostrar_complexo(c1);
                mostrar_complexo(c2);
                break;
            case 2:
                resultado = somar_complexos(c1, c2);
                printf("Resultado da soma: ");
                mostrar_complexo(resultado);
                destruir_complexo(resultado);
                break;
            case 3:
                resultado = subtrair_complexos(c1, c2);
                printf("Resultado da subtração: ");
                mostrar_complexo(resultado);
                destruir_complexo(resultado);
                break;
            case 4:
                resultado = multiplicar_complexos(c1, c2);
                printf("Resultado da multiplicação: ");
                mostrar_complexo(resultado);
                destruir_complexo(resultado);
                break;
            case 5:
                resultado = dividir_complexos(c1, c2);
                printf("Resultado da divisão: ");
                mostrar_complexo(resultado);
                destruir_complexo(resultado);
                break;
            case 6:
                destruir_complexo(c1);
                destruir_complexo(c2);
                printf("Encerrando o programa.\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
