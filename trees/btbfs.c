#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

arr *createArr(int initialCapacity) {
  arr *a = malloc(sizeof(arr));
  a->items = (bt_node **)malloc(initialCapacity * sizeof(bt_node *));
  a->size = 0;
  a->capacity = initialCapacity;
  return a;
}
void append(arr *arr, bt_node *item) {
  if (arr->size == arr->capacity) {
    arr->capacity *= 2;
    arr->items =
        (bt_node **)realloc(arr->items, arr->capacity * sizeof(bt_node *));
  }
  arr->items[arr->size++] = item;
}

bt_node *r(arr *arr) {
  if (arr->size == 0)
    return NULL;
  bt_node *item = arr->items[0];
  for (int i = 1; i < arr->size; i++) {
    arr->items[i - 1] = arr->items[i];
  }
  arr->size--;
  return item;
}

bool btbfs(bt_node *head, int needle) {
  if (head == NULL) {
    return false;
  }

  arr *q = createArr(5);
  append(q, head);

  while (q->size > 0) {
    bt_node *curr = r(q);

    if (curr->val == needle) {
      return true;
    }

    if (curr->left) {
      append(q, curr->left);
    }

    if (curr->right) {
      append(q, curr->right);
    }
  }

  return false;
}
