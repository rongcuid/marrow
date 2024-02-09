#ifndef MARROW_SCHEMA_STRUCT_H_
#define MARROW_SCHEMA_STRUCT_H_

#include <stddef.h>

#include "result.h"

MarrSchemaCreated marrSchemaStruct(const char *zName, const char *zMetadata,
                                   int64_t flags, struct ArrowSchema **pmFields,
                                   ptrdiff_t fieldCount);

#endif  // MARROW_SCHEMA_STRUCT_H_