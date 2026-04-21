// -- widgets.h
// 
// Defines the widget interface. Any struct/object implementing the
// interface is used as block in the sway-bar.

#ifndef KENKO_WIDGETS_H
#define KENKO_WIDGETS_H

typedef struct {
  unsigned int r;
  unsigned int g;
  unsigned int b;
  unsigned int a;
} SwayColor;

#define KENKO_NEW_COLOR(R, G, B, A) (SwayColor) { R, G, B, A }

typedef enum {
  LEFT,
  RIGHT,
  CENTER
} SwayAlignment;

typedef enum {
  NONE,
  PANGO
} SwayMarkup;

typedef struct IWidget {
  const char *(*full_text) (void);
  const char *(*short_text) (void);
  
  // foreground and background colors
  const SwayColor (*color) (void);
  const SwayColor (*background) (void);
  
  // borders
  const SwayColor (*border) (void);
  const unsigned int (*border_top) (void);
  const unsigned int (*border_bottom) (void);
  const unsigned int (*border_left) (void);
  const unsigned int (*border_right) (void);
  // TODO: const unsigned int (*min_width) (void);
  const SwayAlignment (*align) (void);

  const char *(*name) (void);
  const char *(*instance) (void);
  const bool (*urgent) (void);
  const bool (*separator) (void);
  const unsigned int (*separator_block_width) (void);
  const SwayMarkup (*markup) (void);
} IWidget;

#define KENKO_EXPAND(...) __VA_ARGS__

// macro that lets the user conviniently declare a new widget type
#define KENKO_DECLARE_WIDGET(widget_name, fields              \
  typedef struct widget_name {                                \
    IWidget *vtable;                                          \
    KENKO_EXPAND fields                                       \
  } widget_name;                                              \
  _Static_assert(offsetof(name, vtable) == 0,                 \
      "Struct " #widget_name " is not suitable widget type.")

#endif // KENKO_WIDGETS_H

