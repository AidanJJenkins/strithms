#ifndef IN_ORDER_H
#define IN_ORDER_H
#include "../common/vec.h"
#include <stdbool.h>
#include <stddef.h>

typedef struct bt_node {
  int val;
  struct bt_node *left;
  struct bt_node *right;
} bt_node;

typedef struct {
  bt_node *root;
} tree;

vec *in_order_walk(bt_node *node, vec *path);
vec *in_order_search(bt_node *node);

vec *pre_order_walk(bt_node *node, vec *path);
vec *pre_order_search(bt_node *node);

vec *post_order_walk(bt_node *node, vec *path);
vec *post_order_search(bt_node *node);

// binary search tree
tree *create_bst();
bt_node *create_node(int value);
bool find(bt_node *node, int value);
bool Find(tree *tree, int value);
void insert(bt_node *node, int value);
void Insert(tree *tree, int value);
bt_node *delete_recursive(bt_node *root, int value);
bt_node *min_val_node(bt_node *node);
void Delete(tree *tree, int value);

#endif
