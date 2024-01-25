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

#define decl_marr_schema_primitive(ty)                                \
  bool marrSchema##ty(struct ArrowSchema *pSchema, const char *zName, \
                      const char *zMetadata, int64_t flags)
#define decl_marr_schema_primitive_with_args(ty, ...)                 \
  bool marrSchema##ty(struct ArrowSchema *pSchema, const char *zName, \
                      const char *zMetadata, int64_t flags, __VA_ARGS__)

#define decl_def_marr_schema_primitive(ty, fmt_str)         \
  decl_marr_schema_primitive(ty) {                          \
    bool ok = false;                                        \
    char *cname;                                            \
    if (!marrCloneCStr(&cname, zName)) goto finally;        \
    char *cmeta;                                            \
    if (!marrCloneCStr(&cmeta, zMetadata)) goto free_cname; \
    *pSchema = (struct ArrowSchema){                        \
        .format = fmt_str,                                  \
        .name = cname,                                      \
        .metadata = cmeta,                                  \
        .release = &schemaReleaseBasic,                     \
    };                                                      \
    ok = true;                                              \
  free_cmeta:                                               \
    if (!ok) free(cmeta);                                   \
  free_cname:                                               \
    if (!ok) free(cname);                                   \
  finally:                                                  \
    return ok;                                              \
  }

#define def_marr_schema_primitive_formatted(fmt_str, ...)                 \
  do {                                                                    \
    bool ok = false;                                                      \
    char *cname;                                                          \
    if (!marrCloneCStr(&cname, zName)) goto finally;                      \
    char *cmeta;                                                          \
    if (!marrCloneCStr(&cmeta, zMetadata)) goto free_cname;               \
    ptrdiff_t size = snprintf(NULL, 0, fmt_str, __VA_ARGS__);             \
    char *fmt = malloc(size + 1);                                         \
    if (!fmt) goto free_cmeta;                                            \
    if (snprintf(fmt, size + 1, fmt_str, __VA_ARGS__) < 0) goto free_fmt; \
    *pSchema = (struct ArrowSchema){                                      \
        .format = fmt,                                                    \
        .name = cname,                                                    \
        .metadata = cmeta,                                                \
        .release = &schemaReleaseFormatted,                               \
    };                                                                    \
  free_fmt:                                                               \
    if (!ok) free(fmt);                                                   \
  free_cmeta:                                                             \
    if (!ok) free(cmeta);                                                 \
  free_cname:                                                             \
    if (!ok) free(cname);                                                 \
  finally:                                                                \
    return ok;                                                            \
  } while (0)

decl_def_marr_schema_primitive(Null, "n");
decl_def_marr_schema_primitive(Boolean, "b");
decl_def_marr_schema_primitive(Int8, "c");
decl_def_marr_schema_primitive(UInt8, "C");
decl_def_marr_schema_primitive(Int16, "s");
decl_def_marr_schema_primitive(UInt16, "S");
decl_def_marr_schema_primitive(Int32, "i");
decl_def_marr_schema_primitive(UInt32, "I");
decl_def_marr_schema_primitive(Int64, "l");
decl_def_marr_schema_primitive(UInt64, "L");
decl_def_marr_schema_primitive(Float16, "e");
decl_def_marr_schema_primitive(Float32, "f");
decl_def_marr_schema_primitive(Float64, "g");
decl_def_marr_schema_primitive(Binary, "z");
decl_def_marr_schema_primitive(LargeBinary, "Z");
decl_def_marr_schema_primitive(BinaryView, "vz");
decl_def_marr_schema_primitive(Utf8, "u");
decl_def_marr_schema_primitive(LargeUtf8, "U");
decl_def_marr_schema_primitive(Utf8View, "vu");
decl_marr_schema_primitive_with_args(Decimal128, ptrdiff_t precision,
                                     ptrdiff_t scale) {
  def_marr_schema_primitive_formatted("d:%td,%td", precision, scale);
}
decl_marr_schema_primitive_with_args(Decimal, ptrdiff_t precision,
                                     ptrdiff_t scale, ptrdiff_t bitwidth) {
  def_marr_schema_primitive_formatted("d:%td,%td,%td", precision, scale,
                                      bitwidth);
}
decl_def_marr_schema_primitive(Date32, "tdD");
decl_def_marr_schema_primitive(Date64, "tdm");
decl_def_marr_schema_primitive(Time32S, "tts");
decl_def_marr_schema_primitive(Time32Ms, "tdm");
decl_def_marr_schema_primitive(Time64Us, "ttu");
decl_def_marr_schema_primitive(Time64Ns, "ttn");
decl_def_marr_schema_primitive(DurationS, "tDs");
decl_def_marr_schema_primitive(DurationMs, "tDm");
decl_def_marr_schema_primitive(DurationUs, "tDu");
decl_def_marr_schema_primitive(DurationNs, "tDn");
decl_def_marr_schema_primitive(IntervalMonth, "tiM");
decl_def_marr_schema_primitive(IntervalDayTime, "tiD");
decl_def_marr_schema_primitive(IntervalMonthDayNs, "tin");
#undef decl_def_marr_schema_primitive
#undef decl_marr_schema_primitive
#undef decl_marr_schema_primitive_with_args
#undef def_marr_schema_primitive_formatted