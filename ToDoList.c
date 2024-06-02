#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

char atividade[100][100];
int concluida[100] = {0};
int total = 0;

// Continuar
void continuar(){
    printf("\nTecle para continuar...\n");
    getch();
system("cls");
    }

// 1 - Cadastrar
void cadastar(){
    int qntAdicionar;
        printf("Quantas atividades deseja adicionar? ");
        scanf("%d", &qntAdicionar);

        for (int i = total; i < (total + qntAdicionar); i++){
            printf("Atividade %d: ", i+1);
            scanf(" %s", &atividade[i]);
        }
        total += qntAdicionar;
    continuar();
}

// 2 - Atualizar
void atualizar(){
    int numero;
        listarNaoConcluida();
        printf("\nDigite o número da atividade que deseja atualizar: ");
        scanf("%d", &numero);
    numero--;

        printf("Atualize a atividade %d: ", numero+1);
        scanf("%s",&atividade[numero]);
    continuar();
}

// 3 - Excluir
void excluir(){
    int excluir;
        listarNaoConcluida();
        listarConcluidas();
        printf("\nDigite o número da atividade que deseja excluir: ");
        scanf("%d", &excluir);

    if (excluir > 0 && excluir <= total) {
        for (int i = excluir - 1; i < total - 1; i++) {
            strcpy(atividade[i], atividade[i + 1]);
            concluida[i] = concluida[i + 1];
        }
        total--; 
            printf("Atividade %d excluída!\n", excluir);
    } else {
            printf("Número de atividade inválido!\n");
    }
    continuar();
}

// 4 - Marcar atividade como concluida
void marcarConcluida(){
    int concluir;
        listarNaoConcluida();
        printf("\nDigite o número da atividade que deseja marcar como concluída: ");
        scanf("%d", &concluir);

    if (concluir > 0 && concluir <= total) {
        concluida[concluir - 1] = 1; 
        printf("Atividade %d marcada como concluida!\n", concluir);
    } else {
        printf("Número de atividade invalido!\n");
    }
    continuar();
}

// 5 - Listar atividades concluidas
void listarNaoConcluida(){
    printf("Atividades não concluídas\n");

    for (int j = 0; j < total; j++)
    {
        if (!concluida[j])
        {
            printf("%d: %s\n", j+1, atividade[j]);
        }
    }
}

// 6 - listar atividades concluidas
void listarConcluidas(){
    printf("Atividades concluídas\n");

    for (int i = 0; i < total; ++i)
    {
        if (concluida[i])
        {
            printf("%d: %s\n", i+1, atividade[i]);
        }
    }
}

int main(void){
    setlocale (LC_ALL, "");

    int opcao;

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
            case 5: listarNaoConcluida();
                break;
            case 6: listarConcluidas();
                break;
        }
        } while(opcao != 7);

    printf("Programa encerrado!\n");
}