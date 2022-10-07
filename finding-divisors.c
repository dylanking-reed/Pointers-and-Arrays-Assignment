#include "finding-divisors.h"


void array_push(uint32_t* a, size_t* a_len, uint32_t val) {
  a[*a_len] = val;
  *a_len += 1;
}

void find_divisors(uint32_t* a, size_t a_len,
  uint32_t* out_divisors, size_t* out_divisors_len,
  uint32_t* out_dividends, size_t* out_dividends_len) {
  for (size_t i = 0; i < a_len; i++) {
    for (size_t j = 0; j < a_len; j++) {
      if (a[i] % a[j] == 0 && a[i] != a[j]) {
        array_push(out_divisors, out_divisors_len, a[j]);
        array_push(out_dividends, out_dividends_len, a[i]);
      }
    } 
  } 
  if (out_divisors_len == 0 && out_dividends_len == 0) {
    array_push(out_divisors, out_divisors_len, 0);
    array_push(out_dividends, out_dividends_len, 0);
  }
}
