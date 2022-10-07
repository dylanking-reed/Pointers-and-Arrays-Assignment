#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <stdint.h>
#include <stddef.h>

/// Tree node. `left->val` < `val` < `right->val`.
typedef struct Node_s {
  uint32_t val;
  struct Node_s* left;
  struct Node_s* right;
} Node;

/// Tree. Size is maintained. Tree is empty if `root` == `NULL`
typedef struct Tree_s {
  Node* root;
  size_t size;
} Tree;

/// Allocates a new empty tree.
Tree* tree_new();
/// Allocates a new tree and fills it with values from `array`.
Tree* tree_from(uint32_t* array, size_t array_len);
/// Adds a value to tree `t`.
void tree_add(Tree* t, uint32_t val);
/// Removes a value from tree `t`, Promoting from the left. 
/// Returns 1 if the tree contained the value before removal,
/// 0 if the tree did not contain the value.
int tree_remove(Tree* t, uint32_t val);
#endif
