#include "order.h"
#include "../common/vec.h"

vec *in_order_walk(bt_node *node, vec *path) {
  if (node == NULL) {
    return path;
  }

  path = in_order_walk(node->left, path);
  push(path, node->val);
  path = in_order_walk(node->right, path);

  return path;
}

vec *in_order_search(bt_node *node) {
  vec *v = new_vec();
  return in_order_walk(node, v);
}
