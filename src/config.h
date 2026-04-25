// - config.h
//
// contains configurations as defined by the user
#ifndef KENKO_CONFIG_H
#define KENKO_CONFIG_H

#define SWAY_HEADER_SIZE 256
#define SWAY_BODY_SIZE   4096

const IWidget *main_array[] = {
  get_iwidget(random_widget),
  get_iwidget(uptime_widget),
  get_iwidget(datetime_widget)
};

#endif // KENKO_CONFIG_H

