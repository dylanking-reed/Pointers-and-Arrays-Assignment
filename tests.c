#include "binary-tree.h"
#include "finding-divisors.h"
#include <stdio.h>
#include <assert.h>

int dbg(int a) {
  printf("%d", a);
  return a;
}


/// Prints an array of `uint32_t`s.
void uint32_array_print(uint32_t* a, size_t a_len) {
  printf("{ ");
  for (size_t i = 0; i < a_len; i++) printf("%d, ", a[i]);
  printf("}");
}

/// Prints an array of `uint32_t`s with a newline.
void uint32_array_println(uint32_t* a, size_t a_len) {
  uint32_array_print(a, a_len); printf("\n"); 
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

void finding_divisors_test() {
  printf("Running test: finding_divisors_test ... ");
  uint32_t a[3] = {2, 5, 6};
  uint32_t divisors[3];
  size_t divisors_len = 0;
  uint32_t dividends[3];
  size_t dividends_len = 0;
  find_divisors(a, 3, divisors, &divisors_len, dividends, &dividends_len);
  uint32_array_print(divisors, divisors_len);
  uint32_array_print(dividends, dividends_len);
  printf("PASSED\n");
}

int main(void) {
  printf("Testing...\n");
  /* tests */
  binary_tree_test();
  finding_divisors_test();
  printf("Tests passed.\n");
  return 0;
}
