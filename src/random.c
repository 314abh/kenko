// -- random.c
//
// Widget that generates random numbers.

#include <stdbool.h>
#include <stdlib.h>

#include "random.h"

static IWidget random_vt = {
  .full_text = random_full_text,
  .short_text = random_short_text,
  .color = random_color,
  .background = random_bg,
  .border = random_border,
  .border_top = NULL,
  .border_bottom = NULL,
  .border_left = NULL,
  .border_right = NULL,
  // .min_width = random_min_width,
  .align = NULL,
  .name = NULL,
  .instance = NULL,
  .urgent = NULL,
  .separator = NULL,
  .separator_block_width = NULL,
  .markup = NULL
};

KENKO_DECLARE_WIDGET(RandomWidget,
  (const char *name;
   bool separator;)
);

static RandomWidget random_widget;

RandomWidget *make_random() {
  random_widget.vtable = &random_vt;
  random_widget.name = RANDOM_WIDGET_NAME;
  random_widget.separator = true;

  return &random_widget;
}

static const char *dummy_long  = "12345679";
static const char *dummy_short = "1234";

const char *random_full_text(void) {
  return dummy_long;
}

const char *random_short_text(void) {
  return dummy_short;
}

SwayColor random_color(void) {
  return KENKO_NEW_COLOR(0xFF, 0xFF, 0xFF, 0xFF); // white
}

SwayColor random_bg(void) {
  return KENKO_NEW_COLOR(0x00, 0x00, 0x00, 0x00); // black
}

SwayColor random_border(void) {
  return KENKO_NEW_COLOR(0xFF, 0xFF, 0xFF, 0xFF); // white
}

