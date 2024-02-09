#ifndef MARROW_SCHEMA_RESULT_H_
#define MARROW_SCHEMA_RESULT_H_

#include <stdbool.h>
#include <stdint.h>

#include "marrow/arrow.h"

typedef struct {
  bool ok;
  union {
    struct ArrowSchema value;
    int32_t _err_reserved;
  };
} MarrSchemaCreated;

#endif  // MARROW_SCHEMA_RESULT_H_