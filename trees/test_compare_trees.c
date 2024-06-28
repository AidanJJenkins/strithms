#include "tree.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bt_node *create_tree1() {
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

bool test_compare_trees() {
  bt_node *t1 = create_tree1();
  bt_node *t2 = create_tree1();
  bool equal = compare_trees(t1, t2);
  if (!equal) {
    printf("expected true, got: %d", equal);
    return false;
  }

  t2->val = 10;
  bool equal2 = compare_trees(t1, t2);
  if (equal2) {
    printf("expected false, got: %d", equal2);
    return false;
  }
  return true;
}

int main() {
  bool t = test_compare_trees();
  if (!t) {
    printf("Test compare trees failed\n");
    return 1;
  }

  printf("Compare trees tests passed\n");
  return 0;
}
