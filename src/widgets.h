// - widgets.h
// 
// Defines the widget interface. Any struct/object implementing the
// interface is used as block in the sway-bar.

#ifndef KENKO_WIDGETS_H
#define KENKO_WIDGETS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef struct SwayColor {
  unsigned int r;
  unsigned int g;
  unsigned int b;
  unsigned int a;
} SwayColor;

#define KENKO_NEW_COLOR(R, G, B, A) (SwayColor) { R, G, B, A }

typedef enum SwayAlignment {
  ALIGN_LEFT,
  ALIGN_RIGHT,
  ALIGN_CENTER
} SwayAlignment;

typedef enum SwayMarkup {
  MARKUP_NONE,
  MARKUP_PANGO
} SwayMarkup;

typedef enum ResultType {
  RESULT_UINT,
  RESULT_STRING
} ResultType;

typedef struct SwayWidth {
  ResultType kind;
  union {
    const char *str_width;
    uint32_t numeric_width;
  };
} SwayWidth;

#define kenko_new_min_width(t) (SwayWidth) { .kind = t };

typedef struct IWidget IWidget;

struct IWidget {
  const char *(*full_text) (IWidget *self);
  const char *(*short_text) (IWidget *self);
  
  // foreground and background colors
  SwayColor (*color) (IWidget *self);
  SwayColor (*background) (IWidget *self);
  
  // borders
  SwayColor (*border) (IWidget *self);
  unsigned int (*border_top) (IWidget *self);
  unsigned int (*border_bottom) (IWidget *self);
  unsigned int (*border_left) (IWidget *self);
  unsigned int (*border_right) (IWidget *self);
 
  // minimum width and alignment
  SwayWidth (*min_width) (IWidget *self);
  SwayAlignment (*align) (IWidget *self);

  const char *(*name) (IWidget *self);
  const char *(*instance) (IWidget *self);
  bool (*urgent) (IWidget *self);
  bool (*separator) (IWidget *self);
  unsigned int (*separator_block_width) (IWidget *self);
  SwayMarkup (*markup) (IWidget *self);
};

#define KENKO_EXPAND(...) __VA_ARGS__

#define container_of(ptr, type, member)             \
  ((type *)((char *)(ptr) - offsetof(type, member)))

#define get_self(ptr, type) container_of(ptr, type, vtable)
#define get_iwidget(widget_ptr) ((IWidget *)(widget_ptr))



// macro that lets the user conviniently declare a new widget type
#define KENKO_DECLARE_WIDGET(widget_name, fields)             \
  typedef struct widget_name                                  \
  {                                                           \
    IWidget vtable;                                           \
    KENKO_EXPAND fields                                       \
  } widget_name;                                              \
                                                              \
  _Static_assert(offsetof(widget_name, vtable) == 0,          \
      "Struct " #widget_name " is not suitable widget type.")

#endif // KENKO_WIDGETS_H

