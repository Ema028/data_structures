#include <stdio.h>
#include <stdio.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

int get_int(void);

// list aponta para o número, novo node é criado e o número é atualizado, next aponta pro mesmo lugar na memória que list e list é atualizado pra apontar para n
int main(void)
{
  node* list = NULL;
  printf("Quantos números vai ter a lista?\n");
  int list_size = get_int();
  for(int i = 0; i < list_size; i ++)
  {
    node* n = malloc(sizeof(node));
    if(n == NULL)
    {
      return 1;
    }
    printf("Número:\n");
    n -> number = get_int();
    n -> next = list;
    list = n;
    }
    return 0;
}

int get_int(void)
{
    int number;
    scanf("%i\n", &number);
    return number;
}
