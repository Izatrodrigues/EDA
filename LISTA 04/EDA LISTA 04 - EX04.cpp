#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *entrada, *saida;
	char c, arq1[100], arq2[100];

    printf("Nome do arquivo de entrada existente: ");
    scanf("%s", arq1);

    if ((entrada=fopen(arq1, "r")) == NULL) {
	    printf("\n\nNao foi possivel abrir o arquivo.\n");
	    exit(1);
	}	

    printf("Nomeie o arquivo de saida: ");
    scanf("%s", arq2);

	if ((saida=fopen(arq2, "w")) == NULL) {
	    printf("\n\nNao foi possivel abrir o arquivo.\n");
	    exit(1);
    }

    while ((c = fgetc(entrada)) != EOF) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            fputc('*', saida);
        } else {
            fputc(c, saida);
        }
    }

    printf("Concluido!.\n");

    fclose(entrada);
    fclose(saida);

    return 0;
}

//Material de apoio: Exemplo 2 - Aula 04.

