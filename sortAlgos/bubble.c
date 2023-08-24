#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL)
  {
    perror("Erro na alocação de memória para o novo nó");
    exit(EXIT_FAILURE);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void insertAtBeginning(struct Node **head, int data)
{
  struct Node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
}

void printLinkedList(struct Node *head)
{
  struct Node *current = head;
  while (current != NULL)
  {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

void freeLinkedList(struct Node *head)
{
  struct Node *current = head;
  while (current != NULL)
  {
    struct Node *temp = current;
    current = current->next;
    free(temp);
  }
}

void bubble(struct Node *head){
  while(1){
    int swapped = 0;
    struct Node* current;
    for(current = head; current->next != NULL; current = current->next){
      if(current->data > current->next->data){
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;
        swapped = 1;
      }
    }
    if(!swapped)
      break;
  }
}


int main()
{
  struct Node *head = NULL;

  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 5);
  insertAtBeginning(&head, 4);

  printLinkedList(head);
  bubble(head);
  printLinkedList(head);

  return 0;
}
