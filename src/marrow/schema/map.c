#include "marrow/schema/map.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "internal/utils.h"

MarrSchemaCreated marrSchemaMap(const char *zName, const char *zMetadata,
                                int64_t flags, struct ArrowSchema *mKey,
                                struct ArrowSchema *mValue) {}