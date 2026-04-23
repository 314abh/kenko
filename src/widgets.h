// -- widgets.h
// 
// Defines the widget interface. Any struct/object implementing the
// interface is used as block in the sway-bar.

#ifndef KENKO_WIDGETS_H
#define KENKO_WIDGETS_H

#include <stdbool.h>
#include <stddef.h>

typedef struct SwayColor {
  unsigned int r;
  unsigned int g;
  unsigned int b;
  unsigned int a;
} SwayColor;

#define KENKO_NEW_COLOR(R, G, B, A) (SwayColor) { R, G, B, A }

typedef enum {
  ALIGN_LEFT,
  ALIGN_RIGHT,
  ALIGN_CENTER
} SwayAlignment;

typedef enum {
  MARKUP_NONE,
  MARKUP_PANGO
} SwayMarkup;

typedef struct IWidget {
  const char *(*full_text) (void);
  const char *(*short_text) (void);
  
  // foreground and background colors
  SwayColor (*color) (void);
  SwayColor (*background) (void);
  
  // borders
  SwayColor (*border) (void);
  unsigned int (*border_top) (void);
  unsigned int (*border_bottom) (void);
  unsigned int (*border_left) (void);
  unsigned int (*border_right) (void);
  // TODO: const unsigned int (*min_width) (void);
  SwayAlignment (*align) (void);

  const char *(*name) (void);
  const char *(*instance) (void);
  bool (*urgent) (void);
  bool (*separator) (void);
  unsigned int (*separator_block_width) (void);
  SwayMarkup (*markup) (void);
} IWidget;

#define KENKO_EXPAND(...) __VA_ARGS__

// macro that lets the user conviniently declare a new widget type
#define KENKO_DECLARE_WIDGET(widget_name, fields)             \
  typedef struct widget_name {                                \
    IWidget *vtable;                                          \
    KENKO_EXPAND fields                                       \
  } widget_name;                                              \
  _Static_assert(offsetof(widget_name, vtable) == 0,          \
      "Struct " #widget_name " is not suitable widget type.")

#endif // KENKO_WIDGETS_H

