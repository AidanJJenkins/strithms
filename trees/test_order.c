#include "tree.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

bt_node *create_tree() {
  bt_node *root = malloc(sizeof(bt_node));
  root->val = 20;

  root->left = malloc(sizeof(bt_node));
  root->left->val = 10;
  root->left->left = malloc(sizeof(bt_node));
  root->left->left->val = 5;
  root->left->left->left = NULL;
  root->left->left->right = malloc(sizeof(bt_node));
  root->left->left->right->val = 7;
  root->left->left->right->left = NULL;
  root->left->left->right->right = NULL;
  root->left->right = malloc(sizeof(bt_node));
  root->left->right->val = 15;
  root->left->right->left = NULL;
  root->left->right->right = NULL;

  root->right = malloc(sizeof(bt_node));
  root->right->val = 50;
  root->right->left = malloc(sizeof(bt_node));
  root->right->left->val = 30;
  root->right->left->left = malloc(sizeof(bt_node));
  root->right->left->left->val = 29;
  root->right->left->left->left = NULL;
  root->right->left->left->right = NULL;
  root->right->left->right = malloc(sizeof(bt_node));
  root->right->left->right->val = 45;
  root->right->left->right->left = NULL;
  root->right->left->right->right = NULL;
  root->right->right = malloc(sizeof(bt_node));
  root->right->right->val = 100;
  root->right->right->left = NULL;
  root->right->right->right = NULL;

  return root;
}

void test_in_order() {
  bt_node *root = create_tree();

  vec *res = in_order_search(root);

  int expected[] = {5, 7, 10, 15, 20, 29, 30, 45, 50, 100};

  for (int i = 0; i < 10; i++) {
    assert(res->items[i] == expected[i]);
  }
}

void test_pre_order() {
  bt_node *root = create_tree();

  vec *res = pre_order_search(root);

  int expected[] = {20, 10, 5, 7, 15, 50, 30, 29, 45, 100};

  for (int i = 0; i < 10; i++) {
    assert(res->items[i] == expected[i]);
  }
}

void test_post_order() {
  bt_node *root = create_tree();

  vec *res = post_order_search(root);

  int expected[] = {7, 5, 15, 10, 29, 45, 30, 100, 50, 20};
  for (int i = 0; i < 10; i++) {
    assert(res->items[i] == expected[i]);
  }
}

int main() {
  test_pre_order();
  test_in_order();
  test_post_order();
  printf("Pre, in, and post order tests passed\n");
  return 0;
}
