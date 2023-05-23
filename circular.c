#include <stdio.h>
#include <stdlib.h>


struct list {
  int data; 
  struct list * next;
};

typedef struct list List ;

List * create_lst() {
  return NULL; //void list
}

int void_lst(List * l) {
  return (l == NULL); // 1 if the list is not void, 0 if it's void
}

List * insert_lst (List ** l, int data) {
  List * new = (List*) malloc(sizeof(List));
  new->data = data;
  new->next = *l;
  return new;
}

void print_lst(List ** l){
  List * p;
  for(p = *l; p!=NULL; p = p->next){
    printf("info = %d", p->data);
  }
}

List * search_lst(List ** l, int target){
  List * p;
  for(p = *l; p!=NULL; p = p->next){
    if(p->data == target)
      return p; //target found
  }
  return NULL; //target not found
}

List * remove_lst(List ** l, int target){
  List * prev = NULL;
  List * p;
  if(!search_lst(l, target))
    return *l; //target not found, return the original list 
  
  if(prev == NULL){
    *l = p->next;
  }else{
    prev->next = p->next;
  }
  free(p);
  return *l;
}

void distroy_lst(List ** l){
  List * p = *l;
  while (p!=NULL){
    List * t = p->next; //store the referece of next
    free(p);
    p = t;
  }

}

int main () {
  List * l = create_lst();
  insert_lst(&l, 23);
}
