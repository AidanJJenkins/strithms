#include "tree.h"
#include <stdbool.h>

bool compare_trees(bt_node *a, bt_node *b) {
  if (a == NULL && b == NULL) {
    return true;
  }

  if (a == NULL || b == NULL) {
    return false;
  }

  if (a->val != b->val) {
    return false;
  }
  return compare_trees(a->left, b->left) && compare_trees(a->right, b->right);
}
