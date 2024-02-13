#ifndef MEMORY_H
#define MEMORY_H

#include <stdlib.h>
#include "structs.h"

point_t* get_points_data(points_t &points);
edge_t* get_edges_data(edges_t &edges);
int allocate_points(point_t **data, int count);
int allocate_edges(edge_t **data, int count);
void free_data(void *data);
void free_figure(figure_t &figure);

#endif // MEMORY_H
