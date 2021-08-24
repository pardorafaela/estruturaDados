#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "veiculo.h"

float faturamento = 0;

void menu(list *locados, list *veiculoLivres)
{

    int escolha;

    printf(" ***  Locadora de Veiculo ***\n 1 - Inserir Novo Veiculo \n 2 - Remover Veiculo  \n 3 - Locar Veiculo \n 4 - Devolver Veiculo \n 5 - Mostrar Veiculos Livres \n 6 - Mostrar Veiculos Locados \n 7 - Mostrar Faturamento\n Qualquer Outro Número - Sair \n");
    scanf("%i", &escolha);
    veiculo *v = (veiculo *)malloc(sizeof(veiculo));
    char placa[5];
    int retorno = 0;

    switch (escolha)
    {

    case 1:
        __fpurge(stdin);
        printf("Modelo: \n");
        fgets(v->modelo, 50, stdin);
        v->modelo[strlen(v->modelo) - 1] = '\0';

        __fpurge(stdin);

        printf("Placa: \n");
        fgets(v->placa, 10, stdin);
        v->placa[strlen(v->placa) - 1] = '\0';
        __fpurge(stdin);

        printf("Valor Diária: \n");
        scanf("%i", &v->vlDiaria);
        __fpurge(stdin);

        retorno = insereVeiculo(veiculoLivres, v);
        if (retorno)
        {
            puts("Veículo inserido com sucesso.");
        }
        else
        {
            puts("Ocorreu um erro ao inserir o veículo.");
        }

        printf("Pressione enter para continuar...");
        getchar();
        menu(locados, veiculoLivres);
        break;
    case 2:
        __fpurge(stdin);
        printf("Placa:\n");
        fgets(placa, 10, stdin);
        placa[strlen(placa) - 1] = '\0';
        __fpurge(stdin);

        if (locados->tamanho > 0)
            retorno = removeVeiculo(locados, placa);
        if (veiculoLivres->tamanho > 0)
            retorno = removeVeiculo(veiculoLivres, placa);
        
        if (retorno)
            printf("Veículo removido com sucesso.\n");
        else
            printf("Ocorreu um erro ao remover o veículo.\n");
        
        printf("Pressione enter para continuar...");
        getchar();
        menu(locados, veiculoLivres);
        break;
    case 3:
        __fpurge(stdin);
        printf("Placa:\n");
        fgets(placa, 10, stdin);
        placa[strlen(placa) - 1] = '\0';
        __fpurge(stdin);

        retorno = locaDevVeiculo(locados, veiculoLivres, placa,0);
        if (retorno != -1)
        {
            puts("Veículo locado com sucesso.");
        }
        else
        {
            puts("Ocorreu um erro ao locar o veículo.");
        }
        
        printf("Pressione enter para continuar...");
        getchar();
        menu(locados, veiculoLivres);
        break;
    case 4:
        __fpurge(stdin);
        printf("Placa:\n");
        fgets(placa, 10, stdin);
        placa[strlen(placa) - 1] = '\0';
        __fpurge(stdin);

        int qtdDiaLocado = 0;
        printf("Quantidade de Dias locado: \n");
        scanf("%d", &qtdDiaLocado);

        retorno = locaDevVeiculo(veiculoLivres, locados, placa,qtdDiaLocado);
        if (retorno != -1)
        {
            faturamento += retorno;
            puts("Veículo devolvido com sucesso.");
        }
        else
            puts("Ocorreu um erro ao devolver o veículo.");

        __fpurge(stdin);
        printf("Pressione enter para continuar...");
        getchar();
        menu(locados, veiculoLivres);
        break;
    case 5:
    
        __fpurge(stdin);
    
        printf("\n ***Veiculos LIVRES*** \n");
        mostraVeiculos(veiculoLivres);

        printf("Pressione enter para continuar...");
        getchar();
        menu(locados, veiculoLivres);
        break;
    case 6:
        printf("\n***Veiculos Locados*** \n");
        mostraVeiculos(locados);

        __fpurge(stdin);
        printf("Pressione enter para continuar...");
        getchar();
        menu(locados, veiculoLivres);
        break;
    case 7:
        mostraFaturamento(faturamento);

        __fpurge(stdin);
        printf("Pressione enter para continuar...");
        getchar();
        menu(locados, veiculoLivres);
        break;
    default:
        break;
    }
}