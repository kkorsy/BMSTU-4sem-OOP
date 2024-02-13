#ifndef DRAWING_H
#define DRAWING_H

#include <QGraphicsScene>
#include "structs.h"
#include "canvas_drawing.h"

int check_data(edge_t *edge_data, point_t *point_data);
point_t& get_point(point_t *data, int index);
int draw_figure(figure_t &figure, canvas_t &canvas);

#endif // DRAWING_H
