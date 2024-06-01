/*
** Função: Verificação de números primos até N
** Autor: David Ramalho Teixeira de Carvalho
** Data: 31/05/2024
** Observações: Este programa verifica se os números de 2 até N são primos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int eh_primo(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int n;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &n);

    printf("Verificando se os números de 2 a %d são primos:\n", n);
    printf("Números primos: ");

    for (int i = 2; i <= n; i++) {
        if (eh_primo(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}
