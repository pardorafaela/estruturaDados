void mostrarListaAcessos(Fila *f);
void mostrarUsuarios(Fila *f);
void mostraAposHora(Fila *f, Data *data);
void mostraAcessoUsuario(Fila *f, char nome[]);
void removerAcessos(Fila *f, int quantidade);

void mostrarListaAcessos(Fila *f)
{

    if (f->tamanho == 0)
    {
        printf("LISTA VAZIA!\n\n");
        return;
    }
    printf("--- Lista de Acessos --- \n");

    nodo *temporario = f->primeiro;

    do
    {
        printf("--------------");
        printf("\nUsuario:%s \n", temporario->elemento.nome);
        printf("Data Login:");
        imprimiData(temporario->elemento.dataLogin);
        printf("\nData Logout:");
        imprimiData(temporario->elemento.dataLogout);
        printf("--------------");
        temporario = temporario->proximo;
    } while (temporario != NULL);
}

void mostrarUsuarios(Fila *f)
{

    if (f->tamanho == 0)
    {
        printf("LISTA VAZIA!\n\n");
        return;
    }
    printf("--- Lista de Usuarios --- \n");

    nodo *temporario = f->primeiro;
    char *arrayNome[f->tamanho];
    int auxTamanho = 0;
    do
    {
        int jaExiste = 1;
        for (int i = 0; i < auxTamanho; i++)
        {
            if (strcmp(temporario->elemento.nome, arrayNome[i]) == 0)
            {
                jaExiste = 0;
            }
        }
        if (jaExiste == 1)
        {
            printf("Usuario:%s \n", temporario->elemento.nome);
            arrayNome[auxTamanho] = temporario->elemento.nome;
            auxTamanho++;
        }
        temporario = temporario->proximo;
    } while (temporario != NULL);
}

void mostraAposHora(Fila *f, Data *data)
{
    if (f->tamanho == 0)
    {
        printf("LISTA VAZIA!\n\n");
        return;
    }
    printf("--- Lista de Usuarios --- \n");

    nodo *temporario = f->primeiro;
    char *arrayNome[f->tamanho];
    int auxTamanho = 0;
    do
    {
        int jaExiste = 1;
        if (compara_data(data,temporario->elemento.dataLogin) == -1)
        {

            for (int i = 0; i < auxTamanho; i++)
            {
                if (strcmp(temporario->elemento.nome, arrayNome[i]) == 0)
                {
                    jaExiste = 0;
                }
            }
            if (jaExiste == 1)
            {
                printf("Usuario:%s \n", temporario->elemento.nome);
                arrayNome[auxTamanho] = temporario->elemento.nome;
                auxTamanho++;
            }
        }
        temporario = temporario->proximo;
    } while (temporario != NULL);
}

void mostraAcessoUsuario(Fila *f, char nome[])
{

    if (f->tamanho == 0)
    {
        printf("Nenhum Acesso!\n\n");
        return;
    }
    nodo *temporario = f->primeiro;
    int encotrou = 0;
    printf("--- Lista de Acessos pelo Usuario %s --- \n", nome);
    do
    {

        if (strcmp(temporario->elemento.nome, nome) == 0)
        {
            printf("Data Login:");
            imprimiData(temporario->elemento.dataLogin);
            printf("\nData Logout:");
            imprimiData(temporario->elemento.dataLogout);
            printf("\n");
            encotrou = 1;
        }
        temporario = temporario->proximo;
    } while (temporario != NULL);

    if (encotrou == 0)
    {
        printf("Nenhum acesso encontrado para o usuario passado.");
    }
}

void removerAcessos(Fila *f, int quantidade)
{

    for (int i = 0; i < quantidade; i++)
    {
        removeFila(f);
    }
}


Usuario *cria_usuario(char nome[], Data *login, Data *logout)
{
    Usuario *user;
    user = (Usuario *)malloc(sizeof(user));
    strcpy(user->nome,nome);
    user->dataLogin = login;
    user->dataLogout = logout;
    return user;
}
