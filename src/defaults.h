// -- defaults.h
//
// Helpful macros and default values

#ifndef KENKO_DEFAULTS_H
#define KENKO_DEFAULTS_H

#define DEF_TAG "[KENKO]"

#define KENKO_DEFAULT_NAME_TITLE     "[KENKO] default widget"
#define KENKO_DEFAULT_INSTANCE_TITLE "[KENKO] default instance"

/* === default widget functions === */

const char *kenko_default_short_text(void);

SwayColor kenko_default_color(void);
SwayColor kenko_default_background(void);

SwayColor kenko_default_border(void);
unsigned int kenko_default_border_top(void);
unsigned int kenko_default_border_bottom(void);
unsigned int kenko_default_border_left(void);
unsigned int kenko_default_border_right(void);

SwayWidth kenko_default_min_width(void);
SwayAlignment kenko_default_align(void);

const char *kenko_default_name(void);
const char *kenko_default_instance(void);
bool kenko_default_urgent(void);
bool kenko_default_separator(void);
unsigned int kenko_default_separator_block_width(void);
SwayMarkup kenko_default_markup(void);

/* ================================ */

#endif // KENKO_DEFAULTS_H

