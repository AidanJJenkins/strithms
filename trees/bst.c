#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

tree *create_bst() {
  tree *t = malloc(sizeof(tree));
  t->root = NULL;
  return t;
}

bt_node *create_node(int value) {
  bt_node *n = malloc(sizeof(bt_node));
  n->val = value;
  n->left = NULL;
  n->right = NULL;
  return n;
}

bool find(bt_node *root, int val) {
  if (root == NULL) {
    return false;
  }

  if (root->val == val) {
    return true;
  }

  if (val > root->val) {
    return find(root->right, val);
  }
  return find(root->left, val);
}

bool Find(tree *t, int val) { return find(t->root, val); }

void insert(bt_node *node, int value) {
  if (value < node->val) {
    if (node->left == NULL) {
      node->left = create_node(value);
    } else {
      insert(node->left, value);
    }
  } else if (value > node->val) {
    if (node->right == NULL) {
      node->right = create_node(value);
    } else {
      insert(node->right, value);
    }
  }
}

void Insert(tree *b, int value) {
  if (b->root == NULL) {
    b->root = create_node(value);
  } else {
    insert(b->root, value);
  }
}

bt_node *delete_recursive(bt_node *n, int val) {
  if (n == NULL) {
    return n;
  }

  if (val < n->val) {
    n->left = delete_recursive(n->left, val);
  } else if (val > n->val) {
    n->right = delete_recursive(n->right, val);
  } else {
    if (n->left == NULL) {
      bt_node *temp = n->right;
      free(n);
      return temp;
    } else if (n->right == NULL) {
      bt_node *temp = n->right;
      free(n);
      return temp;
    }

    bt_node *min = min_val_node(n);
    n->val = min->val;
    n->right = delete_recursive(n->right, min->val);
  }

  return n;
}

bt_node *min_val_node(bt_node *n) {
  bt_node *curr = n;
  while (curr && curr->left != NULL) {
    curr = curr->left;
  }
  return curr;
}

void Delete(tree *t, int val) { t->root = delete_recursive(t->root, val); }
