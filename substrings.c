#include "substrings.h"
#include <assert.h>
#include <stdlib.h>

char* find_substring(char* haystack, char* needle) {
  for (int i = 0; haystack[i] != '\0'; i++) {
    for (int j = 0; needle[j] != '\0'; j++) {
      if (needle[j] == haystack[i+j] && needle[j+1] == '\0') {
        return &(haystack[i]); 
      } else if (needle[j] != haystack[i+j]) {
        break; 
      }
    }
    if (haystack[i+1] == '\0') {
      return &(haystack[i+1]);
    }
  }
  assert(0 && "Unreachable!");
  return NULL;
}

char* copy_substring(char* str, size_t start, size_t end) {
  char* out = malloc(sizeof(char) * ((end - start) + 2));
  for (int i = 0;i + start <= end;i++) {
    out[i] = str[i + start]; 
  }
  out[end - start + 1] = '\0';
  return out;
}
