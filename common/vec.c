#include "vec.h"
#include <stdio.h>
#include <stdlib.h>

vec *new_vec() {
  vec *v = malloc(sizeof(vec));
  v->count = 0;
  v->capacity = 4;
  v->items = (int *)malloc(v->capacity * sizeof(int));

  return v;
}

void resize_vec(vec *arr) {
  arr->capacity *= 2;
  int *new_items = (int *)realloc(arr->items, arr->capacity * sizeof(int));
  if (new_items == NULL) {
    perror("Failed to reallocate memory for vector items");
    free(arr->items);
    free(arr);
    exit(EXIT_FAILURE);
  }
  arr->items = new_items;
}

void push(vec *arr, int item) {
  if (arr->count == arr->capacity) {
    resize_vec(arr);
  }
  arr->count++;
  arr->items[arr->count - 1] = item;
}

int pop(vec *arr) {
  if (arr->count == 0) {
    fprintf(stderr, "Error: Cannot pop from an empty vector\n");
    exit(EXIT_FAILURE);
  }
  int item = arr->items[0];
  for (size_t i = 1; i < arr->count; ++i) {
    arr->items[i - 1] = arr->items[i];
  }
  arr->count--;
  return item;
}

void del_vec(vec *arr) {
  free(arr->items);
  free(arr);
}
