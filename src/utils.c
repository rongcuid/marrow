#include "utils.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

bool marrow_copy_cstr(char **new_str, const char *str) {
  bool ok = false;
  if (!str) {
    *new_str = NULL;
    goto ok;
  }
  ptrdiff_t sz = strlen(str);
  char *p = malloc(sz);
  if (!p) goto finally;
  memcpy(p, str, sz);
  *new_str = p;
ok:
  ok = true;
finally:
  return ok;
}