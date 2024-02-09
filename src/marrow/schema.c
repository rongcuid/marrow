#include "marrow/schema.h"

#include <stdbool.h>
#include <stdio.h>
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

/**
 * @brief Release function for schemas with format allocations
 *
 * @param schema
 */
static void schemaReleaseFormatted(struct ArrowSchema *pSchema) {
  free((void *)pSchema->format);
  if (pSchema->name) free((void *)pSchema->name);
  if (pSchema->metadata) free((void *)pSchema->name);
  pSchema->release = NULL;
}

static void schemaReleaseRecursive(struct ArrowSchema *pSchema) {
  if (pSchema->name) free((void *)pSchema->name);
  if (pSchema->metadata) free((void *)pSchema->name);
  for (ptrdiff_t i = 0; i < pSchema->n_children; ++i) {
    pSchema->children[i]->release(pSchema->children[i]);
  }
  free(pSchema->children);
  pSchema->release = NULL;
}

#define marr_decl_schema_primitive(ty)                                       \
  MarrSchemaCreated marrSchema##ty(const char *zName, const char *zMetadata, \
                                   int64_t flags)
#define marr_decl_schema_primitive_args(ty, ...)                             \
  MarrSchemaCreated marrSchema##ty(const char *zName, const char *zMetadata, \
                                   int64_t flags, __VA_ARGS__)

#define marr_decl_def_schema_primitive(ty, fmt_str)         \
  marr_decl_schema_primitive(ty) {                          \
    MarrSchemaCreated result = {0};                         \
    char *cname;                                            \
    if (!marrCloneCStr(&cname, zName)) goto finally;        \
    char *cmeta;                                            \
    if (!marrCloneCStr(&cmeta, zMetadata)) goto free_cname; \
    result.value = (struct ArrowSchema){                    \
        .format = fmt_str,                                  \
        .name = cname,                                      \
        .metadata = cmeta,                                  \
        .release = &schemaReleaseBasic,                     \
    };                                                      \
    result.ok = true;                                       \
  free_cmeta:                                               \
    if (!result.ok) free(cmeta);                            \
  free_cname:                                               \
    if (!result.ok) free(cname);                            \
  finally:                                                  \
    return result;                                          \
  }

#define marr_def_schema_primitive_formatted(fmt_str, ...)                 \
  do {                                                                    \
    MarrSchemaCreated result = {0};                                       \
    char *cname;                                                          \
    if (!marrCloneCStr(&cname, zName)) goto finally;                      \
    char *cmeta;                                                          \
    if (!marrCloneCStr(&cmeta, zMetadata)) goto free_cname;               \
    ptrdiff_t size = snprintf(NULL, 0, fmt_str, __VA_ARGS__);             \
    char *fmt = malloc(size + 1);                                         \
    if (!fmt) goto free_cmeta;                                            \
    if (snprintf(fmt, size + 1, fmt_str, __VA_ARGS__) < 0) goto free_fmt; \
    result.value = (struct ArrowSchema){                                  \
        .format = fmt,                                                    \
        .name = cname,                                                    \
        .metadata = cmeta,                                                \
        .release = &schemaReleaseFormatted,                               \
    };                                                                    \
    result.ok = true;                                                     \
  free_fmt:                                                               \
    if (!result.ok) free(fmt);                                            \
  free_cmeta:                                                             \
    if (!result.ok) free(cmeta);                                          \
  free_cname:                                                             \
    if (!result.ok) free(cname);                                          \
  finally:                                                                \
    return result;                                                        \
  } while (0)

marr_decl_def_schema_primitive(Null, "n");
marr_decl_def_schema_primitive(Boolean, "b");
marr_decl_def_schema_primitive(Int8, "c");
marr_decl_def_schema_primitive(UInt8, "C");
marr_decl_def_schema_primitive(Int16, "s");
marr_decl_def_schema_primitive(UInt16, "S");
marr_decl_def_schema_primitive(Int32, "i");
marr_decl_def_schema_primitive(UInt32, "I");
marr_decl_def_schema_primitive(Int64, "l");
marr_decl_def_schema_primitive(UInt64, "L");
marr_decl_def_schema_primitive(Float16, "e");
marr_decl_def_schema_primitive(Float32, "f");
marr_decl_def_schema_primitive(Float64, "g");
marr_decl_def_schema_primitive(Binary, "z");
marr_decl_def_schema_primitive(LargeBinary, "Z");
marr_decl_def_schema_primitive(BinaryView, "vz");
marr_decl_def_schema_primitive(Utf8, "u");
marr_decl_def_schema_primitive(LargeUtf8, "U");
marr_decl_def_schema_primitive(Utf8View, "vu");
marr_decl_schema_primitive_args(Decimal128, ptrdiff_t precision,
                                ptrdiff_t scale) {
  marr_def_schema_primitive_formatted("d:%td,%td", precision, scale);
}
marr_decl_schema_primitive_args(Decimal, ptrdiff_t precision, ptrdiff_t scale,
                                ptrdiff_t bitwidth) {
  marr_def_schema_primitive_formatted("d:%td,%td,%td", precision, scale,
                                      bitwidth);
}
marr_decl_def_schema_primitive(Date32, "tdD");
marr_decl_def_schema_primitive(Date64, "tdm");
marr_decl_def_schema_primitive(Time32S, "tts");
marr_decl_def_schema_primitive(Time32Ms, "tdm");
marr_decl_def_schema_primitive(Time64Us, "ttu");
marr_decl_def_schema_primitive(Time64Ns, "ttn");
marr_decl_schema_primitive_args(TimestampS, const char *timezone) {
  marr_def_schema_primitive_formatted("tss:%s", timezone);
}
marr_decl_schema_primitive_args(TimestampMs, const char *timezone) {
  marr_def_schema_primitive_formatted("tsm:%s", timezone);
}
marr_decl_schema_primitive_args(TimestampUs, const char *timezone) {
  marr_def_schema_primitive_formatted("tsu:%s", timezone);
}
marr_decl_schema_primitive_args(TimestampNs, const char *timezone) {
  marr_def_schema_primitive_formatted("tsn:%s", timezone);
}
marr_decl_def_schema_primitive(DurationS, "tDs");
marr_decl_def_schema_primitive(DurationMs, "tDm");
marr_decl_def_schema_primitive(DurationUs, "tDu");
marr_decl_def_schema_primitive(DurationNs, "tDn");
marr_decl_def_schema_primitive(IntervalMonth, "tiM");
marr_decl_def_schema_primitive(IntervalDayTime, "tiD");
marr_decl_def_schema_primitive(IntervalMonthDayNs, "tin");
#undef marr_decl_def_schema_primitive
#undef marr_decl_schema_primitive
#undef marr_decl_schema_primitive_args
#undef marr_def_schema_primitive_formatted

MarrSchemaCreated marrSchemaList(const char *zName, const char *zMetadata,
                                 int64_t flags, struct ArrowSchema *mChild) {
  MarrSchemaCreated result = {0};
  char *cname;
  if (!marrCloneCStr(&cname, zName)) goto finally;
  char *cmeta;
  if (!marrCloneCStr(&cmeta, zMetadata)) goto free_cname;
  struct ArrowSchema **children = calloc(1, sizeof(struct ArrowSchema *));
  if (!children) goto free_cmeta;
  children[0] = mChild;
  result.value = (struct ArrowSchema){
      .format = "+l",
      .name = cname,
      .metadata = cmeta,
      .release = &schemaReleaseRecursive,
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