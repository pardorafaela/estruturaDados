#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>
#include "struct.h"
#include "lista.h"
#include "pilha.h"

// PAUS OUROS COPAS ESPAPADAS
// 1 2 3 4 5 6 7 8 9 10 Valete Dama Rei

int main()
{

    int qtdJogadores = 0;

    Pilha *baralho = cria();
    Pilha *baralhoMesa = cria();
    int partidaEmAndamento = 0;
    char naipes[4][20] = {"♣", "♦", "♥", "♠"};
    int jogadorVencedor = -1;
    int valorCarta[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    char simbolo[13][3] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    for (int np = 0; np < 4; np++)
    {
        for (int vlCarta = 0; vlCarta < 13; vlCarta++)
        {
            Carta *c = criaCarta(naipes[np], simbolo[vlCarta], valorCarta[vlCarta]);
            push(baralho, *c);
        }
    }

    while (qtdJogadores < 2)
    {
        __fpurge(stdin);
        printf("***JOGO BURRO****\n\nQual a quantidade de jogadores?\n");
        scanf("%i", &qtdJogadores);
        __fpurge(stdin);
    }

    list *jogadores[qtdJogadores];

    for (int i = 0; i < qtdJogadores; i++)
    {
        jogadores[i] = cria_lista();
    }

    printf("Embaralhando as cartas.\n\n");
    embaralha(baralho);
    printf("Distribuindo as cartas entre os jogadores para iniciar a partida automaticamente..\n\n");
    distribuiCarta(baralho, jogadores, qtdJogadores);

    push(baralhoMesa, maiorCarta(jogadores[1]));

    while (partidaEmAndamento == 0 || baralho->topo != NULL)
    {
        for (int i = 0; i < qtdJogadores; i++)
        {

            printf("\nCarta na mesa: ");
            Carta naMesa = peek(baralhoMesa);
            imprimiCarta(naMesa);
            printf("\n");

            printf("Mão do Jogador %d\n", i);
            mostraLista(jogadores[i]);
            printf("\n");

            int carta = buscaLista(jogadores[i], naMesa.naipe);

            while (carta == -1)
            {
                if(baralho->topo == NULL)
                {
                    printf("\n\nNão há mais cartas para comprar...FIM DO JOGO\n");
                    exit(1);
                }
                inserirInicio(jogadores[i], pop(baralho));
                carta = buscaLista(jogadores[i], naMesa.naipe);
            }

            push(baralhoMesa, removeCarta(jogadores[i], carta));

            if (jogadores[i]->primeiro == NULL)
            {   
                printf("Jogador de nº %d é VENCEDOR\n", i);
                exit(1);
            }
        }
    }


}