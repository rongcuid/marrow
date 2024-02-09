#include "marrow/schema/map.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "internal/utils.h"
#include "marrow/schema/result.h"
#include "marrow/schema/struct.h"

MarrSchemaCreated marrSchemaMap(const char *zName, const char *zMetadata,
                                int64_t flags, struct ArrowSchema *mKey,
                                struct ArrowSchema *mValue) {
  MarrSchemaCreated result = {0};
  char *cname;
  if (!marrCloneCStr(&cname, zName)) goto finally;
  char *cmeta;
  if (!marrCloneCStr(&cmeta, zMetadata)) goto free_cname;
  struct ArrowSchema **children = calloc(1, sizeof(struct ArrowSchema *));
  if (!children) goto free_cmeta;
  struct ArrowSchema **kv = calloc(2, sizeof(struct ArrowSchema *));
  if (!kv) goto free_children;
  kv[0] = mKey;
  kv[1] = mValue;
  MarrSchemaCreated entries = marrSchemaStruct("entries", NULL, 0, kv, 2);
  if (!entries.ok) goto free_kv;
  children[0] = entries;
  result.value = (struct ArrowSchema){
      .format = "+m",
      .name = cname,
      .metadata = cmeta,
      .release = &schemaReleaseRecursive,
      .n_children = 1,
      .children = children,
  };
ok:
  result.ok = true;
free_entries:
  if (!result.ok) entries.value.release(&entries.value);
free_kv:
  if (!result.ok) free(kv);
free_children:
  if (!result.ok) free(children);
free_cmeta:
  if (!result.ok) free(cmeta);
free_cname:
  if (!result.ok) free(cname);
finally:
  return result;
}