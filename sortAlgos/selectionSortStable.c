#include "list.h"

void selectionSortStable(struct Node *head) {
  for (struct Node* current = head; current->next != NULL; current = current->next) {
    struct Node *least = current;
    for (struct Node* tail = current->next; tail != NULL; tail = tail->next) {
      if (tail->data < least->data)
        least = tail;
    }
    int temp = current->data;
    current->data = least->data;
    least->data = temp;
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
  selectionSortStable(head);
  printLinkedList(head);
  return 0;
}
