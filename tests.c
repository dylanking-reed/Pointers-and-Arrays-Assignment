#include "binary-tree.h"
#include <stdio.h>
#include <assert.h>

int dbg(int a) {
  printf("%d", a);
  return a;
}

void binary_tree_test() {
  printf("Running test: binary_tree_test ... ");
  /* assertions */
  Tree* t0 = tree_new();
  tree_add(t0, 3);
  tree_add(t0, 4);
  tree_add(t0, 2);
  tree_free(t0);
  uint32_t a[7] = {4, 2, 6, 1, 3, 5, 7};
  Tree* t1 = tree_from(a, 7);
  assert(tree_remove(t1, 4) == 1);
  assert(tree_remove(t1, 6) == 1);
  tree_free(t1); 
  printf("PASSED\n");
}

int main(void) {
  printf("Testing...\n");
  /* tests */
  binary_tree_test();
  printf("Tests passed.\n");
  return 0;
}
