#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calendario.h"

int main()
{

    int data[3];
    lerData(data);
    if (validaData(data) == 0)
    {
        printf("Data Inválida\n");
        exit(1);
    }
    retornaExtenso(data);
    retornaDiaSemana(data);
    printMes(data);
    editarData(data);
}