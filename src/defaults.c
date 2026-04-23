// - defaults.c

#include <stdbool.h>

#include "widgets.h"
#include "defaults.h"

const char *kenko_default_short_text(void)
{
  return "<short text missing>";
}

SwayColor kenko_default_color(void)
{
  return KENKO_NEW_COLOR(0xFF, 0xFF, 0xFF, 0xFF); // white
}

SwayColor kenko_default_background(void)
{
  return KENKO_NEW_COLOR(0x00, 0x00, 0x00, 0xFF); // black
}

SwayColor kenko_default_border(void)
{
  return KENKO_NEW_COLOR(0xFF, 0xFF, 0xFF, 0xFF); // white 
}

unsigned int kenko_default_border_top(void)    { return 1; }
unsigned int kenko_default_border_bottom(void) { return 1; }
unsigned int kenko_default_border_left(void)   { return 1; }
unsigned int kenko_default_border_right(void)  { return 1; }

const char *kenko_default_name(void)
{
  return KENKO_DEFAULT_NAME_TITLE;
}

const char *kenko_default_instance(void)
{
  return KENKO_DEFAULT_INSTANCE_TITLE;
}
bool kenko_default_urgent(void)
{
  return false;
}

bool kenko_default_separator(void)
{
  return true;
}

unsigned int kenko_default_separator_block_width(void)
{
  return 9;
}

SwayMarkup kenko_default_markup(void)
{
  return MARKUP_NONE;
}

