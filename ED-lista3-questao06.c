/*
** Função: Cálculo da raiz quadrada usando o método de Newton-Raphson
** Autor: David Ramalho Teixeira de Carvalho
** Data: 31/05/2024
** Observações: Este programa calcula a raiz quadrada de um número n usando o método de Newton-Raphson com aproximação de 0.0001.
*/

#include <stdio.h>
#include <locale.h>

double raiz_quadrada(double n) {
    double x = n;
    double epsilon = 0.0001;
    double diferenca;

    do {
        double raiz = 0.5 * (x + n / x);
        diferenca = x - raiz;
        x = raiz;
    } while (diferenca > epsilon || diferenca < -epsilon);

    return x;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    double n;
    printf("Digite um número para calcular a raiz quadrada: ");
    scanf("%lf", &n);

    if (n < 0) {
        printf("Número inválido. Por favor, insira um número não negativo.\n");
        return 1;
    }

    double resultado = raiz_quadrada(n);
    printf("A raiz quadrada de %.4f é aproximadamente %.4f\n", n, resultado);

    return 0;
}
