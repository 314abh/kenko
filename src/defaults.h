// -- defaults.h
//
// Helpful macros and default values

#ifndef KENKO_DEFAULTS_H
#define KENKO_DEFAULTS_H

#define DEF_TAG "[KENKO]"

#define KENKO_DEFAULT_NAME_TITLE     "[KENKO] default widget"
#define KENKO_DEFAULT_INSTANCE_TITLE "[KENKO] default instance"

/* === default widget functions === */

const char *kenko_default_short_text(IWidget *self);

SwayColor kenko_default_color(IWidget *self);
SwayColor kenko_default_background(IWidget *self);

SwayColor kenko_default_border(IWidget *self);
unsigned int kenko_default_border_top(IWidget *self);
unsigned int kenko_default_border_bottom(IWidget *self);
unsigned int kenko_default_border_left(IWidget *self);
unsigned int kenko_default_border_right(IWidget *self);

SwayWidth kenko_default_min_width(IWidget *self);
SwayAlignment kenko_default_align(IWidget *self);

const char *kenko_default_name(IWidget *self);
const char *kenko_default_instance(IWidget *self);
bool kenko_default_urgent(IWidget *self);
bool kenko_default_separator(IWidget *self);
unsigned int kenko_default_separator_block_width(IWidget *self);
SwayMarkup kenko_default_markup(IWidget *self);

/* ================================ */

#endif // KENKO_DEFAULTS_H

