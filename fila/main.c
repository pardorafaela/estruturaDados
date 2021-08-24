#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>
#include "struct.h"
#include "fila.h"
#include "data.h"
#include "acesso.h"
void menu();
int main()
{

    int escolha;
    int quantidade;
    Data *dt;
    int data[6];

    Fila *filaAcessos = cria_fila();
    char usuario[100];

    Usuario *user1 = cria_usuario("Rafaela", cria_data(10, 12, 2020, 23, 59, 00), cria_data(11, 12, 2020, 22, 00, 00));
    Usuario *user2 = cria_usuario("Renata", cria_data(11, 12, 2020, 22, 59, 00), cria_data(12, 12, 2020, 23, 00, 00));
    Usuario *user3 = cria_usuario("Roxane", cria_data(12, 12, 2020, 20, 59, 00), cria_data(13, 12, 2020, 19, 00, 00));
    Usuario *user4 = cria_usuario("Fred", cria_data(13, 12, 2020, 21, 59, 00), cria_data(14, 12, 2020, 20, 00, 00));
    Usuario *user5 = cria_usuario("Ada", cria_data(9, 12, 2020, 22, 59, 00), cria_data(15, 12, 2020, 18, 00, 00));
    Usuario *user6 = cria_usuario("Ada", cria_data(9, 12, 2020, 22, 59, 00), cria_data(15, 12, 2020, 18, 00, 00));

    inserir(filaAcessos, user1);
    inserir(filaAcessos, user2);
    inserir(filaAcessos, user3);
    inserir(filaAcessos, user4);
    inserir(filaAcessos, user4);
    inserir(filaAcessos, user5);
   
    void menu()
    {
        printf(" ***  ADMIN USERS ***\n 1 - Mostrar Acessos \n 2 - Mostrar Usuarios  \n 3 - Acesso após uma hora \n 4 - Mostrar Acessos Por Usuario \n 5 - Remover Acessos \n Qualquer Outro Número - Sair \n");
        scanf("%i", &escolha);
        switch (escolha)
        {
        case 1:
            mostrarListaAcessos(filaAcessos);
            printf("Pressione enter para continuar...\n");
            getchar();
            menu();
            break;
        case 2:
            mostrarUsuarios(filaAcessos);
            printf("Pressione enter para continuar...\n");
            getchar();
            menu();
            break;
        case 3:
            printf("Digite a Data:\n\tDigite o dia(dd): ");
            scanf("%i", &data[0]);
            printf("\n\tDigite o mes(mm): ");
            scanf("%i", &data[1]);
            printf("\n\tDigite o ano(aaaa): ");
            scanf("%i", &data[2]);
            printf("\n\tDigite a hora(HH): ");
            scanf("%i", &data[3]);
            printf("\n\tDigite o minuto(MM): ");
            scanf("%i", &data[4]);
            printf("\n\tDigite os segundos(SS): ");
            scanf("%i", &data[5]);

            dt = cria_data(data[0], data[1], data[2], data[3], data[4], data[5]);
            mostraAposHora(filaAcessos, dt);

            printf("Pressione enter para continuar...\n");
            getchar();
            menu();
            break;
        case 4:
            __fpurge(stdin);
            printf("Nome Usuario:\n");
            fgets(usuario, 100, stdin);
            usuario[strlen(usuario) - 1] = '\0';
            __fpurge(stdin);
            mostraAcessoUsuario(filaAcessos, usuario);
            printf("Pressione enter para continuar...\n");
            getchar();
            menu();
            break;
        case 5:
            printf("Quantidade de Acessos para remover?\n");
            scanf("%i", &quantidade);
            removerAcessos(filaAcessos, quantidade);
            printf("Pressione enter para continuar...\n");
            getchar();
            menu();
            break;
        default:
            break;
        }
    }
     menu();
}