// - json.h

#ifndef KENKO_JSON_H
#define KENKO_JSON_H

// TODO:
// - make header
// - make body
// - validations for widgets

const char *kenko_make_header(
    const char header[],
    unsigned int version,
    bool click_events,
    size_t cont_signal,
    size_t stop_signal);

#endif // KENKO_JSON_H

