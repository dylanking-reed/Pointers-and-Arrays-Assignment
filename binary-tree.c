#include "binary-tree.h"
#include <stdlib.h>
#include <assert.h>

/// Allocates a new empty tree.
Tree* tree_new() {
  Tree* new = malloc(sizeof(Tree));
  if (new == NULL) exit(1);
  new->root = NULL;
  new->size = 0;
  return new;
}

/// Allocates a new leaf node.
Node* node_new(uint32_t val) {
  Node* new = malloc(sizeof(Node));
  if (new == NULL) exit(1);
  new->val = val;
  new->left = NULL;
  new->right = NULL;
  return new;
}


void tree_add_node(Node* root, Node* to_add) {
  if (to_add->val < root->val) {
    if (root->left == NULL) {
      root->left = to_add;
      return;
    } else {
      tree_add_node(root->left, to_add);
    }
  } else if (to_add->val > root->val) {
    if (root->right == NULL) {
      root->right = to_add;
      return;
    } else {
      tree_add_node(root->right, to_add);
    }
  } else {
    // no duplicates
    free(to_add);
    return;
  }  
}

/// Adds a value to tree `t`.
void tree_add(Tree* t, uint32_t val) {
  Node* new = node_new(val); 
  if (t->root == NULL) t->root = new;
  tree_add_node(t->root, new);
}
/// Allocates a new tree and fills it with values from `array`.
Tree* tree_from(uint32_t* array, size_t array_len) {
  Tree* t = tree_new();
  for (size_t i = 0; i < array_len; i++) {
    tree_add(t, array[i]);
  }
  return t;
}

void tree_remove_root(Tree* t) {
  if (t->root == NULL) return;
  Node* old_root = t->root;
  if (t->root->left == NULL) {
    if (t->root->right != NULL) {
      t->root = t->root->right;
    } else {
      t->root = NULL;
      assert(t->size == 1);
    } 
  } else {
    t->root = t->root->left;
    tree_add_node(t->root, old_root->right);
  }
  t->size -= 1;
  free(old_root);
}

void node_remove_left(Node* n) {
  if (n->left == NULL) return;
  Node* old = n->left;
  n->left = n->left->left;
  tree_add_node(n, old->right);
  free(old);
}

void node_remove_right(Node* n) {
  if (n->right == NULL) return;
  Node* old = n->right;
  n->right = n->right->right;
  tree_add_node(n, old->left);
  free(old);
}

/// Removes a value from tree `t`, Promoting from the left. 
/// Returns 1 if the tree contained the value before removal,
/// 0 if the tree did not contain the value.
int tree_remove(Tree* t, uint32_t val) {
  if (t->root->val == val) {
    tree_remove_root(t);
    return 1;
  } else {
  
  }
}

