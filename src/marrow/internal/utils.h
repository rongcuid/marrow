#ifndef MARROW_UTILS_H_
#define MARROW_UTILS_H_

#include <stdbool.h>

#include "marrow/arrow.h"

/**
 * @brief Clones a null-terminated string. May allocate memory.
 *
 * @param pNewStr Newly allocated string, or NULL if `*str` is NULL.
 * @param zStr C string to be cloned. May be NULL
 * @return Success
 */
bool marrCloneCStr(char **pNewStr, const char *zStr);

void schemaReleaseRecursive(struct ArrowSchema *pSchema);
void schemaReleaseRecursiveFormatted(struct ArrowSchema *pSchema);

#endif