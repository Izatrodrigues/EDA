#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lerArquivo(const char *nomeArquivo, int vetor[], int tamanho) {
    FILE *arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("\n\nNao foi possivel abrir o arquivo.\n");
        exit(1);
    }

    int i = 0;
    while (i < tamanho && fscanf(arq, "%d", &vetor[i]) == 1) {
        i++;
    }

    fclose(arq);
    return i;
}

int encontrarMenor(const int vetor[], int tamanho) {
    int menor = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    return menor;
}

double calcularMedia(const int vetor[], int tamanho) {
    if (tamanho == 0) {
        return 0.0;
    }

    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vetor[i];
    }

    return (double)soma / tamanho;
}

int main() {
    int N;
    printf("Quantos numeros devem ser lidos do arquivo? ");
    scanf("%d", &N);

    int vetor[N];
    int qtdLida = lerArquivo("sorteio.txt", vetor, N);

    if (qtdLida != N) {
        printf("O arquivo nao possui %d numeros.\n", N);
        return 1;
    }

    int menor = encontrarMenor(vetor, N);
    double media = calcularMedia(vetor, N);

    printf("Menor elemento: %d\n", menor);
    printf("Media dos elementos: %.2lf\n", media);

    return 0;
}
