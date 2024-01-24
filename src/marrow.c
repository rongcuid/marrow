#include "marrow.h"

#include <stdlib.h>
#include <string.h>

static bool copy_cstr(char **new_str, const char *str) {
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

/**
 * @brief Release function for schemas with no format allocations
 *
 * @param schema
 */
static void schema_release_basic(struct ArrowSchema *schema) {
  if (schema->name) free((void *)schema->name);
  if (schema->metadata) free((void *)schema->name);
  schema->release = NULL;
}

#define def_marr_schema_basic(ty, fmt_str)                            \
  bool marr_schema_##ty(struct ArrowSchema *schema, const char *name, \
                        const char *metadata, int64_t flags) {        \
    bool ok = false;                                                  \
    char *cname;                                                      \
    if (!copy_cstr(&cname, name)) goto finally;                       \
    char *cmeta;                                                      \
    if (!copy_cstr(&cmeta, metadata)) goto free_cname;                \
    *schema = (struct ArrowSchema){                                   \
        .format = fmt_str,                                            \
        .name = cname,                                                \
        .metadata = cmeta,                                            \
        .release = &schema_release_basic,                             \
    };                                                                \
    ok = true;                                                        \
  free_cmeta:                                                         \
    if (!ok) free(cmeta);                                             \
  free_cname:                                                         \
    if (!ok) free(cname);                                             \
  finally:                                                            \
    return ok;                                                        \
  }

def_marr_schema_basic(boolean, "b");
def_marr_schema_basic(int8, "c");
def_marr_schema_basic(uint8, "C");
def_marr_schema_basic(int16, "s");
def_marr_schema_basic(uint16, "S");
def_marr_schema_basic(int32, "i");
def_marr_schema_basic(uint32, "I");
def_marr_schema_basic(int64, "l");
def_marr_schema_basic(uint64, "L");
def_marr_schema_basic(float16, "e");
def_marr_schema_basic(float32, "f");
def_marr_schema_basic(float64, "g");
#undef def_marr_schema_basic

bool marr_schema_null(struct ArrowSchema *schema, const char *name,
                      const char *metadata) {
  bool ok = false;
  char *cname;
  if (!copy_cstr(&cname, name)) goto finally;
  char *cmeta;
  if (!copy_cstr(&cmeta, metadata)) goto free_cname;
  *schema = (struct ArrowSchema){
      .format = "n",
      .name = cname,
      .metadata = cmeta,
      .release = &schema_release_basic,
  };
  ok = true;
free_cmeta:
  if (!ok) free(cmeta);
free_cname:
  if (!ok) free(cname);
finally:
  return ok;
}
