
typedef struct Pessoa
{
    char nome[100];
    char telefone[20];
    int idade;
    int tamanho;
} Pessoa;

typedef struct no
{
    Pessoa elemento;
    struct no *proximo;
    struct no *anterior;
} nodo;

typedef struct Lista
{
    nodo *primeiro;
    nodo *ultimo;
    int tamanho;
} Lista;

Lista *criaLista();

Pessoa *criaPessoa(char nome[], char telefone[], int idade);

void insereFim(Lista *l, Pessoa *p);

void insereInicio(Lista *l, Pessoa *p);

void inserePosicao(Lista *l, Pessoa *p, int i);

Pessoa *removeFim(Lista *l);

Pessoa *removeInicio(Lista *l);

Pessoa *removePosicao(Lista *l, int i);

void mostraListaED(Lista *l);

void mostraListaDE(Lista *l);

void mostraPessoa(Pessoa *p);

int numeroElementos(Lista *l);

void ordenaLista(Lista *l);

void apagaListaInteira(Lista *l);

void apagaPessoa(Pessoa *p);

// ----------------------

Lista *criaLista()
{
    Lista *lista;
    lista = (Lista *)malloc(sizeof(Lista));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
    return lista;
}

Pessoa *criaPessoa(char nome[], char telefone[], int idade)
{
    Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
    strcpy(p->nome, nome);
    strcpy(p->telefone, telefone);
    p->idade = idade;
    return p;
}

void insereFim(Lista *l, Pessoa *p)
{
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    novo->proximo = NULL;
    novo->elemento = *p;
    if (l->primeiro == NULL)
    {
        l->primeiro = novo;
        l->ultimo = novo;
    }
    else
    {
        nodo *atual;
        atual = l->ultimo;
        novo->anterior = atual;
        atual->proximo = novo;
        l->ultimo = novo;
    }
    l->tamanho++;
}

void insereInicio(Lista *l, Pessoa *p)
{
    if (l == NULL)
    {
        printf("LISTA INVALIDA");
        exit(1);
    }

    nodo *novo = (nodo *)malloc(sizeof(nodo));
    if (novo == NULL)
    {
        printf("Falha ao criar um novo nodo.");
        exit(1);
    }

    novo->elemento = *p;

    if (l->primeiro == NULL)
    {
        l->primeiro = novo;
        l->ultimo = novo;
    }
    else
    {
        nodo *atual;
        atual = l->primeiro;
        novo->proximo = atual;
        atual->anterior = novo;
        l->primeiro = novo;
    }
    l->tamanho++;
}

void inserePosicao(Lista *l, Pessoa *p, int posicao)
{
    if (posicao - 1 > l->tamanho)
    {
        printf("Posição Invalida");
        exit(1);
    }
    nodo *novo = (nodo *)malloc(sizeof(nodo));
    novo->elemento = *p;
    if (l->primeiro == NULL)
    {
        insereInicio(l, p);
    }
    else
    {
        nodo *temporario = l->primeiro;

        nodo *anterior = NULL;

        for (int i = 0; i < posicao; i++)
        {
            anterior = temporario;
            temporario = temporario->proximo;
        }

        novo->proximo = temporario;
        if (anterior == NULL)
        {
            l->primeiro = novo;
        }
        else
        {
            anterior->proximo = novo;
        }
    }
    l->tamanho++;
}

Pessoa *removeFim(Lista *l)
{
    if (l->tamanho > 0)
    {

        nodo *temporario = l->ultimo;
        l->ultimo = temporario->anterior;
        l->ultimo->proximo = NULL;
        l->ultimo--;
        return &temporario->elemento;
    }
}

Pessoa *removeInicio(Lista *l)
{
    if (l->tamanho > 0)
    {
        nodo *temporario = l->primeiro;
        l->primeiro = temporario->proximo;
        l->primeiro->anterior = NULL;
        free(temporario);
        l->tamanho--;
        return &temporario->elemento;
    }
}

Pessoa *removePosicao(Lista *l, int posicao)
{
    if (posicao - 1 > l->tamanho)
    {
        printf("Posição Invalida");
        exit(1);
    }

    if (posicao == 0)
    {
        return removeInicio(l);
    }
    if (l->tamanho - 1 == posicao)
    {
        return removeFim(l);
    }
    Pessoa *rem;
    nodo *temporario = l->primeiro;
    nodo *anterior = NULL;
    for (int i = 0; i < posicao; i++)
    {
        anterior = temporario;
        temporario = temporario->proximo;
    }

    if (temporario != NULL)
    {
        if (anterior != NULL)
            anterior->proximo = temporario->proximo;
        else
            l->primeiro = temporario->proximo;

        rem = &temporario->elemento;

        free(temporario);
        l->tamanho--;
    }
    return rem;
}

void mostraListaED(Lista *l)
{
    if (l->tamanho == 0)
    {
        printf("LISTA VAZIA!\n\n");
        return;
    }
    nodo *temporario = l->primeiro;
    do
    {
        mostraPessoa(&temporario->elemento);
        temporario = temporario->proximo;
    } while (temporario != NULL);
}

void mostraListaDE(Lista *l)
{
    if (l->tamanho == 0)
    {
        printf("LISTA VAZIA!\n\n");
        return;
    }
    nodo *temporario = l->ultimo;
    do
    {
        mostraPessoa(&temporario->elemento);
        temporario = temporario->anterior;
    } while (temporario != NULL);
}

void mostraPessoa(Pessoa *p)
{
    printf("------\nNome:%s \nTelefone:%s \nIdade:%d\n", p->nome, p->telefone, p->idade);
}

int numeroElementos(Lista *l)
{
    int tamanho = 0;
    nodo *temporario = l->primeiro;
    if (temporario == NULL)
        return 0;
    do
    {
        tamanho++;
        temporario = temporario->proximo;
    } while (temporario != NULL);

    return tamanho;
}

void ordenaLista(Lista *l)
{
    nodo *n = l->primeiro;
    while (n != NULL)
    {
        nodo *n2 = n->proximo;
        while (n2 != NULL)
        {
            if (strcmp(n->elemento.nome,n2->elemento.nome) > 0 )
            {
                Pessoa aux = n->elemento;
                n->elemento = n2->elemento;
                n2->elemento = aux;
            }
            n2 = n2->proximo;
        }
        n = n->proximo;
    }
}

void apagaListaInteira(Lista *l)
{
    nodo *n = l->primeiro;
    while (n != NULL)
    {
        nodo *nvelho = n;
        n = n->proximo;
        free(nvelho);
        nvelho = NULL;
    }
    free(l);
    l = NULL;
}

void apagaPessoa(Pessoa *p)
{
    free(p);
}

Pessoa *encontraNome(Lista *l, char nome[])
{
    int posicao = 0;
    nodo *temporario = l->primeiro;
    do
    {
        if (strcmp(temporario->elemento.nome, nome) == 0)
            return &temporario->elemento;
        posicao++;
        temporario = temporario->proximo;
    } while (temporario != NULL);
}
Pessoa *encontraTelefone(Lista *l, char telefone[])
{
    int posicao = 0;
    nodo *temporario = l->primeiro;
    do
    {
        if (strcmp(temporario->elemento.telefone, telefone) == 0)
            return &temporario->elemento;
        posicao++;
        temporario = temporario->proximo;
    } while (temporario != NULL);
}


nodo *getPosicao(Lista *lista, int pos)
{
	int posicao = 0;
	nodo *temporario = lista->primeiro;
	do
	{
		if (posicao == pos)
			return temporario;
		posicao++;
		temporario = temporario->proximo;
	} while (temporario != NULL);

	return temporario;
}