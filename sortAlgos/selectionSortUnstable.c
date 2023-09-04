#include "list.h"

void selectionSortUnstable(struct Node *head){
  struct Node* menor;
  struct Node* current;
  for( current = head; current->next != NULL; current = current->next ) {
    struct Node* tail;
    menor = current;
    for( tail = current->next; tail != NULL; tail = tail->next ){
      if(tail->data < menor->data)
        menor = tail;
    }
    int temp = current->data;
    current->data = menor->data;
    menor->data = temp;


  }
}

int main(void){
  struct Node *head = NULL;

  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 5);
  insertAtBeginning(&head, 4);

  printLinkedList(head);
  selectionSortUnstable(head);
  printLinkedList(head);
  return 0;
}
