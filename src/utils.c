#include "utils.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

bool marrCloneCStr(char **pNewStr, const char *pStr) {
  bool ok = false;
  assert(pNewStr != NULL && "marrowCloneCStr(): pNewStr MUST NOT be NULL");
  if (!pStr) {
    *pNewStr = NULL;
    goto ok;
  }
  ptrdiff_t sz = strlen(pStr);
  char *p = malloc(sz);
  if (!p) goto finally;
  memcpy(p, pStr, sz);
  *pNewStr = p;
ok:
  ok = true;
finally:
  return ok;
}