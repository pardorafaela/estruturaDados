
#include "lista.h"
int serialVeiculo = 0;  // SERIAL GLOBAL
int insereVeiculo(list *veiculoLivres,veiculo *v);
int removeVeiculo(list *lista,  char placa[]);
int locaDevVeiculo(list *recebe, list *transfere, char placa[],int diasLocados);
void mostraVeiculos(list *lista);
void mostraFaturamento(float faturamento);

int insereVeiculo(list *veiculoLivres ,veiculo *v)
{
    v->cod = serialVeiculo;
    serialVeiculo++;
    return inserirFim(veiculoLivres ,*v);
};

int removeVeiculo(list *lista,  char placa[])
{
    int posPlaca = buscaPlaca(lista,placa);
    if(posPlaca != -1 ) return removePos(lista, posPlaca);
    return 0;
};

int locaDevVeiculo(list *recebe, list *transfere, char placa[],int diasLocados)
{
    int posPlaca = buscaPlaca(transfere,placa);
    if(posPlaca != -1){
        return trocaLista(recebe,transfere,posPlaca,diasLocados);
    } 
};


void mostraVeiculos(list *lista )
{
    mostraLista(lista);
};


void mostraFaturamento(float faturamento)
{
    printf("Faturamento da Loja: R$%.2f\n",faturamento);
};