#include "tree.h"
#include <stdbool.h>
#include <stdio.h>

bool test_minheap() {
  minheap *h = create_heap();

  heap_insert(h, 5);
  heap_insert(h, 3);
  heap_insert(h, 70);
  heap_insert(h, 500);
  heap_insert(h, 4);
  heap_insert(h, 1);
  heap_insert(h, 8);
  heap_insert(h, 7);

  if (h->length != 8) {
    return false;
  }
  int deleted;

  deleted = heap_del(h);
  if (deleted != 1) {
    printf("Expected deleted value to be 1, but got %d\n", deleted);
    return false;
  }

  deleted = heap_del(h);
  if (deleted != 3) {
    printf("Expected deleted value to be 3, but got %d\n", deleted);
    return false;
  }

  deleted = heap_del(h);
  if (deleted != 4) {
    printf("Expected deleted value to be 4, but got %d\n", deleted);
    return false;
  }

  deleted = heap_del(h);
  if (deleted != 5) {
    printf("Expected deleted value to be 5, but got %d\n", deleted);
    return false;
  }

  if (h->length != 4) {
    printf("Expected length to be 4, but got %d\n", h->length);
    return false;
  }

  deleted = heap_del(h);
  if (deleted != 7) {
    printf("Expected deleted value to be 7, but got %d\n", deleted);
    return false;
  }

  deleted = heap_del(h);
  if (deleted != 8) {
    printf("Expected deleted value to be 8, but got %d\n", deleted);
    return false;
  }

  deleted = heap_del(h);
  if (deleted != 70) {
    printf("Expected deleted value to be 70, but got %d\n", deleted);
    return false;
  }

  deleted = heap_del(h);
  if (deleted != 500) {
    printf("Expected deleted value to be 500, but got %d\n", deleted);
    return false;
  }

  if (h->length != 0) {
    printf("Expected length to be 0, but got %d\n", h->length);
    return false;
  }

  return true;
}

int main() {
  bool test = test_minheap();
  if (test == false) {
    return 1;
  }
  printf("Minheap tests pass\n");
  return 0;
}
