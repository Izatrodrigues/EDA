#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *p;
	char c;
	char nome[100];

    printf("Nome do arquivo existente: ");
    scanf("%s", nome);

	if ((p=fopen(nome, "r")) == NULL) {
		    printf("\n\nNao foi possivel abrir o arquivo.\n");
		exit(1);
	}

    printf("Qual caractere quer contar? ");
    scanf(" %c", &c);
	
	int cont = 0;
    int qtd;
    while ((qtd = fgetc(p)) != EOF) {
        if (qtd == c) {
            cont++;
        }
    }

    printf("\nExistem %d letras '%c' no arquivo", cont, c);
	fclose(p);

    return 0;
}

//Material de apoio Exemplo 03 - Aula 04.

