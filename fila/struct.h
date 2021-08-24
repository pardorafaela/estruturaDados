typedef struct
{
	int dia;
	int mes;
	int ano;
	int hora;
	int minuto;
	int segundo;
} Data;



typedef struct Usuario
{
	char nome[100];
	Data *dataLogin;
	Data *dataLogout;
} Usuario;

typedef struct no
{
	Usuario elemento;
    struct no* proximo;
} nodo;

typedef struct
{
	nodo *primeiro;
	nodo *ultimo;
	int tamanho;
} Fila;




