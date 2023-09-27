#include "double_linked_list.h"

void insertion_sort(struct Node *head)
{
    struct Node *current;
    struct Node *left;
    for (current = head->next; current != NULL; current = current->next)
    {
        int temp = current->data;
        left = current->prev;
        while (left != NULL && left->data > temp)
        {
            left->next->data = left->data;
            left = left->prev;
        }
        if (left == NULL)
            head->data = temp;
        else
            left->next->data = temp;
    }
}

int main(void)
{
    struct Node *head = NULL;
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);

    printLinkedList(head);
    insertion_sort(head);
    printLinkedList(head);

    return 0;
}

/*
for(int i = 1; i < tam; i++){
    current = v[i];
    while(j < 0 && current < v[j]){
        v[j+1] = v[j];
        j--;
    }
}
 */