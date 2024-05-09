#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int value;
    struct node *next;
};

struct node *ultimo = NULL;
struct node *primeiro = NULL;

void enfileirar(int valor);
void desenfileirar();
void mostrarFila();
bool filaVazia();

int main()
{
    bool executa = true;
    int num;

    while (executa)
    {
        printf("Digite sua opcao: \n");
        printf("1 - Adicionar elemento a fila: \n");
        printf("2 - Mostrar Fila: \n");
        printf("3 - Remover elemento da fila: \n");
        printf("4 - Remover toda fila: \n");
        printf("5 - Sair\n");

        scanf("%d", &num);

        switch (num)
        {
        case 1:
            {
                int valor;
                printf("Digite o numero a ser adicionado: \n");
                scanf("%d", &valor);
                enfileirar(valor);
                break;
            }
        case 2:
            mostrarFila();
            break;
        case 3:
            desenfileirar();
            break;
        case 4:
            while (!filaVazia())
                desenfileirar();
            printf("Fila excluída com sucesso!");
            break;
        case 5:
            executa = false;
            break;
        default:
            printf("Opção inválida! Tente novamente!");
            break;
        }
    }

    return 0;
}

void enfileirar(int valor)
{
    struct node *novo = (struct node *)malloc(sizeof(struct node));
    if (novo == NULL)
    {
        printf("Erro ao alocar memoria!\n");
        return;
    }
    novo->value = valor;
    novo->next = NULL;
    if (filaVazia())
    {
        primeiro = novo;
        ultimo = novo;
    }
    else
    {
        ultimo->next = novo;
        ultimo = novo;
    }
    printf("Elemento %i enfileirado com sucesso\n", valor);

    getch();
    system("cls");
}

void desenfileirar()
{
    if (filaVazia())
    {
        printf("A fila esta vazia!\n");
        return;
    }
    struct node *temp = primeiro;
    primeiro = primeiro->next;
    printf("Elemento %d desenfileirado da fila.\n", temp->value);
    free(temp);
    getch();
    system("cls");
}

void mostrarFila()
{
    if (filaVazia())
    {
        printf("A fila esta vazia!\n");
        return;
    }
    struct node *temp = primeiro;
    printf("Elementos da fila:\n");
    while (temp != NULL)
    {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
    getch();
    system("cls");
}

bool filaVazia()
{
    return primeiro == NULL;
}
