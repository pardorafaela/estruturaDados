
Fila *cria_fila();

int inserir(Fila *fila, Usuario *p);

int removeFila(Fila *fila);

int busca(Fila *fila, char cpf[]);

int getTotalElementos(Fila *fila);

// void mostra(Fila *fila);

int ehVazia(Fila *fila);

Fila *cria_fila()
{
	Fila *fila;
	fila = (Fila *)malloc(sizeof(fila));
	fila->primeiro = NULL;
	fila->ultimo = NULL;
	fila->tamanho = 0;
	return fila;
}

int inserir(Fila *fila, Usuario *p)
{
	nodo *novo = (nodo *)malloc(sizeof(nodo));
	novo->proximo = NULL;
	novo->elemento = *p;
	if (fila->tamanho == 0)
	{
		if (fila->primeiro == NULL)
		{
			fila->ultimo = novo;
		}
		else
		{
			novo->proximo = fila->primeiro;
		}

		fila->primeiro = novo;
		fila->tamanho++;
		return 1;
	}
	else
	{
		fila->ultimo->proximo = novo;
	}

	fila->ultimo = novo;
	fila->tamanho++;
	return 1;
}

int removeFila(Fila *fila)
{
	if (fila->tamanho > 0)
	{
		nodo *temporario = fila->primeiro;
		fila->primeiro = temporario->proximo;
		free(temporario);
		fila->tamanho--;
		return 1;
	} else printf("Fila Vázia");
	return 0;
}

int busca(Fila *fila, char nome[])
{
	int posicao = 0;
	nodo *temporario = fila->primeiro;
	do
	{
		if (strcmp(temporario->elemento.nome, nome) == 0)
		{
			return posicao;
		}

		posicao++;
		temporario = temporario->proximo;

	} while (temporario != NULL);

	return -1;
}

int getTotalElementos(Fila *fila)
{
	int tamanho = 0;
	nodo *temporario = fila->primeiro;
	if (temporario == NULL)
		return 0;
	do
	{
		tamanho++;
		temporario = temporario->proximo;
	} while (temporario != NULL);

	return tamanho;
}

int ehVazia(Fila *fila)
{
	int tamanho = 0;
	nodo *temporario = fila->primeiro;
	if (temporario == NULL)
		return 0;

	return -1;
}
