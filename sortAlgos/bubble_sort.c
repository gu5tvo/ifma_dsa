#include "list.h"

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


int main(void) {
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
