#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *arq;
	int N;

    printf("Quantos numeros devem ser gerados? ");
    scanf("%d", &N);

	if ((arq=fopen("sorteio.txt", "w")) == NULL) {
	    printf("\n\nNao foi possivel abrir o arquivo.\n");
	    exit(1);
	}	

    srand(time(NULL));
    fprintf(arq, "%d\n", N);

    for (int i = 0; i < N; i++) {
        int numero = rand() % 101;
        fprintf(arq, "%d\n", numero);
    }
    
    printf("\nConcluido!");
    fclose(arq);

    return 0;
}
