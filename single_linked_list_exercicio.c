#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int criar_list(node** head, int size);
void print_list(node* head);

int main(void)
{
    node* list = NULL;
    //passa o endereço para o pointer list
    criar_list(&list, 10);
    print_list(list);
    //para fazer: delete os ímpares e adicione o 12
    printf("\n");
    print_list(list);
}

int criar_list(node** head, int size)
{
    for(int i = 1; i <= size ; i++)
    {
        node* n = malloc(sizeof(node));
        if(n == NULL)
        {
          //checar se a memória foi alocada com sucesso
          return 1;
        }
        n -> number = i;
        //*head acessa o valor armazenado na memória apontada por node** head(pointer para a cabeça da lista), ou seja, acessa o endereço da cabeça da lista
        n -> next = *head;
        *head = n;
    }
    return 0;
}

void print_list(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        printf("%i ", temp->number);
        temp = temp->next;
    }
}
