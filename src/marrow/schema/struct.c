#include "marrow/schema/struct.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

static void schemaReleaseStruct(struct ArrowSchema *pSchema) {
  if (pSchema->name) free((void *)pSchema->name);
  if (pSchema->metadata) free((void *)pSchema->name);
  for (ptrdiff_t i = 0; i < pSchema->n_children; ++i) {
    pSchema->children[i]->release(pSchema->children[i]);
  }
  free(pSchema->children);
  pSchema->release = NULL;
}

MarrSchemaCreated marrSchemaStruct(const char *zName, const char *zMetadata,
                                   int64_t flags, struct ArrowSchema **pmFields,
                                   ptrdiff_t fieldCount) {
  MarrSchemaCreated result = {0};
  if (fieldCount < 0) goto finally;
  char *cname;
  if (!marrCloneCStr(&cname, zName)) goto finally;
  char *cmeta;
  if (!marrCloneCStr(&cmeta, zMetadata)) goto free_cname;
  struct ArrowSchema **children =
      calloc(fieldCount, sizeof(struct ArrowSchema *));
  if (!children) goto free_cmeta;
  for (ptrdiff_t i = 0; i < fieldCount; ++i) {
    children[i] = pmFields[i];
  }
  result.value = (struct ArrowSchema){
      .format = "+l",
      .name = cname,
      .metadata = cmeta,
      .release = &schemaReleaseStruct,
      .n_children = 1,
      .children = children,
  };
ok:
  result.ok = true;
free_children:
  if (!result.ok) free(children);
free_cmeta:
  if (!result.ok) free(cmeta);
free_cname:
  if (!result.ok) free(cname);
finally:
  return result;
}