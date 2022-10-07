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
  tree_add(t, 3);
  uint32_t a[7] = {4, 2, 6, 1, 3, 5, 7};
  Tree* t1 = tree_from(a, 7);
  tree_remove(t, 4);
  //printf("PASSED\n");
}

int main(void) {
  printf("Testing...\n");
  /* tests */
  binary_tree_test();
  printf("Tests passed.\n");
  return 0;
}
