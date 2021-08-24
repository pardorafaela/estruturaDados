void lerData(int *data);   // OK 
int validaData(int *data); // OK
void retornaExtenso(int *data); // OK
void retornaData(int *data);   // Ok
void retornaDiaSemana(int *data); //OK
void editarData(int *data);

void somaDia(int *data);
void subtraiDia(int *data);
void printMes(int *data);

int ehBi(int *data);
int calcularDiaSemana(int *data);
int ultimoDiaMes(int *data);

char meses[12][10] = {"Janeiro","Fevereiro","Março","Abril","Maio","Junho","Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
char diaSemana[8][15] = {"Sábado","Domingo","Segunda-feira","Terça-feira","Quarta-feira","Quinta-feira","Sexta-feira"};

void lerData(int *data)
{
	printf("Digite a Data:\n\tDigite o dia(dd): ");
	scanf("%i", &data[0]);
	printf("\n\tDigite o mes(mm): ");
	scanf("%i", &data[1]);
	printf("\n\tDigite o ano(aaaa): ");
	scanf("%i", &data[2]);
    
}

int validaData(int *data)
{
	if(data[0] < 1 || data[0] > 31) return 0;
	if(data[1] < 1 || data[1] > 12) return 0;
	if(data[2] < 1500 || data[2] > 2100) return 0;
                           
    // ANO BISSEXTO - VALIDA FEVEREIRO
    if(ehBi(data)) 
    {
        if(data[1] == 2 && data[0] > 29)
        {
            return 0;
        }
    } else {
        if(data[1] == 2 && data[0] > 28)
        {
            return 0;
        }
    }

    if((data[1] == 4 || data[1] == 6 || data[1] == 9 || data[1] == 11) && data[0] > 30) 
        return 0;
      
    return 1;
}

void retornaData(int *data)
{
    printf("%d/%d/%d",data[0],data[1],data[2]);
}

void retornaExtenso(int *data)
{
    if(validaData(data) == 0) {
        printf("Data Inválida\n");
    } else {
        printf("Rio Grande, %d de %s de %d\n",data[0],meses[data[1] - 1],data[2]);
    }
}

void retornaDiaSemana(int *data)
{   
    if (validaData(data) != 0) {
        int calculo = calcularDiaSemana(data);
        printf("%02d-%02d-%d é um(a) %s\n",data[0],data[1],data[2],diaSemana[calculo]);
    }
}

void editarData(int *data)
{
    int soma = 0;
    do
    {
        printf("Deseja alterar a data? Digite um número de dias, positivos ou negativos, para alterar. Digite 0 para sair.\n");
        scanf("%d", &soma);
        if (soma > 0)
        {
            for (int i = 0; i < soma; i++)
            {
                somaDia(data);
            }
        }
        else if (soma < 0)
        {
            for (int i = soma; i < 0; i++)
            {
                subtraiDia(data);
            }
        }
        if (soma != 0)
        {
            printMes(data);
        }
    } while (soma != 0);
    
}


int ehBi(int *data)
{
    if(data[2] % 4 == 0 && (data[2] % 100 != 0 || data[2] % 400 == 0))
        return 1;
    
    return 0;
}

void somaDia(int *data)
{
    if (validaData(data))
    {
        data[0]++;
        // Se não foi possível somar para um dia válido
        if (!validaData(data))
        {
            data[0] = 1;
            // Se estamos em dezembro == ano novo
            if (data[1] == 12)
            {
                data[1] = 1;
                data[2]++;
            }
            // Se não == mês novo
            else
            {
                data[1]++;
            }
        }
    }
}

void subtraiDia(int *data)
{
    if (validaData(data))
    {
        // Se não for o primeiro dia do mês
        if (data[0] > 1)
            data[0]--;
        else
        {
            // Se não for janeiro
            if (data[1] > 1)
            {
                data[1]--;
                data[0] = ultimoDiaMes(data);
            }
            // Se for primeiro de janeiro
            else
            {
                data[2]--;
                data[1] = 12;
                data[0] = 31;
            }
            
        }
    }
}

void printMes(int *data)
{   
    // printf("%s",mes[0]);
    printf(" ---- %s de %d ----\n", meses[data[1] - 1], data[2]);
    puts("dom seg ter qua qui sex sáb");
    int ponteiroMes[3] = {1, data[1], data[2]};
    int diaSemanaPrimeiro = calcularDiaSemana(ponteiroMes);
    int diaSemana = 1;
    while(ponteiroMes[1] == data[1])
    {
        if (ponteiroMes[0] == 1)
        {
            while(diaSemanaPrimeiro != diaSemana)
            {
                printf("    ");
                diaSemana = (diaSemana+1)%7;
            }
        }
        
        printf("%2d", ponteiroMes[0]);
        if (ponteiroMes[0] == data[0]) printf("X");
        else printf(" ");
        
        if (diaSemana == 0) printf("\n");
        else printf(" ");
        diaSemana = (diaSemana+1)%7;

        somaDia(ponteiroMes);
    }
    puts("");
}

int calcularDiaSemana(int *data)
{
    int validaBi = ehBi(data) && data[1] < 3;
    // if((!data[2] % 100 == 0 && data[2] % 400 == 0) && (data[1] == 1 || data[1] == 2)) validaBi = 1;
    int vetMes[12] = {1,4,4,0,2,5,0,3,6,1,4,6};
    // Domingo1 Segunda2 Terça3 Quarta4 Quinta5 Sexta6 Sábado7
    int chaveAno = (((data[2] % 100) / 4 ) + ((data[2] % 100) % 7)) % 7;
    if(data[2] >= 2000 && data[2] <= 2099 ) chaveAno = chaveAno - 1;
    int soma = (data[0] + vetMes[data[1] - 1 ] + chaveAno) - validaBi;
    return soma - ((soma / 7) * 7);
}

int ultimoDiaMes(int *data)
{
    if (data[1] == 2)
    {
        if (ehBi(data))
             return 29;
        else return 28;
    }
    if(data[1] == 4 || data[1] == 6 || data[1] == 9 || data[1] == 11)
         return 30;
    else return 31;
}