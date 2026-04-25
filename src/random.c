// - random.c
//
// Widget that generates random numbers.

#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

/* === forward declarations === */

static uint32_t get_seed();
static inline uint32_t xorshift32(uint32_t *state);
static uint32_t randrange(uint32_t *state, uint32_t min, uint32_t max);

const char *random_full_text(IWidget *self);
const char *random_short_text(IWidget *self);
SwayColor random_color(IWidget *self);
SwayColor random_bg(IWidget *self);
SwayColor random_border(IWidget *self);

/* ======================== */

typedef struct RandomWidget {
  IWidget vtable;
  uint32_t seed;
  const char value[8];
  const char name[32];
};

// KENKO_DECLARE_WIDGET(RandomWidget,
//   (uint32_t seed;
//    const char value[8];
//    const char name[32];)
// );

RandomWidget random_widget = {
  .seed = get_seed(),
  .name = "random_widget",
  .vtable = {
    .full_text = random_full_text,
    .short_text = random_short_text,
    .color = random_color,
    .background = random_bg,
    .border = random_border,
    .border_top = NULL,
    .border_bottom = NULL,
    .border_left = NULL,
    .border_right = NULL,
    .min_width = NULL,
    .align = NULL,
    .name = NULL,
    .instance = NULL,
    .urgent = NULL,
    .separator = NULL,
    .separator_block_width = NULL,
    .markup = NULL
  }
};

static uint32_t get_seed() {
  uint32_t seed = time(NULL);
  for (size_t i = 0; i < 100; ++i) seed = xorshift32(&seed);
  return seed;
}

static inline uint32_t xorshift32(uint32_t *state) {
  uint32_t x = *state;

  x ^= x << 13;
  x ^= x >> 17;
  x ^= x <<  5;

  *state = x;
  return x;
}

static uint32_t randrange(uint32_t *state, uint32_t min, uint32_t max) {
  assert(min < max && "randrange: max must be greater than min.");

  uint32_t range = (max - min) + 1;
  uint32_t limit = UINT32_MAX - (UINT32_MAX % range);
  
  uint32_t x;
  do {
    x = xorshift32(state);
  } while (x >= limit);

  return min + (x % range);
}

const char *random_full_text(IWidget *self) {
  RandomWidget *rw = get_self(self, RandomWidget);
  uint32_t seed = rw->seed;
  uint32_t num = randrange(&seed, 1000, 9999);
  snprintf(rw->value, sizeof(rw->value), "%u", num);
  return rw->value;
}

const char *random_short_text(IWidget *self) {
  random_full_text(self);
  RandomWidget *rw = get_self(self, RandomWidget);
  return rw->value;
}

SwayColor random_color(IWidget *self) {
  return KENKO_NEW_COLOR(0xFF, 0xFF, 0xFF, 0xFF); // white
}

SwayColor random_bg(IWidget *self) {
  return KENKO_NEW_COLOR(0x00, 0x00, 0x00, 0x00); // black
}

SwayColor random_border(IWidget *self) {
  return KENKO_NEW_COLOR(0xFF, 0xFF, 0xFF, 0xFF); // white
}

