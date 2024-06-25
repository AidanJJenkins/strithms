#include "../common/vec.h"
#include "tree.h"

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

vec *pre_order_walk(bt_node *node, vec *path) {
  if (node == NULL) {
    return path;
  }

  push(path, node->val);
  path = pre_order_walk(node->left, path);
  path = pre_order_walk(node->right, path);

  return path;
}

vec *pre_order_search(bt_node *node) {
  vec *v = new_vec();
  return pre_order_walk(node, v);
}

vec *post_order_walk(bt_node *node, vec *path) {
  if (node == NULL) {
    return path;
  }

  path = post_order_walk(node->left, path);
  path = post_order_walk(node->right, path);
  push(path, node->val);

  return path;
}

vec *post_order_search(bt_node *node) {
  vec *v = new_vec();
  return post_order_walk(node, v);
}
