#include "list.h"


void selectionSortUnstable(struct Node *head) {
  for (struct Node *current = head; current->next != NULL;
       current = current->next) {
    struct Node *min = current;
    for (struct Node* tail = current->next; tail != NULL; tail = tail->next) {
      if (tail->data < min->data) {
        int temp = tail->data;
        tail->data = min->data;
        min->data = temp;
      }
    }
  }
}
int main(void) {

  struct Node *head = NULL;

  insertAtBeginning(&head, 1);
  insertAtBeginning(&head, 0);
  insertAtBeginning(&head, 100);
  insertAtBeginning(&head, 20);
  insertAtBeginning(&head, 43);
  insertAtBeginning(&head, 13);
  insertAtBeginning(&head, 78);
  insertAtBeginning(&head, 90);
  insertAtBeginning(&head, 3);
  printLinkedList(head);
  selectionSortUnstable(head);
  printLinkedList(head);
  return 0;
}
