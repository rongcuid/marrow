#ifndef MARROW_SCHEMA_LIST_H_
#define MARROW_SCHEMA_LIST_H_

#include <stddef.h>

#include "result.h"

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
#endif  // MARROW_SCHEMA_LIST_H_