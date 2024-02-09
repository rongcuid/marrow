#ifndef MARROW_SCHEMA_PRIMITIVE_H_
#define MARROW_SCHEMA_PRIMITIVE_H_

#include <stddef.h>
#include <stdint.h>

#include "result.h"

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

#endif  // MARROW_SCHEMA_PRIMITIVE_H_