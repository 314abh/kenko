// -- random.c
//
// Widget that generates random numbers.

#include <stdbool.h>

#include "random.h"
#include "widgets.h"

#define RANDOM_WIDGET_NAME DEF_TAG " " "RANDOM_WIDGET"

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
   const bool separator;)
);

typedef struct RandomWidget {
  IWidget *vtable;
  const char *name;
  const bool separator;
} RandomWidget;

static RandomWidget random_widget;

RandomWidget *make_random() {
  random_widget->vtable = random_vt;
  random_widget->name = RANDOM_WIDGET_NAME;
  random_widget->separator = true;

  return random_widget;
}

static const char *dummy_long  = "12345679";
static const char *dummy_short = "1234";

const char *random_full_text() {
  return dummy_long;
}

const char *random_short_text() {
  return dummy_short;
}

SwayColor random_color() {
  return KENKO_NEW_COLOR(0xFF, 0xFF, 0xFF, 0xFF); // white
}

SwayColor random_bg() {
  return KENKO_NEW_COLOR(0x00, 0x00, 0x00, 0x00); // black
}

SwayColor random_border() {
  return KENKO_NEW_COLOR(0xFF, 0xFF, 0xFF, 0xFF); // white
}

