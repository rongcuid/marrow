#ifndef MARROW_SCHEMA_H_
#define MARROW_SCHEMA_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "arrow.h"

////// Basic Primitives
bool marrSchemaNull(struct ArrowSchema *schema, const char *name,
                    const char *metadata, int64_t flags);
bool marrSchemaBoolean(struct ArrowSchema *schema, const char *name,
                       const char *metadata, int64_t flags);
bool marrSchemaInt8(struct ArrowSchema *schema, const char *name,
                    const char *metadata, int64_t flags);
bool marrSchemaUInt8(struct ArrowSchema *schema, const char *name,
                     const char *metadata, int64_t flags);
bool marrSchemaInt16(struct ArrowSchema *schema, const char *name,
                     const char *metadata, int64_t flags);
bool marrSchemaUInt16(struct ArrowSchema *schema, const char *name,
                      const char *metadata, int64_t flags);
bool marrSchemaInt32(struct ArrowSchema *schema, const char *name,
                     const char *metadata, int64_t flags);
bool marrSchemaUInt32(struct ArrowSchema *schema, const char *name,
                      const char *metadata, int64_t flags);
bool marrSchemaInt64(struct ArrowSchema *schema, const char *name,
                     const char *metadata, int64_t flags);
bool marrSchemaUInt64(struct ArrowSchema *schema, const char *name,
                      const char *metadata, int64_t flags);
bool marrSchemaFloat16(struct ArrowSchema *schema, const char *name,
                       const char *metadata, int64_t flags);
bool marrSchemaFloat32(struct ArrowSchema *schema, const char *name,
                       const char *metadata, int64_t flags);
bool marrSchemaFloat64(struct ArrowSchema *schema, const char *name,
                       const char *metadata, int64_t flags);
////// Binaries
bool marrSchemaBinary(struct ArrowSchema *schema, const char *name,
                      const char *metadata, int64_t flags);
bool marrSchemaLargeBinary(struct ArrowSchema *schema, const char *name,
                           const char *metadata, int64_t flags);
bool marrSchemaBinaryView(struct ArrowSchema *schema, const char *name,
                          const char *metadata, int64_t flags);
bool marrSchemaUtf8(struct ArrowSchema *schema, const char *name,
                    const char *metadata, int64_t flags);
bool marrSchemaLargeUtf8(struct ArrowSchema *schema, const char *name,
                         const char *metadata, int64_t flags);
bool marrSchemaUtf8View(struct ArrowSchema *schema, const char *name,
                        const char *metadata, int64_t flags);
bool marrSchemaDecimal128(struct ArrowSchema *schema, const char *name,
                          const char *metadata, ptrdiff_t precision,
                          ptrdiff_t scale, int64_t flags);
bool marrSchemaDecimal(struct ArrowSchema *schema, const char *name,
                       const char *metadata, ptrdiff_t bitwidth,
                       ptrdiff_t precision, ptrdiff_t scale, int64_t flags);
////// Temporals
bool marrSchemaDate32(struct ArrowSchema *schema, const char *name,
                      const char *metadata, int64_t flags);
bool marrSchemaDate64(struct ArrowSchema *schema, const char *name,
                      const char *metadata, int64_t flags);
bool marrSchemaTime32S(struct ArrowSchema *schema, const char *name,
                       const char *metadata, int64_t flags);
bool marrSchemaTime32Ms(struct ArrowSchema *schema, const char *name,
                        const char *metadata, int64_t flags);
bool marrSchemaTime64Us(struct ArrowSchema *schema, const char *name,
                        const char *metadata, int64_t flags);
bool marrSchemaTime64Ns(struct ArrowSchema *schema, const char *name,
                        const char *metadata, int64_t flags);
bool marrSchemaTimestampS(struct ArrowSchema *schema, const char *name,
                          const char *metadata, int64_t flags,
                          const char *timezone);
bool marrSchemaTimestampMs(struct ArrowSchema *schema, const char *name,
                           const char *metadata, int64_t flags,
                           const char *timezone);
bool marrSchemaTimestampUs(struct ArrowSchema *schema, const char *name,
                           const char *metadata, int64_t flags,
                           const char *timezone);
bool marrSchemaTimestampNs(struct ArrowSchema *schema, const char *name,
                           const char *metadata, int64_t flags,
                           const char *timezone);
bool marrSchemaDurationS(struct ArrowSchema *schema, const char *name,
                         const char *metadata, int64_t flags);
bool marrSchemaDurationMs(struct ArrowSchema *schema, const char *name,
                          const char *metadata, int64_t flags);
bool marrSchemaDurationUs(struct ArrowSchema *schema, const char *name,
                          const char *metadata, int64_t flags);
bool marrSchemaDurationNs(struct ArrowSchema *schema, const char *name,
                          const char *metadata, int64_t flags);
bool marrSchemaDurationMonth(struct ArrowSchema *schema, const char *name,
                             const char *metadata, int64_t flags);
bool marrSchemaDurationDayTime(struct ArrowSchema *schema, const char *name,
                               const char *metadata, int64_t flags);
bool marrSchemaDurationMonthDayNs(struct ArrowSchema *schema, const char *name,
                                  const char *metadata, int64_t flags);
////// Nested types
bool marrSchemaList(struct ArrowSchema *schema, const char *name,
                    const char *metadata, int64_t flags,
                    struct ArrowSchema *child);
bool marrSchemaLargeList(struct ArrowSchema *schema, const char *name,
                         const char *metadata, int64_t flags,
                         struct ArrowSchema *child);
bool marrSchemaListView(struct ArrowSchema *schema, const char *name,
                        const char *metadata, int64_t flags,
                        struct ArrowSchema *child);
bool marrSchemaLargeListView(struct ArrowSchema *schema, const char *name,
                             const char *metadata, int64_t flags,
                             struct ArrowSchema *child);
bool marrSchemaFixedList(struct ArrowSchema *schema, const char *name,
                         const char *metadata, int64_t flags,
                         struct ArrowSchema *child, ptrdiff_t size);
// TODO
bool marrSchemaStruct(struct ArrowSchema *schema, const char *name,
                      const char *metadata, int64_t flags);
bool marrSchemaMap(struct ArrowSchema *schema, const char *name,
                   const char *metadata, int64_t flags);
bool marrSchemaDenseUnion(struct ArrowSchema *schema, const char *name,
                          const char *metadata, int64_t flags);
bool marrSchemaSparseUnion(struct ArrowSchema *schema, const char *name,
                           const char *metadata, int64_t flags);
bool marrSchemaRunEnd(struct ArrowSchema *schema, const char *name,
                      const char *metadata, int64_t flags);

#endif  // MARROW_SCHEMA_H_