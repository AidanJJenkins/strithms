#include "../../include/group_one/linkedlist.h" //
#include <stdlib.h>

void reverse_i(List *l) {
  if (l == NULL || l->head == NULL || l->head->next == NULL) {
    return;
  }

  Node *prev = NULL;
  Node *curr = l->head;
  Node *next = NULL;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  l->head = prev;
}
