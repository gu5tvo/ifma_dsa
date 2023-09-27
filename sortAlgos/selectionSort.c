#include "list.h"

struct Node* findSmallest(struct Node* head ){
  struct Node* smallest = head;

  for(struct Node* current = head; current->next != NULL; current = current->next ){
    if(current->data < smallest->data){
      smallest = current;
    }
  }
  return smallest;
}

void selectionSort(struct Node* head){
  struct Node* new;

  for(struct Node* current = head; current->next != NULL; current = current->next){
    struct Node* smallest = findSmallest(current);
    insertAtBeginning(&new, smallest->data);
  }
}

int main(void){ 
  struct Node* head = NULL;

  insertAtBeginning(&head, 2);
  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 3);
  insertAtBeginning(&head, 5);
  insertAtBeginning(&head, 4);

  printLinkedList(head);
  selectionSort(head);
  printLinkedList(head);

  return 0;
}
