typedef struct carta
{
	char naipe[20];
	char simbolo[2];
	int valor;
} Carta;

typedef struct no
{
	Carta elemento;
    struct no* proximo;
    struct no* anterior; //utilizado apenas na pilha
} nodo;

typedef struct
{
	nodo *primeiro;
	nodo *ultimo;
	int tamanho;
} list;


typedef struct pilha{
   nodo *topo;
} Pilha;



