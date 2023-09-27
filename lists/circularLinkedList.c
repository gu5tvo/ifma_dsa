#include <stdio.h>
#include <stdlib.h>

struct list {
  int data; 
  struct list *next;
};

int arr[11];

typedef struct list List;

List *create_lst() {
  return NULL; // void list
}

int is_void_lst(List *l) {
  return (l == NULL); // 1 if the list is void, 0 if it's not void
}

List *insert_lst(List **l, int data) {
  List *new_node = (List*) malloc(sizeof(List));
  new_node->data = data;
  new_node->next = *l;
  
  if (*l == NULL) {
    new_node->next = new_node; // make the new node point to itself
  } else {
    List *last = *l;
    while (last->next != *l) {
      last = last->next;
    }
    last->next = new_node; // make the last node point to the new node
  }
  
  *l = new_node; // update the head of the list
  return new_node;
}

void print_lst(List *l) {
  List *p = l;
  if (l != NULL) {
    do {
      printf("info = %d\n", p->data);
      p = p->next;
    } while (p != l);
  }
}

List *search_lst(List *l, int target) {
  List *p = l;
  if (l != NULL) {
    do {
      if (p->data == target)
        return p; // target found
      p = p->next;
    } while (p != l);
  }
  printf("target not found");
  return NULL; // target not found
}

List *remove_lst(List **l, int target) {
  List *prev = NULL;
  List *p = *l;
  if (!search_lst(*l, target))
    return *l; // target not found, return the original list
  
  do {
    if (p->data == target) {
      if (prev == NULL) {
        *l = p->next;
      } else {
        prev->next = p->next;
      }
      
      if (p == *l) {
        *l = NULL; // the list became empty
      }
      
      free(p);
      break;
    }
    prev = p;
    p = p->next;
  } while (p != *l);
  
  return *l;
}

void destroy_lst(List **l) {
  List *p = *l;
  while (p != NULL) {
    List *t = p->next; // store the reference of the next node
    if (t == *l) {
      free(p);
      break; // avoid an infinite loop for circular lists
    }
    free(p);
    p = t;
  }
  *l = NULL; // update the head of the list
}

int main() {
  List *l = create_lst();
  insert_lst(&l, 23);
  insert_lst(&l, 42);
  insert_lst(&l, 56);
  insert_lst(&l, 78);
  
  printf("Circular List:\n");
  print_lst(l);
  
  List *found = search_lst(l, 42);
  if (found != NULL) {
    printf("Target found: %d\n", found->data);
  } else {
    printf("Target not found.\n");

  remove_lst(&l, 56);

  printf("Updated Circular List:\n");
  print_lst(l);

  destroy_lst(&l);

  return 0;
  }
}

