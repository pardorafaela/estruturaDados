#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>
#include "lde.h"
#include "busca.h"

int main()
{
    Lista *listaTelefonica = criaLista();
    Lista *listaTelefonica1 = criaLista();

    Desempenho *desempenhoBubble = (Desempenho *)malloc(sizeof(Desempenho));
    Desempenho *desempenhoQuick = (Desempenho *)malloc(sizeof(Desempenho));

    Pessoa *p1 = criaPessoa("Rafa", "991063565", 25);
    Pessoa *p2 = criaPessoa("Renata", "981202829", 25);
    Pessoa *p3 = criaPessoa("Roxane", "99165403020", 30);
    Pessoa *p4 = criaPessoa("Jaqueline", "991552313", 49);
    Pessoa *p5 = criaPessoa("Cleber", "991552330", 43);
    Pessoa *p6 = criaPessoa("Jesse", "991708065", 27);
    Pessoa *p7 = criaPessoa("Lucas", "981202848", 29);
    Pessoa *p8 = criaPessoa("Bruna", "99165402320", 23);
    Pessoa *p9 = criaPessoa("Paulo", "991552355", 28);
    Pessoa *p10 = criaPessoa("Gabriel", "991552398", 20);
    Pessoa *p11 = criaPessoa("Amanda", "991063565", 25);
    Pessoa *p12 = criaPessoa("Joana", "981202829", 25);
    Pessoa *p13 = criaPessoa("Roberta", "99165403020", 30);
    Pessoa *p14 = criaPessoa("Mauro", "991552313", 49);
    Pessoa *p15 = criaPessoa("Roberto", "991552330", 43);
    Pessoa *p16 = criaPessoa("Daiane", "991708065", 27);
    Pessoa *p17 = criaPessoa("Luciano", "981202848", 29);
    Pessoa *p18 = criaPessoa("Carlos", "99165402320", 24);
    Pessoa *p19 = criaPessoa("Cintia", "991552355", 28);
    Pessoa *p20 = criaPessoa("Paola", "991552398", 20);
    insereFim(listaTelefonica, p1);
    insereFim(listaTelefonica, p2);
    insereInicio(listaTelefonica, p3);
    insereInicio(listaTelefonica, p4);
    insereInicio(listaTelefonica, p5);
    insereFim(listaTelefonica, p6);
    insereFim(listaTelefonica, p7);
    insereInicio(listaTelefonica, p8);
    insereInicio(listaTelefonica, p9);
    insereInicio(listaTelefonica, p10);
    insereFim(listaTelefonica, p11);
    insereFim(listaTelefonica, p12);
    insereInicio(listaTelefonica, p13);
    insereInicio(listaTelefonica, p14);
    insereInicio(listaTelefonica, p15);
    insereFim(listaTelefonica, p16);
    insereFim(listaTelefonica, p17);
    insereInicio(listaTelefonica, p18);
    insereInicio(listaTelefonica, p19);
    insereInicio(listaTelefonica, p20);

    // ordenaLista(listaTelefonica);
    // mostraListaDE(listaTelefonica);
    // mostraPessoa(encontraTelefone(listaTelefonica,"991063565"));

    void menu()
    {
        int escolha;
        printf("\n ***  LISTA TELEFONICA ***\n 2 - BubbleSort  \n 3 - QuickSort\n 4 - Avaliar Desempenho \n Qualquer Outro Número - Sair \n");
        scanf("%i", &escolha);
        switch (escolha)
        {
        case 2:
            printf("\n---Lista Não Ordenada---\n\n");
            mostraListaED(listaTelefonica);

            bubbleSort(listaTelefonica, desempenhoBubble);

            printf("\n---Lista Ordenada---\n\n");

            mostraListaED(listaTelefonica);

            printf("Pressione enter para continuar...");
            getchar();
            menu();
            break;
        case 3:
            printf("\n---Lista Não Ordenada---\n\n");
            mostraListaED(listaTelefonica);
            clock_t inicia = iniciaExecucao();
            desempenhoQuick->iteracao = 0;
            quickSort(listaTelefonica->primeiro, listaTelefonica->ultimo, desempenhoQuick);
            desempenhoQuick->tempo = terminaExecucao(inicia);
            desempenhoQuick->tamanho = listaTelefonica->tamanho;
            strcpy(desempenhoQuick->metodo, "QuickSort");

            printf("\n---Lista Ordenada---\n\n");
            mostraListaED(listaTelefonica);
            printf("Pressione enter para continuar...");
            getchar();
            menu();
            break;
        case 4:
            desempenho(desempenhoBubble);
            desempenho(desempenhoQuick);
            printf("Pressione enter para continuar...");
            getchar();
            menu();
            break;
        default:
            break;
        }
    }
    menu();
}