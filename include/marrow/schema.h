/**
 * @file schema.h
 * @author Rongcui Dong (rongcuid@outlook.com)
 * @brief Low level schema manipulation functions
 * @version 0.1
 * @date 2024-01-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef MARROW_SCHEMA_H_
#define MARROW_SCHEMA_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "marrow/arrow.h"

////// Primitives
typedef struct {
  bool ok;
  union {
    struct ArrowSchema value;
    int32_t _err_reserved;
  };
} MarrSchemaCreated;
MarrSchemaCreated marrSchemaNull(const char *zName, const char *zMetadata,
                                 int64_t flags);
MarrSchemaCreated marrSchemaBoolean(const char *zName, const char *zMetadata,
                                    int64_t flags);
MarrSchemaCreated marrSchemaInt8(const char *zName, const char *zMetadata,
                                 int64_t flags);
MarrSchemaCreated marrSchemaUInt8(const char *zName, const char *zMetadata,
                                  int64_t flags);
MarrSchemaCreated marrSchemaInt16(const char *zName, const char *zMetadata,
                                  int64_t flags);
MarrSchemaCreated marrSchemaUInt16(const char *zName, const char *zMetadata,
                                   int64_t flags);
MarrSchemaCreated marrSchemaInt32(const char *zName, const char *zMetadata,
                                  int64_t flags);
MarrSchemaCreated marrSchemaUInt32(const char *zName, const char *zMetadata,
                                   int64_t flags);
MarrSchemaCreated marrSchemaInt64(const char *zName, const char *zMetadata,
                                  int64_t flags);
MarrSchemaCreated marrSchemaUInt64(const char *zName, const char *zMetadata,
                                   int64_t flags);
MarrSchemaCreated marrSchemaFloat16(const char *zName, const char *zMetadata,
                                    int64_t flags);
MarrSchemaCreated marrSchemaFloat32(const char *zName, const char *zMetadata,
                                    int64_t flags);
MarrSchemaCreated marrSchemaFloat64(const char *zName, const char *zMetadata,
                                    int64_t flags);
MarrSchemaCreated marrSchemaBinary(const char *zName, const char *zMetadata,
                                   int64_t flags);
MarrSchemaCreated marrSchemaLargeBinary(const char *zName,
                                        const char *zMetadata, int64_t flags);
MarrSchemaCreated marrSchemaBinaryView(const char *zName, const char *zMetadata,
                                       int64_t flags);
MarrSchemaCreated marrSchemaUtf8(const char *zName, const char *zMetadata,
                                 int64_t flags);
MarrSchemaCreated marrSchemaLargeUtf8(const char *zName, const char *zMetadata,
                                      int64_t flags);
MarrSchemaCreated marrSchemaUtf8View(const char *zName, const char *zMetadata,
                                     int64_t flags);
MarrSchemaCreated marrSchemaDecimal128(const char *zName, const char *zMetadata,
                                       int64_t flags, ptrdiff_t precision,
                                       ptrdiff_t scale);
MarrSchemaCreated marrSchemaDecimal(const char *zName, const char *zMetadata,
                                    int64_t flags, ptrdiff_t precision,
                                    ptrdiff_t scale, ptrdiff_t bitwidth);
MarrSchemaCreated marrSchemaDate32(const char *zName, const char *zMetadata,
                                   int64_t flags);
MarrSchemaCreated marrSchemaDate64(const char *zName, const char *zMetadata,
                                   int64_t flags);
MarrSchemaCreated marrSchemaTime32S(const char *zName, const char *zMetadata,
                                    int64_t flags);
MarrSchemaCreated marrSchemaTime32Ms(const char *zName, const char *zMetadata,
                                     int64_t flags);
MarrSchemaCreated marrSchemaTime64Us(const char *zName, const char *zMetadata,
                                     int64_t flags);
MarrSchemaCreated marrSchemaTime64Ns(const char *zName, const char *zMetadata,
                                     int64_t flags);
MarrSchemaCreated marrSchemaTimestampS(const char *zName, const char *zMetadata,
                                       int64_t flags, const char *timezone);
MarrSchemaCreated marrSchemaTimestampMs(const char *zName,
                                        const char *zMetadata, int64_t flags,
                                        const char *timezone);
MarrSchemaCreated marrSchemaTimestampUs(const char *zName,
                                        const char *zMetadata, int64_t flags,
                                        const char *timezone);
MarrSchemaCreated marrSchemaTimestampNs(const char *zName,
                                        const char *zMetadata, int64_t flags,
                                        const char *timezone);
MarrSchemaCreated marrSchemaDurationS(const char *zName, const char *zMetadata,
                                      int64_t flags);
MarrSchemaCreated marrSchemaDurationMs(const char *zName, const char *zMetadata,
                                       int64_t flags);
MarrSchemaCreated marrSchemaDurationUs(const char *zName, const char *zMetadata,
                                       int64_t flags);
MarrSchemaCreated marrSchemaDurationNs(const char *zName, const char *zMetadata,
                                       int64_t flags);
MarrSchemaCreated marrSchemaIntervalMonth(const char *zName,
                                          const char *zMetadata, int64_t flags);
MarrSchemaCreated marrSchemaIntervalDayTime(const char *zName,
                                            const char *zMetadata,
                                            int64_t flags);
MarrSchemaCreated marrSchemaIntervalMonthDayNs(const char *zName,
                                               const char *zMetadata,
                                               int64_t flags);
////// Nested types
MarrSchemaCreated marrSchemaList(const char *zName, const char *zMetadata,
                                 int64_t flags, struct ArrowSchema *child);
MarrSchemaCreated marrSchemaLargeList(const char *zName, const char *zMetadata,
                                      int64_t flags, struct ArrowSchema *child);
MarrSchemaCreated marrSchemaListView(const char *zName, const char *zMetadata,
                                     int64_t flags, struct ArrowSchema *child);
MarrSchemaCreated marrSchemaLargeListView(const char *zName,
                                          const char *zMetadata, int64_t flags,
                                          struct ArrowSchema *child);
MarrSchemaCreated marrSchemaFixedList(const char *zName, const char *zMetadata,
                                      int64_t flags, struct ArrowSchema *child,
                                      ptrdiff_t size);
// TODO
MarrSchemaCreated marrSchemaStruct(const char *zName, const char *zMetadata,
                                   int64_t flags);
MarrSchemaCreated marrSchemaMap(const char *zName, const char *zMetadata,
                                int64_t flags);
MarrSchemaCreated marrSchemaDenseUnion(const char *zName, const char *zMetadata,
                                       int64_t flags);
MarrSchemaCreated marrSchemaSparseUnion(const char *zName,
                                        const char *zMetadata, int64_t flags);
MarrSchemaCreated marrSchemaRunEnd(const char *zName, const char *zMetadata,
                                   int64_t flags);

#endif  // MARROW_SCHEMA_H_