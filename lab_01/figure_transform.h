#ifndef FIGURE_TRANSFORM_H
#define FIGURE_TRANSFORM_H

#include "structs.h"

int move_figure(figure_t &figure, move_t &changes);
int rotate_figure(figure_t &figure, rotate_t &changes);
int scale_figure(figure_t &figure, scale_t &changes);

#endif // FIGURE_TRANSFORM_H
