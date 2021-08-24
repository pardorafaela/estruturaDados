

Pilha *cria()
{
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->topo = NULL;
    return pilha;
}

int push(Pilha *p, Carta carta)
{
    nodo *n = (nodo *)malloc(sizeof(nodo));
    n->elemento = carta;
    nodo *t = p->topo;
    if (t != NULL)
    {
        t->anterior = n;
    }
    n->proximo = t;
    p->topo = n;
    return 1;
}

Carta pop(Pilha *pilha)
{

    nodo *x = pilha->topo;
    if (x != NULL)
    {
        nodo *t = x->proximo;
        if (t != NULL)
        {
            t->anterior = NULL;
        }
        Carta carta = x->elemento;
        pilha->topo = t;
        free(x);
        return carta;
    }
}

int size(Pilha *pilha)
{
    nodo *x = pilha->topo;
    int tamanho = 0;
    while (x != NULL)
    {
        x = x->proximo;
        tamanho++;
    }
    return tamanho;
}

Carta peek(Pilha *pilha)
{
    if (pilha->topo != NULL)
    {
        return pilha->topo->elemento;
    }
}

void imprimir(Pilha *pilha)
{
    nodo *aux = pilha->topo;
    while (aux != NULL)
    {
        printf("%s  %s  %d  \n", aux->elemento.naipe, aux->elemento.simbolo, aux->elemento.valor);
        aux = aux->proximo;
    }
}

Carta *criaCarta(char naipe[], char simbolo[], int valor)
{
    Carta *nova = (Carta *)malloc(sizeof(Carta));

    strcpy(nova->naipe, naipe);
    strcpy(nova->simbolo, simbolo);
    nova->valor = valor;
    return nova;
}
void destroy(Pilha *pilha)
{

    while (pilha->topo != NULL)
    {
        pop(pilha);
    }
    free(pilha->topo);
}
void embaralha(Pilha *p)
{
    srand(time(NULL)); 
    int tamanho = rand()%10;
    Pilha *temporario[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        temporario[i] = cria();
    }

    while (p->topo != NULL)
    {
        push(temporario[rand() % tamanho], pop(p));
    }

    for (int x = 0; x < tamanho; x++)
    {

        while (temporario[x]->topo != NULL)
        {
            push(p, pop(temporario[x]));
        }
       
    }
}


void imprimiCarta(Carta carta)
{
    printf("%s  %s  %d  \n", carta.naipe, carta.simbolo, carta.valor);
}


void distribuiCarta(Pilha *p,list *jogadores[],int qtdJogadres)
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < qtdJogadres; j++)
        {
            Carta cartaAtual = pop(p);
            inserirInicio(jogadores[j],cartaAtual);
        }
        
    }
}
