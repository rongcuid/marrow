#ifndef MARROW_SCHEMA_H_
#define MARROW_SCHEMA_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "marrow/arrow.h"

////// Primitives
typedef struct {
  union {
    struct ArrowSchema value;
    enum {
      MARR_SCHEMA_ERR = 0,
    } err;
  };
  bool ok;
} ArrowSchemaCreated;
ArrowSchemaCreated marrSchemaNull(const char *zName, const char *zMetadata,
                                  int64_t flags);
ArrowSchemaCreated marrSchemaBoolean(const char *zName, const char *zMetadata,
                                     int64_t flags);
ArrowSchemaCreated marrSchemaInt8(const char *zName, const char *zMetadata,
                                  int64_t flags);
ArrowSchemaCreated marrSchemaUInt8(const char *zName, const char *zMetadata,
                                   int64_t flags);
ArrowSchemaCreated marrSchemaInt16(const char *zName, const char *zMetadata,
                                   int64_t flags);
ArrowSchemaCreated marrSchemaUInt16(const char *zName, const char *zMetadata,
                                    int64_t flags);
ArrowSchemaCreated marrSchemaInt32(const char *zName, const char *zMetadata,
                                   int64_t flags);
ArrowSchemaCreated marrSchemaUInt32(const char *zName, const char *zMetadata,
                                    int64_t flags);
ArrowSchemaCreated marrSchemaInt64(const char *zName, const char *zMetadata,
                                   int64_t flags);
ArrowSchemaCreated marrSchemaUInt64(const char *zName, const char *zMetadata,
                                    int64_t flags);
ArrowSchemaCreated marrSchemaFloat16(const char *zName, const char *zMetadata,
                                     int64_t flags);
ArrowSchemaCreated marrSchemaFloat32(const char *zName, const char *zMetadata,
                                     int64_t flags);
ArrowSchemaCreated marrSchemaFloat64(const char *zName, const char *zMetadata,
                                     int64_t flags);
ArrowSchemaCreated marrSchemaBinary(const char *zName, const char *zMetadata,
                                    int64_t flags);
ArrowSchemaCreated marrSchemaLargeBinary(const char *zName,
                                         const char *zMetadata, int64_t flags);
ArrowSchemaCreated marrSchemaBinaryView(const char *zName,
                                        const char *zMetadata, int64_t flags);
ArrowSchemaCreated marrSchemaUtf8(const char *zName, const char *zMetadata,
                                  int64_t flags);
ArrowSchemaCreated marrSchemaLargeUtf8(const char *zName, const char *zMetadata,
                                       int64_t flags);
ArrowSchemaCreated marrSchemaUtf8View(const char *zName, const char *zMetadata,
                                      int64_t flags);
ArrowSchemaCreated marrSchemaDecimal128(const char *zName,
                                        const char *zMetadata, int64_t flags,
                                        ptrdiff_t precision, ptrdiff_t scale);
ArrowSchemaCreated marrSchemaDecimal(const char *zName, const char *zMetadata,
                                     int64_t flags, ptrdiff_t precision,
                                     ptrdiff_t scale, ptrdiff_t bitwidth);
ArrowSchemaCreated marrSchemaDate32(const char *zName, const char *zMetadata,
                                    int64_t flags);
ArrowSchemaCreated marrSchemaDate64(const char *zName, const char *zMetadata,
                                    int64_t flags);
ArrowSchemaCreated marrSchemaTime32S(const char *zName, const char *zMetadata,
                                     int64_t flags);
ArrowSchemaCreated marrSchemaTime32Ms(const char *zName, const char *zMetadata,
                                      int64_t flags);
ArrowSchemaCreated marrSchemaTime64Us(const char *zName, const char *zMetadata,
                                      int64_t flags);
ArrowSchemaCreated marrSchemaTime64Ns(const char *zName, const char *zMetadata,
                                      int64_t flags);
ArrowSchemaCreated marrSchemaTimestampS(const char *zName,
                                        const char *zMetadata, int64_t flags,
                                        const char *timezone);
ArrowSchemaCreated marrSchemaTimestampMs(const char *zName,
                                         const char *zMetadata, int64_t flags,
                                         const char *timezone);
ArrowSchemaCreated marrSchemaTimestampUs(const char *zName,
                                         const char *zMetadata, int64_t flags,
                                         const char *timezone);
ArrowSchemaCreated marrSchemaTimestampNs(const char *zName,
                                         const char *zMetadata, int64_t flags,
                                         const char *timezone);
ArrowSchemaCreated marrSchemaDurationS(const char *zName, const char *zMetadata,
                                       int64_t flags);
ArrowSchemaCreated marrSchemaDurationMs(const char *zName,
                                        const char *zMetadata, int64_t flags);
ArrowSchemaCreated marrSchemaDurationUs(const char *zName,
                                        const char *zMetadata, int64_t flags);
ArrowSchemaCreated marrSchemaDurationNs(const char *zName,
                                        const char *zMetadata, int64_t flags);
ArrowSchemaCreated marrSchemaIntervalMonth(const char *zName,
                                           const char *zMetadata,
                                           int64_t flags);
ArrowSchemaCreated marrSchemaIntervalDayTime(const char *zName,
                                             const char *zMetadata,
                                             int64_t flags);
ArrowSchemaCreated marrSchemaIntervalMonthDayNs(const char *zName,
                                                const char *zMetadata,
                                                int64_t flags);
////// Nested types
ArrowSchemaCreated marrSchemaList(const char *zName, const char *zMetadata,
                                  int64_t flags, struct ArrowSchema *child);
ArrowSchemaCreated marrSchemaLargeList(const char *zName, const char *zMetadata,
                                       int64_t flags,
                                       struct ArrowSchema *child);
ArrowSchemaCreated marrSchemaListView(const char *zName, const char *zMetadata,
                                      int64_t flags, struct ArrowSchema *child);
ArrowSchemaCreated marrSchemaLargeListView(const char *zName,
                                           const char *zMetadata, int64_t flags,
                                           struct ArrowSchema *child);
ArrowSchemaCreated marrSchemaFixedList(const char *zName, const char *zMetadata,
                                       int64_t flags, struct ArrowSchema *child,
                                       ptrdiff_t size);
// TODO
ArrowSchemaCreated marrSchemaStruct(const char *zName, const char *zMetadata,
                                    int64_t flags);
ArrowSchemaCreated marrSchemaMap(const char *zName, const char *zMetadata,
                                 int64_t flags);
ArrowSchemaCreated marrSchemaDenseUnion(const char *zName,
                                        const char *zMetadata, int64_t flags);
ArrowSchemaCreated marrSchemaSparseUnion(const char *zName,
                                         const char *zMetadata, int64_t flags);
ArrowSchemaCreated marrSchemaRunEnd(const char *zName, const char *zMetadata,
                                    int64_t flags);

#endif  // MARROW_SCHEMA_H_