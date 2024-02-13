#include "figure.h"
#include <stdio.h>


void init_point(point_t &point)
{
	point.x = 0;
	point.y = 0;
	point.z = 0;
}


void init_points(points_t &points)
{
    points.data = nullptr;
	points.count = 0;
}


void init_edges(edges_t &edges)
{
    edges.data = nullptr;
	edges.count = 0;
}


figure_t init_figure()
{
	static figure_t figure;

	init_point(figure.center);
	init_points(figure.points);
	init_edges(figure.edges);

	return figure;
}
