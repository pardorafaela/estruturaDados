// Código, Modelo, Placa , valor da diária
typedef struct
{
	int cod;
	int vlDiaria;
	char modelo[50];
	char placa[10];
} veiculo;

typedef struct no
{
	veiculo elemento;
	struct no *proximo;
} nodo;

typedef struct
{
	nodo *primeiro;
	nodo *ultimo;
	int tamanho;
} list;

//FUNÇÕES LISTA
void *cria_lista();
int inserirFim(list *lista, veiculo v);					 // RETORNO 1 - SUCESSO 0 - ERRO
int inserirInicio(list *lista, veiculo v);			 // RETORNO 1 - SUCESSO 0 - ERRO
int inserirPos(list *lista, veiculo v, int pos); // RETORNO 1 - SUCESSO 0 - ERRO

int removeInicio(list *lista);			 // RETORNO 1 - SUCESSO 0 - ERRO
int removeFinal(list *lista);				 // RETORNO 1 - SUCESSO 0 - ERRO
int removePos(list *lista, int pos); // RETORNO 1 - SUCESSO 0 - ERRO

int buscaLista(list *lista, char modelo[]); // RETORNA POSIÇÃO DO ELEMENTO

int tamanhoLista(list *lista); // RETORNA A QTD DE ELEMENTOS

void mostraLista(list *lista); // mostra elementos da lista

void *cria_lista()
{
	list *lista;
	lista = (list *)malloc(sizeof(list));
	lista->primeiro = NULL;
	lista->ultimo = NULL;
	lista->tamanho = 0;
	return lista;
}

int inserirFim(list *lista, veiculo v)
{
	nodo *novo = (nodo *)malloc(sizeof(nodo));
	novo->proximo = NULL;
	novo->elemento = v;
	if (tamanhoLista(lista) == 0)
	{
		return inserirInicio(lista,v);
		
	}
	else
	{
		lista->ultimo->proximo = novo;
	}

	lista->ultimo = novo;
	lista->tamanho++;
	return 1;
}

int inserirInicio(list *lista, veiculo v)
{
	nodo *novo = (nodo *)malloc(sizeof(nodo));
	novo->proximo = NULL;
	novo->elemento = v;

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

int inserirPos(list *lista, veiculo v, int pos)
{
	nodo *novo = (nodo *)malloc(sizeof(nodo));
	novo->elemento = v;

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

int trocaLista(list *recebe,list *transfere, int pos,int qtdDiaLocado)
{

	nodo *temporario = transfere->primeiro;
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
			transfere->primeiro = temporario->proximo;


		inserirPos(recebe,temporario->elemento,recebe->tamanho);
		transfere->tamanho--;

		return qtdDiaLocado * temporario->elemento.vlDiaria;
	}
	else
		return -1;
}

int buscaLista(list *lista, char modelo[])
{
	int posicao = 0;
	nodo *temporario = lista->primeiro;
	do
	{
		if (strcmp(temporario->elemento.modelo, modelo) == 0)
			return posicao;
		posicao++;
		temporario = temporario->proximo;
	} while (temporario != NULL);

	return -1;
}
int buscaPlaca(list *lista, char placa[])
{
	int posicao = 0;
	nodo *temporario = lista->primeiro;
	do
	{
		if (strcmp(temporario->elemento.placa, placa) == 0)
			return posicao;
		posicao++;
		temporario = temporario->proximo;
	} while (temporario != NULL);


	return -1;
}

int tamanhoLista(list *lista)
{
	int tamanho = 0;
	nodo *temporario = lista->primeiro;
	if(temporario == NULL) return 0;
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

	// Código, Modelo, Placa , valor da diária
	do
	{
		printf("Código:%d \nModelo:%s \nPlaca:%s \nValor Diária:%d\n\n", temporario->elemento.cod, temporario->elemento.modelo, temporario->elemento.placa, temporario->elemento.vlDiaria);
		temporario = temporario->proximo;
	} while (temporario != NULL);
}