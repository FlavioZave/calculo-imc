#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

typedef struct lista {
	char nome[100];
	int idade;
	float peso;
	float altura;
}lista;

int receber_dados();
void calculo_pessoa(lista pessoa[1]);

int main () {
	setlocale(LC_ALL, "Portuguese");
	int opcao = 0;
	bool cont = true;
	
	while(cont){
		printf("|--- Faça o calculo do seu IMC! ---|\n");
		printf("Selecione uma das opções:\n");
		printf("1. Calcular IMC\n");
		printf("2. Sair\n");
		scanf("%d", &opcao);
		cont = false;
		
		switch(opcao) {
			case 1:
				receber_dados();
			break;
			case 2:
				printf("Agradecemos por utilizar nosso App!");
				cont = false;
			break;
			default:
				printf("Opção Inválida.\n");
			break;
		}
	}
}

void calculo_imc(lista pessoa[1]) {
	system("cls");
	printf("| --- Calculo do IMC ---|\n");
	float resultadoImc[1];
	
	for(int j=0;j<1;j++) {
		printf("Dados recebidos de %s\n", pessoa[j].nome);
		printf("Peso: %.2f\n", pessoa[j].peso);
		printf("Altura: %.2f\n\n", pessoa[j].altura);
		resultadoImc[j] = pessoa[j].peso/(pessoa[j].altura*pessoa[j].altura);
		printf("Resultado IMC: %.2f\n\n", resultadoImc[j]);
		
		if(resultadoImc[j]<=18.50) {
			printf("Classificação: Magreza\n");
			printf("Grau de Obesidade: 0\n\n");
		}
		else if(resultadoImc[j]>=18.51 and resultadoImc[j]<=24.90) {
			printf("Classificação: OK\n");
			printf("Grau de Obesidade: 0\n\n");
		}
		else if(resultadoImc[j]>=24.91 and resultadoImc[j]<=29.90) {
			printf("Classificação: Sobrepeso\n");
			printf("Grau de Obesidade: I\n\n");
		}
		else if(resultadoImc[j]>=29.91 and resultadoImc[j]<=39.90) {
			printf("Classificação: Obesidade\n");
			printf("Grau de Obesidade: II\n\n");
		}
		else if(resultadoImc[j]>=39.91) {
			printf("Classificação: Obesidade Grave\n");
			printf("Grau de Obesidade: III\n\n");
		}
	}
	for(int b=0;b<1;) {
		char enter;
		fflush(stdin);
		printf("\nPressione Enter para continuar...");
		enter = getchar();
		if(enter == '\n' && getchar() == '\n') {
			b++;
		}
	}
	system("cls");
}

int receber_dados() {
	system("cls");
	lista pessoa[1];
	printf("| --- Informe abaixo os seus dados! ---|\n");
	
	for(int i=0; i<1; i++) {
		fflush(stdin);
		printf("Seu nome:");
		scanf("%99[^\n]s", &pessoa[i].nome);
		fflush(stdin);
		printf("Sua idade:");
		scanf("%d", &pessoa[i].idade);
		fflush(stdin);
		printf("Seu peso:");
		scanf("%f", &pessoa[i].peso);
		fflush(stdin);
		printf("Sua altura:");
		scanf("%f", &pessoa[i].altura);
		fflush(stdin);
	}
	calculo_imc(pessoa);
	return main();
}
