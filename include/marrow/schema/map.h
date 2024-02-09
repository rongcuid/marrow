#ifndef MARROW_SCHEMA_MAP_H_
#define MARROW_SCHEMA_MAP_H_

#include <stdint.h>

#include "marrow/arrow.h"
#include "result.h"

MarrSchemaCreated marrSchemaMap(const char *zName, const char *zMetadata,
                                int64_t flags, struct ArrowSchema *mKey,
                                struct ArrowSchema *mValue);

#endif  // MARROW_SCHEMA_MAP_H_