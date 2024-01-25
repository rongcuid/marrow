#ifndef MARROW_SCHEMA_H_
#define MARROW_SCHEMA_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "marrow/arrow.h"

////// Basic Primitives
bool marrSchemaNull(struct ArrowSchema *pSchema, const char *zName,
                    const char *zMetadata, int64_t flags);
bool marrSchemaBoolean(struct ArrowSchema *pSchema, const char *zName,
                       const char *zMetadata, int64_t flags);
bool marrSchemaInt8(struct ArrowSchema *pSchema, const char *zName,
                    const char *zMetadata, int64_t flags);
bool marrSchemaUInt8(struct ArrowSchema *pSchema, const char *zName,
                     const char *zMetadata, int64_t flags);
bool marrSchemaInt16(struct ArrowSchema *pSchema, const char *zName,
                     const char *zMetadata, int64_t flags);
bool marrSchemaUInt16(struct ArrowSchema *pSchema, const char *zName,
                      const char *zMetadata, int64_t flags);
bool marrSchemaInt32(struct ArrowSchema *pSchema, const char *zName,
                     const char *zMetadata, int64_t flags);
bool marrSchemaUInt32(struct ArrowSchema *pSchema, const char *zName,
                      const char *zMetadata, int64_t flags);
bool marrSchemaInt64(struct ArrowSchema *pSchema, const char *zName,
                     const char *zMetadata, int64_t flags);
bool marrSchemaUInt64(struct ArrowSchema *pSchema, const char *zName,
                      const char *zMetadata, int64_t flags);
bool marrSchemaFloat16(struct ArrowSchema *pSchema, const char *zName,
                       const char *zMetadata, int64_t flags);
bool marrSchemaFloat32(struct ArrowSchema *pSchema, const char *zName,
                       const char *zMetadata, int64_t flags);
bool marrSchemaFloat64(struct ArrowSchema *pSchema, const char *zName,
                       const char *zMetadata, int64_t flags);
////// Binaries
bool marrSchemaBinary(struct ArrowSchema *pSchema, const char *zName,
                      const char *zMetadata, int64_t flags);
bool marrSchemaLargeBinary(struct ArrowSchema *pSchema, const char *zName,
                           const char *zMetadata, int64_t flags);
bool marrSchemaBinaryView(struct ArrowSchema *pSchema, const char *zName,
                          const char *zMetadata, int64_t flags);
bool marrSchemaUtf8(struct ArrowSchema *pSchema, const char *zName,
                    const char *zMetadata, int64_t flags);
bool marrSchemaLargeUtf8(struct ArrowSchema *pSchema, const char *zName,
                         const char *zMetadata, int64_t flags);
bool marrSchemaUtf8View(struct ArrowSchema *pSchema, const char *zName,
                        const char *zMetadata, int64_t flags);
bool marrSchemaDecimal128(struct ArrowSchema *pSchema, const char *zName,
                          const char *zMetadata, int64_t flags,
                          ptrdiff_t precision, ptrdiff_t scale);
bool marrSchemaDecimal(struct ArrowSchema *pSchema, const char *zName,
                       const char *zMetadata, ptrdiff_t bitwidth, int64_t flags,
                       ptrdiff_t precision, ptrdiff_t scale);
////// Temporals
bool marrSchemaDate32(struct ArrowSchema *pSchema, const char *zName,
                      const char *zMetadata, int64_t flags);
bool marrSchemaDate64(struct ArrowSchema *pSchema, const char *zName,
                      const char *zMetadata, int64_t flags);
bool marrSchemaTime32S(struct ArrowSchema *pSchema, const char *zName,
                       const char *zMetadata, int64_t flags);
bool marrSchemaTime32Ms(struct ArrowSchema *pSchema, const char *zName,
                        const char *zMetadata, int64_t flags);
bool marrSchemaTime64Us(struct ArrowSchema *pSchema, const char *zName,
                        const char *zMetadata, int64_t flags);
bool marrSchemaTime64Ns(struct ArrowSchema *pSchema, const char *zName,
                        const char *zMetadata, int64_t flags);
bool marrSchemaTimestampS(struct ArrowSchema *pSchema, const char *zName,
                          const char *zMetadata, int64_t flags,
                          const char *timezone);
bool marrSchemaTimestampMs(struct ArrowSchema *pSchema, const char *zName,
                           const char *zMetadata, int64_t flags,
                           const char *timezone);
bool marrSchemaTimestampUs(struct ArrowSchema *pSchema, const char *zName,
                           const char *zMetadata, int64_t flags,
                           const char *timezone);
bool marrSchemaTimestampNs(struct ArrowSchema *pSchema, const char *zName,
                           const char *zMetadata, int64_t flags,
                           const char *timezone);
bool marrSchemaDurationS(struct ArrowSchema *pSchema, const char *zName,
                         const char *zMetadata, int64_t flags);
bool marrSchemaDurationMs(struct ArrowSchema *pSchema, const char *zName,
                          const char *zMetadata, int64_t flags);
bool marrSchemaDurationUs(struct ArrowSchema *pSchema, const char *zName,
                          const char *zMetadata, int64_t flags);
bool marrSchemaDurationNs(struct ArrowSchema *pSchema, const char *zName,
                          const char *zMetadata, int64_t flags);
bool marrSchemaIntervalMonth(struct ArrowSchema *pSchema, const char *zName,
                             const char *zMetadata, int64_t flags);
bool marrSchemaIntervalDayTime(struct ArrowSchema *pSchema, const char *zName,
                               const char *zMetadata, int64_t flags);
bool marrSchemaIntervalMonthDayNs(struct ArrowSchema *pSchema,
                                  const char *zName, const char *zMetadata,
                                  int64_t flags);
////// Nested types
bool marrSchemaList(struct ArrowSchema *pSchema, const char *zName,
                    const char *zMetadata, int64_t flags,
                    struct ArrowSchema *child);
bool marrSchemaLargeList(struct ArrowSchema *pSchema, const char *zName,
                         const char *zMetadata, int64_t flags,
                         struct ArrowSchema *child);
bool marrSchemaListView(struct ArrowSchema *pSchema, const char *zName,
                        const char *zMetadata, int64_t flags,
                        struct ArrowSchema *child);
bool marrSchemaLargeListView(struct ArrowSchema *pSchema, const char *zName,
                             const char *zMetadata, int64_t flags,
                             struct ArrowSchema *child);
bool marrSchemaFixedList(struct ArrowSchema *pSchema, const char *zName,
                         const char *zMetadata, int64_t flags,
                         struct ArrowSchema *child, ptrdiff_t size);
// TODO
bool marrSchemaStruct(struct ArrowSchema *pSchema, const char *zName,
                      const char *zMetadata, int64_t flags);
bool marrSchemaMap(struct ArrowSchema *pSchema, const char *zName,
                   const char *zMetadata, int64_t flags);
bool marrSchemaDenseUnion(struct ArrowSchema *pSchema, const char *zName,
                          const char *zMetadata, int64_t flags);
bool marrSchemaSparseUnion(struct ArrowSchema *pSchema, const char *zName,
                           const char *zMetadata, int64_t flags);
bool marrSchemaRunEnd(struct ArrowSchema *pSchema, const char *zName,
                      const char *zMetadata, int64_t flags);

#endif  // MARROW_SCHEMA_H_