#include "tree.h"
#include <stdio.h>

bool test_invert() {
  tree *t = create_bst();
  Insert(t, 5);
  Insert(t, 7);
  Insert(t, 3);

  bt_node *inverted = invert(t->root);
  if (inverted->right->val != 3) {
    printf("expected right val to be 3, got: %d", inverted->right->val);
    return false;
  }

  if (inverted->left->val != 7) {
    printf("expected right val to be 3, got: %d", inverted->left->val);
    return false;
  }

  return true;
}

int main() {
  bool test = test_invert();
  if (test == false) {
    return 1;
  }
  printf("Invert tree tests pass\n");
  return 0;
}
