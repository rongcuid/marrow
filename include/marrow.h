#ifndef MARROW_H_
#define MARROW_H_

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/****** Canonical arrow C interfaces implementation.******/
#ifndef ARROW_C_DATA_INTERFACE
#define ARROW_C_DATA_INTERFACE

#define ARROW_FLAG_DICTIONARY_ORDERED 1
#define ARROW_FLAG_NULLABLE 2
#define ARROW_FLAG_MAP_KEYS_SORTED 4

struct ArrowSchema {
  // Array type description
  const char *format;
  const char *name;
  const char *metadata;
  int64_t flags;
  int64_t n_children;
  struct ArrowSchema **children;
  struct ArrowSchema *dictionary;

  // Release callback
  void (*release)(struct ArrowSchema *);
  // Opaque producer-specific data
  void *private_data;
};

struct ArrowArray {
  // Array data description
  int64_t length;
  int64_t null_count;
  int64_t offset;
  int64_t n_buffers;
  int64_t n_children;
  const void **buffers;
  struct ArrowArray **children;
  struct ArrowArray *dictionary;

  // Release callback
  void (*release)(struct ArrowArray *);
  // Opaque producer-specific data
  void *private_data;
};

#endif  // ARROW_C_DATA_INTERFACE

#ifndef ARROW_C_STREAM_INTERFACE
#define ARROW_C_STREAM_INTERFACE

struct ArrowArrayStream {
  // Callbacks providing stream functionality
  int (*get_schema)(struct ArrowArrayStream *, struct ArrowSchema *out);
  int (*get_next)(struct ArrowArrayStream *, struct ArrowArray *out);
  const char *(*get_last_error)(struct ArrowArrayStream *);

  // Release callback
  void (*release)(struct ArrowArrayStream *);

  // Opaque producer-specific data
  void *private_data;
};

#endif  // ARROW_C_STREAM_INTERFACE

/***** Marrow Begins Here. ******/

////// Arrow C Schema, initializations

/**
 * @brief Initialize schema from an Arrow format string.
 *
 * Refer to Arrow specification for the specification of format string.
 *
 * @param format Format string. Will be copied
 * @param schema Output schema
 * @return true If succeeds
 * @return false If fails
 */
bool marr_schema_from_format(struct ArrowSchema *schema, const char *format);

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
#endif  // MARROW_H_