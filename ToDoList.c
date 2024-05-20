#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

char atividade[100][100];
int concluida[100] = {0};
int total = 0, i;

// 1 - Cadastrar
void cadastar(){
	printf("Quantas atividades deseja adicionar?\n");
	scanf("%d", &total);
	getchar();

	for (i = 0; i < total; i++){
	    printf("Atividade %d\n", i+1);
	    fgets(atividade[i], 100, stdin);

	}
    system("pause");
}

// 2 - Atualizar
void atualizar(){
    int numero;
    printf("Digite o número da atividade que deseja atualizar:\n");
    scanf("%d", &numero);
    numero--;
    getchar();

    printf("Atualize a atividade %d:\n", numero+1);
    fgets(atividade[numero], 100, stdin);
    printf("Atividade atualizada!\n");
    system("pause");
}

// 3 - Excluir
void excluir(){
    int numero;
    printf("Digite o número da atividade que deseja excluir:\n");
    scanf("%d", &numero);

    if (numero > 0 && numero <= total) {
        for (int i = numero - 1; i < total - 1; i++) {
            strcpy(atividade[i], atividade[i + 1]);
        }
        total--;
        printf("Atividade %d excluída!\n", numero);
    } else {
        printf("Número de atividade inválido!\n");
    }
    system("pause");
    }

// 4 - MARCAR ATIVIDADE COMO CONCLUIDA
void marcarConcluida(){
    int numero;
    printf("Digite o número da atividade que deseja marcar como concluída:\n");
    scanf("%d", &numero);

    if (numero > 0 && numero <= total) {
        concluida[numero - 1] = 1; // marca a atividade como concluida
        printf("Atividade %d marcada como concluida!\n", numero);
    } else {
        printf("Numero de atividade invalido!\n");
    }
    system("pause");
}

// 6 - listar atividades
void listarConcluidas(){
	for (int i = 0; i < total; ++i)
	{
	    if (concluida[i]) {
            printf("Atividade %d\n", i+1);
            printf("%s", atividade[i]);
	    }
	}
	system("pause");
}

int main(void){
setlocale (LC_ALL, "");

int opcao = 0;

do {
	printf("\n1 - Cadastrar atividade\n");
	printf("2 - Atualizar atividade\n");
	printf("3 - Excluir atividade\n");
	printf("4 - Marcar como concluída\n");
	printf("5 - Listar atividades que faltam ser realizadas\n");
	printf("6 - Listar atividades concluídas\n");
	printf("7 - Sair\n");

	scanf("%d", &opcao);

	switch(opcao){
		case 1: cadastar();
			break;
		case 2: atualizar();
			break;
		case 3: excluir();
			break;
		case 4: marcarConcluida();
			break;
		case 5: /*listarNaoConcluida();*/
			break;
		case 6: listarConcluidas();
			break;
	system("cls");
	}

	}

while(opcao != 7);

printf("Programa encerrado!\n");

}