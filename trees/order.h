#ifndef IN_ORDER_H
#define IN_ORDER_H
#include "../common/vec.h"
#include <stddef.h>

typedef struct bt_node {
  int val;
  struct bt_node *left;
  struct bt_node *right;
} bt_node;

vec *in_order_walk(bt_node *node, vec *path);
vec *in_order_search(bt_node *node);

vec *pre_order_walk(bt_node *node, vec *path);
vec *pre_order_search(bt_node *node);

vec *post_order_walk(bt_node *node, vec *path);
vec *post_order_search(bt_node *node);

#endif
