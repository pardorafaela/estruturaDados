
clock_t iniciaExecucao()
{
    clock_t inicia = clock();
    return inicia;
}

double terminaExecucao(clock_t inicia)
{
    clock_t termina = clock();
    return ((double)(termina - inicia) / (CLOCKS_PER_SEC / 1000));
}

void bubbleSort(Lista *l,Desempenho *desempenho)
{
    clock_t inicia = iniciaExecucao();
    desempenho->iteracao = 0;
    nodo *proximo, *atual;
    for (int i = 0; i < l->tamanho - 1; i++)
    {
        atual = l->primeiro;
        proximo = atual->proximo;
        for (int j = 0; j < l->tamanho - 1; j++)
        {
            if (proximo->elemento.idade < atual->elemento.idade)
            {
                Pessoa aux = proximo->elemento;
                proximo->elemento = atual->elemento;
                atual->elemento = aux;
            }
            if (atual->proximo != NULL && proximo->proximo != NULL)
            {
                atual = atual->proximo;
                proximo = proximo->proximo;
            }
            desempenho->iteracao++;
        }
    }

    desempenho->tempo = terminaExecucao(inicia);
    desempenho->tamanho = l->tamanho;
    strcpy(desempenho->metodo,"BubbleSort");
}

void quickSort(nodo *primeiro, nodo *ultimo,Desempenho *desempenho)
{
    if (ultimo != NULL && primeiro != ultimo && primeiro != ultimo->proximo)
    {
        Pessoa el = ultimo->elemento;

        nodo *i = primeiro->anterior;

        for (nodo *j = primeiro; j != ultimo; j = j->proximo)
        {
            if (j->elemento.idade <= el.idade)
            {

                if (i == NULL)
                    i = primeiro;
                else
                    i = i->proximo;

                Pessoa t = i->elemento;
                i->elemento = j->elemento;
                j->elemento = t;
            }
            desempenho->iteracao++;
        }
        
        if (i == NULL)
            i = primeiro;
        else
            i = i->proximo;

        Pessoa t1 = i->elemento;
        i->elemento = ultimo->elemento;
        ultimo->elemento = t1;

        quickSort(primeiro, i->anterior,desempenho);
        quickSort(i->proximo, ultimo,desempenho);
    }
}

void desempenho(Desempenho *desempenho)
{
    printf("--- %s ---\n   Iterações: %d\n   Tamanho Lista:%d\n   Tempo De Execução:%f\n---------------\n\n",desempenho->metodo, desempenho->iteracao,desempenho->tamanho, desempenho->tempo);

}
