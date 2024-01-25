#include "schema.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"

/**
 * @brief Release function for schemas with no format allocations
 *
 * @param schema
 */
static void schemaReleaseBasic(struct ArrowSchema *pSchema) {
  if (pSchema->name) free((void *)pSchema->name);
  if (pSchema->metadata) free((void *)pSchema->name);
  pSchema->release = NULL;
}

#define def_marr_schema_basic(ty, fmt_str)                            \
  bool marrSchema##ty(struct ArrowSchema *pSchema, const char *zName, \
                      const char *zMetadata, int64_t flags) {         \
    bool ok = false;                                                  \
    char *cname;                                                      \
    if (!marrCloneCStr(&cname, zName)) goto finally;                  \
    char *cmeta;                                                      \
    if (!marrCloneCStr(&cmeta, zMetadata)) goto free_cname;           \
    *pSchema = (struct ArrowSchema){                                  \
        .format = fmt_str,                                            \
        .name = cname,                                                \
        .metadata = cmeta,                                            \
        .release = &schemaReleaseBasic,                               \
    };                                                                \
    ok = true;                                                        \
  free_cmeta:                                                         \
    if (!ok) free(cmeta);                                             \
  free_cname:                                                         \
    if (!ok) free(cname);                                             \
  finally:                                                            \
    return ok;                                                        \
  }

def_marr_schema_basic(Null, "n");
def_marr_schema_basic(Boolean, "b");
def_marr_schema_basic(Int8, "c");
def_marr_schema_basic(UInt8, "C");
def_marr_schema_basic(Int16, "s");
def_marr_schema_basic(UInt16, "S");
def_marr_schema_basic(Int32, "i");
def_marr_schema_basic(UInt32, "I");
def_marr_schema_basic(Int64, "l");
def_marr_schema_basic(UInt64, "L");
def_marr_schema_basic(Float16, "e");
def_marr_schema_basic(Float32, "f");
def_marr_schema_basic(Float64, "g");
#undef def_marr_schema_basic
