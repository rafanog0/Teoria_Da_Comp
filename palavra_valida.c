#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define VALIDO 1
#define INVALIDO -1


typedef struct no
{
    char id;
    char vai;
    char volta;
    struct no *prox;
    struct no *anterior;
} No;

typedef struct head
{
    No *inicio;
    No *fim;
} head;

head* cria_lista()
{
    head *novo = (head*)malloc(sizeof(head));
    No *R = (No*)malloc(sizeof(No));
    R->vai = 'a';
    R->volta = 'b';
    R->id = 'R';
    No *S = (No*)malloc(sizeof(No));
    S->vai = 'b';
    S->volta = 'a';
    S->id = 'S';
    No *T = (No*)malloc(sizeof(No));
    T->vai = 'a';
    T->volta = 'b';
    T->id = 'T';

    No *U = (No*)malloc(sizeof(No));
    U->vai = 'b';
    U->volta = 'a';
    U->id = 'U';

    R->prox = S;
    R->anterior = U;
    S->prox = T;
    S->anterior = R;
    T->prox = U;
    T->anterior = S;
    U->prox = R;
    U->anterior = T;

    novo->inicio = R;
    novo->fim = R;
    return novo;
}

int checa_palavra(head *lista, char palavra[], char *resposta)
{
    No *aux = lista->inicio;
    int i = 0;
    while(palavra[i] != '\0')
    {
        if(palavra[i] == 'a')
        {
            if(aux->vai == 'a')
            {   
                resposta[i] = aux->id;
                aux = aux->prox;
            }
            else if(aux->volta == 'a')
            {   
                resposta[i] = aux->id;
                aux = aux->anterior;
            }

            else
                return INVALIDO;
        }
        else if(palavra[i] == 'b')
        {
            if(aux->vai == 'b')
            {
                resposta[i] = aux->id;
                aux = aux->prox;
            }
            else if(aux->volta == 'b')
            {
                resposta[i] = aux->id;
                aux = aux->anterior;
            }
            else
                return INVALIDO;
        }
        i++;
    }
    if(aux == lista->fim)
    {
        resposta[i] = aux->id;
        return VALIDO;
    }
    return INVALIDO;
}

int verifica_entrada(char palavra[])
{
    int i = 0;
    while(palavra[i] != '\0')
    {
        if(palavra[i] != 'a' && palavra[i] != 'b')
            return INVALIDO;
        i++;
    }
    return VALIDO;
}


int main()
{
    char palavra_recebida[50];
    char resposta[50];
    memset(resposta, '\0', sizeof(char)*50);


    head *lista = cria_lista();
    while(1)
    {
        printf("Digite a palavra: use 'a' ou 'b'\n");
        scanf("%s", palavra_recebida);
        if(verifica_entrada(palavra_recebida) == INVALIDO)
        {
            printf("Saindo do programa.\n");
            break;
        }
        else if(checa_palavra(lista, palavra_recebida, resposta) > 0)
            printf("\n\n**Palavra valida**\nCaminho: %s\n\n", resposta);
        else
            printf("\n\n**Palavra invalida**\n\n");
    }

    return 0;
}
