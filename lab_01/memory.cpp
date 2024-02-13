#include "memory.h"
#include "errors.h"


point_t* get_points_data(points_t &points)
{
	return points.data;
}


edge_t* get_edges_data(edges_t &edges)
{
	return edges.data;
}


int allocate_points(point_t **data, int count)
{
	int rc = OK;

	point_t *tmp = (point_t *)malloc(sizeof(point_t) * count);
	if (!tmp)
		rc = MEM_ERR;
	else
		*data = tmp;

	return rc;
}


int allocate_edges(edge_t **data, int count)
{
	int rc = OK;

	edge_t *tmp = (edge_t *)malloc(sizeof(edge_t) * count);
	if (!tmp)
		rc = MEM_ERR;
	else
		*data = tmp;

	return rc;
}


void free_data(void *data)
{
	free(data);
}


void free_figure(figure_t &figure)
{
	free_data(get_points_data(figure.points));
	free_data(get_edges_data(figure.edges));
}
