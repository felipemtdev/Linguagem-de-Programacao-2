#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX 5

struct molde_funcionario {
    char nome[30];
    int idade;
    float salario;
};

int main() {
    struct molde_funcionario func[MAX];
    int n = 0;
    int i;
    int opcao = 1;

    ///////////////////// LER ARQUIVO PARA STRUCT ///////////////////
    FILE *arq = fopen("basedados.txt", "r");
    
    if (arq != NULL) {
        // Lê os dados formatados exatamente como foram salvos (Nome;Idade;Salario)
        while (n < MAX && fscanf(arq, " %29[^;];%d;%f\n", func[n].nome, &func[n].idade, &func[n].salario) == 3) {
            n++;
        }
        fclose(arq);
    }
    ////////////////////////////////////////////////////////////////

    while (opcao != 0) {
        system("cls");
        printf("===============================\n");
        printf("    SISTEMA DE FUNCIONARIOS    \n");
        printf("===============================\n\n");
        printf("MENU:\n");
        printf("1 - Incluir\n");
        printf("2 - Listar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Zerar a base de dados\n");
        printf("0 - Sair\n\n");
        
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            system("cls");
            printf("--- INCLUIR FUNCIONARIO ---\n\n");

            if (n < MAX) {
                fflush(stdin);
                printf("Digite o nome do funcionario: ");
                scanf(" %[^\n]", func[n].nome);

                printf("Digite a idade do funcionario: ");
                scanf("%d", &func[n].idade);

                printf("Digite o salario do funcionario: ");
                scanf("%f", &func[n].salario);

                n++;
                printf("\nFuncionario cadastrado com sucesso!");
            } else {
                printf("O sistema suporta no maximo %d funcionarios!", MAX);
            }

            printf("\n\nPressione qualquer tecla para continuar...");
            getch();

        } else if (opcao == 2) {
            system("cls");
            printf("--- LISTA DE FUNCIONARIOS ---\n\n");

            if (n > 0) {
                for (i = 0; i < n; i++) {
                    printf("REGISTRO [%d]\n", i + 1);
                    printf("Nome: %s\n", func[i].nome);
                    printf("Idade: %d\n", func[i].idade);
                    printf("Salario: R$ %.2f\n", func[i].salario);
                    printf("-------------------------------\n");
                }
            } else {
                printf("Nenhum funcionario cadastrado no momento.");
            }

            printf("\n\nPressione qualquer tecla para continuar...");
            getch();

        } else if (opcao == 3) {
            system("cls");
            printf("--- ALTERAR FUNCIONARIO ---\n\n");

            if (n == 0) {
                printf("Nao existem funcionarios cadastrados!");
            } else {
                for (i = 0; i < n; i++) {
                    printf("[%d] Nome: %s | Idade: %d | Salario: R$ %.2f\n", i + 1, func[i].nome, func[i].idade, func[i].salario);
                }

                int alt;
                printf("\nDigite o NUMERO do registro que deseja alterar (1 a %d): ", n);
                scanf("%d", &alt);
                alt = alt - 1; // Ajusta para índice 0 da array

                if (alt >= 0 && alt < n) {
                    fflush(stdin);
                    printf("\nDigite o NOVO nome: ");
                    scanf(" %[^\n]", func[alt].nome);

                    printf("Digite a NOVA idade: ");
                    scanf("%d", &func[alt].idade);

                    printf("Digite o NOVO salario: ");
                    scanf("%f", &func[alt].salario);

                    printf("\nFuncionario alterado com sucesso!");
                } else {
                    printf("\nNumero de registro invalido!");
                }
            }

            printf("\n\nPressione qualquer tecla para continuar...");
            getch();

        } else if (opcao == 4) {
            system("cls");
            printf("--- EXCLUIR FUNCIONARIO ---\n\n");

            if (n > 0) {
                for (i = 0; i < n; i++) {
                    printf("[%d] Nome: %s\n", i + 1, func[i].nome);
                }

                int regexcluir;
                printf("\nDigite o numero do registro a ser excluido: ");
                scanf("%d", &regexcluir);
                regexcluir = regexcluir - 1; // Ajusta índice

                if (regexcluir >= 0 && regexcluir < n) {
                    // Desloca os elementos para preencher o espaço do excluído
                    for (int p = regexcluir; p < n - 1; p++) {
                        strcpy(func[p].nome, func[p + 1].nome);
                        func[p].idade = func[p + 1].idade;
                        func[p].salario = func[p + 1].salario;
                    }
                    n--;
                    printf("\nRegistro excluido com sucesso!");
                } else {
                    printf("\nRegistro invalido!");
                }
            } else {
                printf("Nao ha registros para excluir!");
            }

            printf("\n\nPressione qualquer tecla para continuar...");
            getch();

        } else if (opcao == 5) {
            char senha[10];

            system("cls");
            printf("--- ZERAR BASE DE DADOS ---\n\n");
            printf("Digite a senha de confirmacao: ");
            scanf("%s", senha);

            if (strcmp(senha, "aaabb") == 0) {
                arq = fopen("basedados.txt", "w");
                if (arq != NULL) {
                    fclose(arq);
                }
                n = 0; // Reseta o contador da memória RAM também
                printf("\nBase de dados zerada com sucesso!");
            } else {
                printf("\nSenha incorreta!!!");
            }

            printf("\n\nPressione qualquer tecla para continuar...");
            getch();

        } else if (opcao == 0) {
            // Salva os dados de volta no arquivo ao sair
            arq = fopen("basedados.txt", "w");
            if (arq != NULL) {
                for (i = 0; i < n; i++) {
                    fprintf(arq, "%s;%d;%.2f\n", func[i].nome, func[i].idade, func[i].salario);
                }
                fclose(arq);
            }

            system("cls");
            printf("Sistema finalizado com sucesso. Dados salvos!\n");

        } else {
            printf("\nOpcao invalida...");
            printf("\n\nPressione qualquer tecla para continuar...");
            getch();
        }
    }

    return 0;
}
