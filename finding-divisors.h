#ifndef FINDING_DIVISORS_H
#define FINDING_DIVISORS_H
#include <stdint.h>
#include <stddef.h>
void find_divisors(uint32_t* a, size_t a_len,
  uint32_t* out_divisors, size_t* out_divisors_len,
  uint32_t* out_dividends, size_t* out_dividends_len); 

#endif
