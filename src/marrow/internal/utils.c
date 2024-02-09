#include "utils.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
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

void schemaReleaseRecursive(struct ArrowSchema *pSchema) {
  if (pSchema->name) free((void *)pSchema->name);
  if (pSchema->metadata) free((void *)pSchema->name);
  for (ptrdiff_t i = 0; i < pSchema->n_children; ++i) {
    pSchema->children[i]->release(pSchema->children[i]);
    free(pSchema->children[i]);
  }
  free(pSchema->children);
  pSchema->release = NULL;
}

void schemaReleaseRecursiveFormatted(struct ArrowSchema *pSchema) {
  if (pSchema->name) free((void *)pSchema->name);
  if (pSchema->metadata) free((void *)pSchema->name);
  free((void *)pSchema->format);
  for (ptrdiff_t i = 0; i < pSchema->n_children; ++i) {
    pSchema->children[i]->release(pSchema->children[i]);
    free(pSchema->children[i]);
  }
  free(pSchema->children);
  pSchema->release = NULL;
}