
//FUNÇÕES LISTA
list *cria_lista();
int inserirFim(list *lista, Carta c);		   // RETORNO 1 - SUCESSO 0 - ERRO
int inserirInicio(list *lista, Carta c);	   // RETORNO 1 - SUCESSO 0 - ERRO
int inserirPos(list *lista, Carta c, int pos); // RETORNO 1 - SUCESSO 0 - ERRO

int removeInicio(list *lista);		 // RETORNO 1 - SUCESSO 0 - ERRO
int removeFinal(list *lista);		 // RETORNO 1 - SUCESSO 0 - ERRO
int removePos(list *lista, int pos); // RETORNO 1 - SUCESSO 0 - ERRO

int buscaLista(list *lista, char modelo[]); // RETORNA POSIÇÃO DO ELEMENTO

int tamanhoLista(list *lista); // RETORNA A QTD DE ELEMENTOS

void mostraLista(list *lista); // mostra elementos da lista

list *cria_lista()
{
	list *lista;
	lista = (list *)malloc(sizeof(list));
	lista->primeiro = NULL;
	lista->ultimo = NULL;
	lista->tamanho = 0;
	return lista;
}

int inserirFim(list *lista, Carta c)
{
	nodo *novo = (nodo *)malloc(sizeof(nodo));
	novo->proximo = NULL;
	novo->elemento = c;
	if (tamanhoLista(lista) == 0)
	{
		return inserirInicio(lista, c);
	}
	else
	{
		lista->ultimo->proximo = novo;
	}

	lista->ultimo = novo;
	lista->tamanho++;
	return 1;
}

int inserirInicio(list *lista, Carta c)
{
	nodo *novo = (nodo *)malloc(sizeof(nodo));
	novo->proximo = NULL;
	novo->elemento = c;

	if (lista->primeiro == NULL)
	{
		lista->ultimo = novo;
	}
	else
	{
		novo->proximo = lista->primeiro;
	}

	lista->primeiro = novo;
	lista->tamanho++;
	return 1;
}

int inserirPos(list *lista, Carta c, int pos)
{
	nodo *novo = (nodo *)malloc(sizeof(nodo));
	novo->elemento = c;

	nodo *temporario = lista->primeiro;

	nodo *anterior = NULL;

	for (int i = 0; i < pos; i++)
	{
		anterior = temporario;
		temporario = temporario->proximo;
	}

	novo->proximo = temporario;
	lista->tamanho++;

	if (anterior == NULL)
	{

		lista->primeiro = novo;
		return 1;
	}
	else
	{
		anterior->proximo = novo;
		return 1;
	}

	return 0;
}

int removeInicio(list *lista)
{
	if (lista->tamanho > 0)
	{
		nodo *temporario = lista->primeiro;
		lista->primeiro = temporario->proximo;
		free(temporario);
		lista->tamanho--;
		return 1;
	}
	return 0;
}

int removeFinal(list *lista)
{
	if (lista->tamanho > 0)
	{
		free(lista->ultimo);
		lista->tamanho--;
		return 1;
	}
	return 0;
}

int removePos(list *lista, int pos)
{

	if (pos == 0)
		return removeInicio(lista);

	if (lista->tamanho - 1 == pos)
		return removeFinal(lista);

	nodo *temporario = lista->primeiro;
	nodo *anterior = NULL;
	for (int i = 0; i < pos; i++)
	{
		anterior = temporario;
		temporario = temporario->proximo;
	}

	if (temporario != NULL)
	{
		if (anterior != NULL)
			anterior->proximo = temporario->proximo;
		else
			lista->primeiro = temporario->proximo;

		free(temporario);
		lista->tamanho--;
	}
	else
		return 0;
}

int buscaLista(list *lista, char naipe[])
{
	int posicao = 0;
	nodo *temporario = lista->primeiro;
	do
	{
		if (strcmp(temporario->elemento.naipe, naipe) == 0)
		{
			return posicao;
		}

		posicao++;
		temporario = temporario->proximo;

	} while (temporario != NULL);

	return -1;
}

Carta maiorCarta(list *lista)
{
	nodo *temporario = lista->primeiro;
	int auxValor = 0;
	Carta auxCarta;
	int posicao = 0;
	int auxPosicao = 0;
	do
	{
		if (temporario->elemento.valor > auxValor)
		{
			auxValor = temporario->elemento.valor;
			auxCarta = temporario->elemento;
			auxPosicao = posicao;
		}
		posicao++;
		temporario = temporario->proximo;
	} while (temporario != NULL);
	removePos(lista, auxPosicao);
	return auxCarta;
}

Carta removeCarta(list *lista, int pos)
{
	nodo *temporario = lista->primeiro;
	int auxValor = 0;
	Carta auxCarta;
	int posicao = 0;
	do
	{
		if (posicao == pos)
		{
			auxValor = temporario->elemento.valor;
			auxCarta = temporario->elemento;
			removePos(lista, posicao);
			return auxCarta;
		}
		posicao++;
		temporario = temporario->proximo;
	} while (temporario != NULL);
}

int tamanhoLista(list *lista)
{
	int tamanho = 0;
	nodo *temporario = lista->primeiro;
	if (temporario == NULL)
		return 0;
	do
	{
		tamanho++;
		temporario = temporario->proximo;
	} while (temporario != NULL);

	return tamanho;
}

void mostraLista(list *lista)
{
	if (lista->tamanho == 0)
	{
		printf("LISTA VAZIA!\n\n");
		return;
	}

	nodo *temporario = lista->primeiro;

	do
	{
		printf("%s   %s  %d | ", temporario->elemento.naipe, temporario->elemento.simbolo, temporario->elemento.valor);
		temporario = temporario->proximo;
	} while (temporario != NULL);
}