#ifndef CANVAS_DRAWING_H
#define CANVAS_DRAWING_H

#include <QGraphicsScene>
#include "structs.h"

struct canvas_t
{
    QGraphicsScene *scene;
    int width;
    int height;
};

void draw_line(point_t &point_a, point_t &point_b, canvas_t &canvas);

#endif // CANVAS_DRAWING_H
