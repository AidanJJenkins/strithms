#include "../../include/group_one/vec.h"
#include <stdlib.h>

vec *new_vec() {
  vec *arr = (vec *)malloc(sizeof(vec));

  arr->items = (int *)malloc(sizeof(int));
  if (arr->items == NULL) {
    free(arr);
    return NULL;
  }

  arr->count = 0;
  arr->capacity = 0;
  return arr;
}

void resize_vec(vec *arr) {
  if (arr->count >= arr->capacity) {
    if (arr->capacity == 0) {
      arr->capacity = 256;
    } else {
      size_t new_capacity = arr->capacity * 2;
      void *ptr = realloc(arr->items, new_capacity * sizeof(int));

      if (ptr == NULL) {
        return;
      }

      arr->items = (int *)ptr;
      arr->capacity = new_capacity;
    }
  } else {
    return;
  }
}

void push(vec *arr, int item) {
  arr->count++;
  resize_vec(arr);

  arr->items[arr->count] = item;
}

int pop(vec *arr) {
  if (arr->count == 0) {
    return -1;
  }

  int removed_element = arr->items[0];

  for (int i = 1; i < arr->count; i++) {
    arr->items[i - 1] = arr->items[i];
  }

  arr->count--;
  return removed_element;
}

int get_at(vec *arr, int idx) {
  if (idx < 0 || idx >= arr->count) {
    return -1;
  }

  return arr->items[idx];
}

void del_vec(vec *arr) {
  free(arr->items);
  free(arr);
}

void delete_at(vec *arr, int index) {
  if (arr->count == 0 || index < 0 || index >= arr->count) {
    // Handle invalid index or empty array (optional: print error message)
    return;
  }

  // Store the element to be removed (optional, for potential use later)
  int removed_element = arr->items[index];

  // Shift elements to the left, overwriting the element at the given index
  for (int i = index + 1; i < arr->count; i++) {
    arr->items[i - 1] = arr->items[i];
  }

  arr->count--; // Decrement size to reflect removal
}
