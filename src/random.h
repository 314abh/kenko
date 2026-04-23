#ifndef RANDOM_WIDGET_H
#define RANDOM_WIDGET_H

#include "widgets.h"

#define RANDOM_WIDGET_NAME "[kenko] RANDOM_WIDGET"

const char *random_full_text(void);
const char *random_short_text(void);
SwayColor   random_color(void);
SwayColor   random_bg(void);
SwayColor   random_border(void);

#endif // RANDOM_WIDGET_H

