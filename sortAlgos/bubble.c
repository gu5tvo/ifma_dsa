#include <stdio.h>
#include <stdlib.h>

// Definindo a estrutura do nó da linked list
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Erro na alocação de memória para o novo nó");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

void bubble(struct Node* head){
  for(struct Node* current = head; current->next == NULL; current = current->next){
    for(struct Node* current2 = head; current2->next == NULL; current2 = current2->next){
      if(current2->data > current2->next->data){
        struct Node* temp = current2;
        current2 = current2->next;
        current2->next = temp;
      }
    }

  }
}

int main() {
    struct Node* head = NULL;

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
