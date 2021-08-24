#include <time.h>

Data *cria_data(int dia, int mes, int ano, int hora, int minuto, int segundo)
{
    Data *data;
    data = (Data *)malloc(sizeof(data));
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    data->hora = hora;
    data->minuto = minuto;
    data->segundo = segundo;
    return data;
}

void imprimiData(Data *data)
{

    if (data->dia < 10)
        printf("0%d/", data->dia);
    else
        printf("%d/", data->dia);
    if (data->mes < 10)
        printf("0%d/%d ", data->mes, data->ano);
    else
        printf("%d/%d ", data->mes, data->ano);

    if (data->hora < 10)
        printf("0%d:", data->hora);
    else
        printf("%d:", data->hora);

    if (data->minuto < 10)
        printf("0%d:", data->minuto);
    else
        printf("%d:", data->minuto);

    if (data->segundo < 10)
        printf("0%d\n", data->segundo);
    else
        printf("%d\n", data->segundo);

   
}

int compara_data(Data *data1, Data *data2)
{
    if (data1->ano < data2->ano)
        return -1;
    else if (data1->ano > data2->ano)
        return 1;

    if (data1->ano == data2->ano)
    {
        if (data1->mes < data2->mes)
            return -1;
        else if (data1->mes > data2->mes)
            return 1;
        else if (data1->dia < data2->dia)
            return -1;
        else if (data1->dia > data2->dia)
            return 1;
        else if (data1->hora < data2->hora)
            return -1;
        else if (data1->hora > data2->hora)
            return 1;
        else if (data1->minuto < data2->minuto)
            return -1;
        else if (data1->minuto > data2->minuto)
            return 1;
        else if (data1->segundo < data2->segundo)
            return -1;
        else if (data1->segundo > data2->segundo)
            return 1;
        else
            return 0;
    }
}
