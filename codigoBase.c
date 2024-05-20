#include <stdio.h>
#include <locale.h>

int opcao;

void cadastrarAtividade(){

   setlocale(LC_ALL, "");

    int quantidade, i;
    char atividade[quantidade][100];

    printf("Quantas atividades deseja adicionar? ");
    scanf("%d", &quantidade);
    getchar();

    for (i = 1; i <= quantidade; i++)
    {
    printf("Atividade %d:", i);
    fgets(atividade[i], 100, stdin);
    }

}

void menu()
{
    printf("Lista de atividades\n");
    printf("1 - Cadastrar uma atividade\n");
    printf("2 - Atualizar atividade\n");
    printf("3 - Excluir atividade\n");
    printf("4 - Marcar como concluída\n");
    printf("5 - Listar atividades que faltam ser realizadas\n");
    printf("6 - Listar atividades concluídas\n");
    printf("\nDigite a opção escolhida:");
    scanf("%d", &opcao);
}

int main(){
    setlocale (LC_ALL, "");

    menu();

    switch (opcao)
    {
    case 1:
        cadastrarAtividade();
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    default:
        menu();
        break;
    }

}