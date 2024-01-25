#ifndef MARROW_SCHEMA_H_
#define MARROW_SCHEMA_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "arrow.h"

////// Basic Primitives
bool marr_schema_null(struct ArrowSchema *schema, const char *name,
                      const char *metadata);
bool marr_schema_boolean(struct ArrowSchema *schema, const char *name,
                         const char *metadata, int64_t flags);
bool marr_schema_int8(struct ArrowSchema *schema, const char *name,
                      const char *metadata, int64_t flags);
bool marr_schema_uint8(struct ArrowSchema *schema, const char *name,
                       const char *metadata, int64_t flags);
bool marr_schema_int16(struct ArrowSchema *schema, const char *name,
                       const char *metadata, int64_t flags);
bool marr_schema_uint16(struct ArrowSchema *schema, const char *name,
                        const char *metadata, int64_t flags);
bool marr_schema_int32(struct ArrowSchema *schema, const char *name,
                       const char *metadata, int64_t flags);
bool marr_schema_uint32(struct ArrowSchema *schema, const char *name,
                        const char *metadata, int64_t flags);
bool marr_schema_int64(struct ArrowSchema *schema, const char *name,
                       const char *metadata, int64_t flags);
bool marr_schema_uint64(struct ArrowSchema *schema, const char *name,
                        const char *metadata, int64_t flags);
bool marr_schema_float16(struct ArrowSchema *schema, const char *name,
                         const char *metadata, int64_t flags);
bool marr_schema_float32(struct ArrowSchema *schema, const char *name,
                         const char *metadata, int64_t flags);
bool marr_schema_float64(struct ArrowSchema *schema, const char *name,
                         const char *metadata, int64_t flags);
////// Binaries
bool marr_schema_binary(struct ArrowSchema *schema, const char *name,
                        const char *metadata, int64_t flags);
bool marr_schema_large_binary(struct ArrowSchema *schema, const char *name,
                              const char *metadata, int64_t flags);
bool marr_schema_binary_view(struct ArrowSchema *schema, const char *name,
                             const char *metadata, int64_t flags);
bool marr_schema_utf8(struct ArrowSchema *schema, const char *name,
                      const char *metadata, int64_t flags);
bool marr_schema_large_utf8(struct ArrowSchema *schema, const char *name,
                            const char *metadata, int64_t flags);
bool marr_schema_utf8_view(struct ArrowSchema *schema, const char *name,
                           const char *metadata, int64_t flags);
bool marr_schema_decimal128(struct ArrowSchema *schema, const char *name,
                            const char *metadata, ptrdiff_t precision,
                            ptrdiff_t scale, int64_t flags);
bool marr_schema_decimal(struct ArrowSchema *schema, const char *name,
                         const char *metadata, ptrdiff_t bitwidth,
                         ptrdiff_t precision, ptrdiff_t scale, int64_t flags);
////// Temporals
bool marr_schema_date32(struct ArrowSchema *schema, const char *name,
                        const char *metadata, int64_t flags);
bool marr_schema_date64(struct ArrowSchema *schema, const char *name,
                        const char *metadata, int64_t flags);
bool marr_schema_time32_s(struct ArrowSchema *schema, const char *name,
                          const char *metadata, int64_t flags);
bool marr_schema_time32_ms(struct ArrowSchema *schema, const char *name,
                           const char *metadata, int64_t flags);
bool marr_schema_time64_us(struct ArrowSchema *schema, const char *name,
                           const char *metadata, int64_t flags);
bool marr_schema_time64_ns(struct ArrowSchema *schema, const char *name,
                           const char *metadata, int64_t flags);
bool marr_schema_timestamp_s(struct ArrowSchema *schema, const char *name,
                             const char *metadata, int64_t flags,
                             const char *timezone);
bool marr_schema_timestamp_ms(struct ArrowSchema *schema, const char *name,
                              const char *metadata, int64_t flags,
                              const char *timezone);
bool marr_schema_timestamp_us(struct ArrowSchema *schema, const char *name,
                              const char *metadata, int64_t flags,
                              const char *timezone);
bool marr_schema_timestamp_ns(struct ArrowSchema *schema, const char *name,
                              const char *metadata, int64_t flags,
                              const char *timezone);
bool marr_schema_duration_s(struct ArrowSchema *schema, const char *name,
                            const char *metadata, int64_t flags);
bool marr_schema_duration_ms(struct ArrowSchema *schema, const char *name,
                             const char *metadata, int64_t flags);
bool marr_schema_duration_us(struct ArrowSchema *schema, const char *name,
                             const char *metadata, int64_t flags);
bool marr_schema_duration_ns(struct ArrowSchema *schema, const char *name,
                             const char *metadata, int64_t flags);
bool marr_schema_duration_month(struct ArrowSchema *schema, const char *name,
                                const char *metadata, int64_t flags);
bool marr_schema_duration_day_time(struct ArrowSchema *schema, const char *name,
                                   const char *metadata, int64_t flags);
bool marr_schema_duration_month_day_ns(struct ArrowSchema *schema,
                                       const char *name, const char *metadata,
                                       int64_t flags);
////// Nested types
bool marr_schema_list(struct ArrowSchema *schema, const char *name,
                      const char *metadata, int64_t flags,
                      struct ArrowSchema *child);
bool marr_schema_large_list(struct ArrowSchema *schema, const char *name,
                            const char *metadata, int64_t flags,
                            struct ArrowSchema *child);
bool marr_schema_list_view(struct ArrowSchema *schema, const char *name,
                           const char *metadata, int64_t flags,
                           struct ArrowSchema *child);
bool marr_schema_large_list_view(struct ArrowSchema *schema, const char *name,
                                 const char *metadata, int64_t flags,
                                 struct ArrowSchema *child);
bool marr_schema_fixedlist(struct ArrowSchema *schema, const char *name,
                           const char *metadata, int64_t flags,
                           struct ArrowSchema *child, ptrdiff_t size);
// TODO
bool marr_schema_struct(struct ArrowSchema *schema, const char *name,
                        const char *metadata, int64_t flags);
bool marr_schema_map(struct ArrowSchema *schema, const char *name,
                     const char *metadata, int64_t flags);
bool marr_schema_dense_union(struct ArrowSchema *schema, const char *name,
                             const char *metadata, int64_t flags);
bool marr_schema_sparse_union(struct ArrowSchema *schema, const char *name,
                              const char *metadata, int64_t flags);
bool marr_schema_run_end(struct ArrowSchema *schema, const char *name,
                         const char *metadata, int64_t flags);

#endif  // MARROW_SCHEMA_H_