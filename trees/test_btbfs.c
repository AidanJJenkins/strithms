#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bt_node *create_trees() {
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

bool test_btbfs() {
  bt_node *t = create_trees();
  bool found = btbfs(t, 29);
  if (!found) {
    return false;
  }

  bool found2 = btbfs(t, 67);
  if (found2) {
    return true;
  }

  free(t);
  return true;
}

int main() {
  bool test = test_btbfs();
  if (!test) {
    printf("BTBFS tests failed\n");
    return 1;
  }
  printf("Binary tree breadth first search tests pass\n");
  return 0;
}
