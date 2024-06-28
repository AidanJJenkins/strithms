#include "tree.h"
#include <stdlib.h>

bt_node *invert(bt_node *root) {
  if (root != NULL) {
    bt_node *temp;
    temp = invert(root->right);
    root->right = invert(root->left);
    root->left = temp;
  }
  return root;
}
