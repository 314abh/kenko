// - json.c

#include "json.h"

_Static_assert(SWAY_HEADER_SIZE > 0,
    "SWAY_HEADER_SIZE must be an unsigned integer type with value greater than zero.");
const char kenko_header[SWAY_HEADER_SIZE];

_Static_assert(SWAY_BODY_SIZE > 0,
    "SWAY_BODY_SIZE must be an unsigned integer type with value greater than zero.");
const char kenko_body[SWAY_BODY_SIZE];

#define KENKO_HEADER_FORMAT \
  "{\"version\":%lu,\"click_events\":%s,\"cont_signal\":%lu,\"stop_signal\":%lu}\n"

const char *kenko_make_header(
    const char header[],
    unsigned int version,
    bool click_events,
    size_t cont_signal,
    size_t stop_signal) {
  size_t header_size = sizeof(header);
  size_t written_bytes = snprintf(header, header_size,
      KENKO_HEADER_FORMAT, version, (click_events ? "true" : "false),
      cont_signal, stop_signal);
  
  if (written_bytes >= header_size)
    fprintf(stderr, "[warning] header trunucated.");

  return header;
}



