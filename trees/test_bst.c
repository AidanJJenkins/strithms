#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool test_bst() {
  tree *t = create_bst();
  Insert(t, 5);
  Insert(t, 7);
  Insert(t, 9);

  if (t->root->val != 5) {
    printf("t->root expected 5, got: %d \n", t->root->val);
    return false;
  }

  if (t->root->right->val != 7) {
    printf("t->root->right expected 7, got: %d \n", t->root->right->val);
    return false;
  }

  bool found = Find(t, 7);
  if (found == false) {
    printf("expected true, got false");
  }

  Delete(t, 7);

  bool deleted = Find(t, 7);
  if (deleted != false) {
    printf("expected false, got true");
  }

  free(t);
  return true;
}

int main() {
  bool test = test_bst();
  if (test == false) {
    printf("test_bst failed");
    return 0;
  }
  printf("Binary search tree tests pass\n");
  return 0;
}
