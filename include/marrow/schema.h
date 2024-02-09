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
// Primitive types
#include "schema/primitive.h"  // IWYU pragma: export
// Nested types
#include "schema/list.h"    // IWYU pragma: export
#include "schema/struct.h"  // IWYU pragma: export

// TODO

MarrSchemaCreated marrSchemaDenseUnion(const char *zName, const char *zMetadata,
                                       int64_t flags);
MarrSchemaCreated marrSchemaSparseUnion(const char *zName,
                                        const char *zMetadata, int64_t flags);
MarrSchemaCreated marrSchemaRunEnd(const char *zName, const char *zMetadata,
                                   int64_t flags);

#endif  // MARROW_SCHEMA_H_