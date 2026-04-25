// - defaults.c

#include <stdbool.h>

#include "widgets.h"
#include "defaults.h"

const char *kenko_default_short_text(IWidget *self) {
  return "<short text missing>";
}

SwayColor kenko_default_color(IWidget *self) {
  return KENKO_NEW_COLOR(0xFF, 0xFF, 0xFF, 0xFF); // white
}

SwayColor kenko_default_background(IWidget *self) {
  return KENKO_NEW_COLOR(0x00, 0x00, 0x00, 0xFF); // black
}

SwayColor kenko_default_border(IWidget *self) {
  return KENKO_NEW_COLOR(0xFF, 0xFF, 0xFF, 0xFF); // white 
}

unsigned int kenko_default_border_top(IWidget *self)    { return 1; }
unsigned int kenko_default_border_bottom(IWidget *self) { return 1; }
unsigned int kenko_default_border_left(IWidget *self)   { return 1; }
unsigned int kenko_default_border_right(IWidget *self)  { return 1; }

SwayWidth kenko_default_min_width(IWidget *self) {
  return (SwayWidth) {
    .kind = RESULT_UINT,
    .numeric_width = 10
  };
}

SwayAlignment kenko_default_align(IWidget *self) {
  return ALIGN_CENTER;
}

const char *kenko_default_name(IWidget *self) {
  return KENKO_DEFAULT_NAME_TITLE;
}

const char *kenko_default_instance(IWidget *self) {
  return KENKO_DEFAULT_INSTANCE_TITLE;
}

bool kenko_default_urgent(IWidget *self) {
  return false;
}

bool kenko_default_separator(IWidget *self) {
  return true;
}

unsigned int kenko_default_separator_block_width(IWidget *self) {
  return 9;
}

SwayMarkup kenko_default_markup(IWidget *self) {
  return MARKUP_NONE;
}

