#include "canvas_drawing.h"
#include "structs.h"


void draw_line(point_t &point_a, point_t &point_b, canvas_t &canvas)
{
    canvas.scene->addLine(point_a.x, point_a.y, point_b.x, point_b.y);
}
