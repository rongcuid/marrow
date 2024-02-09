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
#include "schema/primitive.h"  // IWYU: export

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