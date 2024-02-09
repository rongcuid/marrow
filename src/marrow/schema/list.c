#include "marrow/schema/list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "internal/utils.h"

#define marr_decl_def_schema_list(ty, fmt)                                   \
  MarrSchemaCreated marrSchema##ty(const char *zName, const char *zMetadata, \
                                   int64_t flags,                            \
                                   struct ArrowSchema *mChild) {             \
    MarrSchemaCreated result = {0};                                          \
    char *cname;                                                             \
    if (!marrCloneCStr(&cname, zName)) goto finally;                         \
    char *cmeta;                                                             \
    if (!marrCloneCStr(&cmeta, zMetadata)) goto free_cname;                  \
    struct ArrowSchema **children = calloc(1, sizeof(struct ArrowSchema *)); \
    if (!children) goto free_cmeta;                                          \
    children[0] = mChild;                                                    \
    result.value = (struct ArrowSchema){                                     \
        .format = "+l",                                                      \
        .name = cname,                                                       \
        .metadata = cmeta,                                                   \
        .release = &schemaReleaseRecursive,                                  \
        .n_children = 1,                                                     \
        .children = children,                                                \
    };                                                                       \
  ok:                                                                        \
    result.ok = true;                                                        \
  free_children:                                                             \
    if (!result.ok) free(children);                                          \
  free_cmeta:                                                                \
    if (!result.ok) free(cmeta);                                             \
  free_cname:                                                                \
    if (!result.ok) free(cname);                                             \
  finally:                                                                   \
    return result;                                                           \
  }

marr_decl_def_schema_list(List, "+l");
marr_decl_def_schema_list(LargeList, "+L");
marr_decl_def_schema_list(ListView, "+vl");
marr_decl_def_schema_list(LargeListView, "+vL");

#undef marr_decl_def_schema_list

MarrSchemaCreated marrSchemaFixedList(const char *zName, const char *zMetadata,
                                      int64_t flags, struct ArrowSchema *mChild,
                                      ptrdiff_t size) {
  MarrSchemaCreated result = {0};
  char *cname;
  if (!marrCloneCStr(&cname, zName)) goto finally;
  char *cmeta;
  if (!marrCloneCStr(&cmeta, zMetadata)) goto free_cname;
  ptrdiff_t fmtSize = snprintf(NULL, 0, "+w:%td", size);
  char *fmt = malloc(fmtSize + 1);
  if (!fmt) goto free_cmeta;
  if (snprintf(fmt, fmtSize, "+w:%td", size) < 0) goto free_fmt;
  struct ArrowSchema **children = calloc(1, sizeof(struct ArrowSchema *));
  if (!children) goto free_fmt;
  children[0] = mChild;
  result.value = (struct ArrowSchema){
      .format = fmt,
      .name = cname,
      .metadata = cmeta,
      .release = &schemaReleaseRecursiveFormatted,
      .n_children = 1,
      .children = children,
  };
ok:
  result.ok = true;
free_children:
  if (!result.ok) free(children);
free_fmt:
  if (!result.ok) free(fmt);
free_cmeta:
  if (!result.ok) free(cmeta);
free_cname:
  if (!result.ok) free(cname);
finally:
  return result;
}
