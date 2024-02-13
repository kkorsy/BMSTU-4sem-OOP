#include "drawing.h"
#include "memory.h"
#include "errors.h"


int check_data(edge_t *edge_data, point_t *point_data)
{
	int rc = OK;
	if (!edge_data || !point_data)
		rc = DATA_ERR;

	return rc;
}


int check_count(int count_edges, int count_points)
{
    int rc = OK;
    if (count_edges < 0 || count_points < 0 || count_edges < count_points)
        rc = DATA_ERR;

    return rc;
}


int get_start_vertex(edge_t edge)
{
	return edge.start;
}


int get_end_vertex(edge_t edge)
{
	return edge.end;
}


int get_edge_start(edge_t *data, int index)
{
    if (data == nullptr)
            return -1;

	return get_start_vertex(data[index]);
}


int get_edge_end(edge_t *data, int index)
{
    if (data == nullptr)
            return -1;

	return get_end_vertex(data[index]);
}


point_t& get_point(point_t *data, int index)
{
	return data[index];
}


int copy_points(points_t &dst, points_t &src)
{
	dst.count = src.count;
	int rc = allocate_points(&dst.data, dst.count);
	if (!rc)
		for (int i = 0; i < dst.count; i++)
			get_point(dst.data, i) = get_point(src.data, i);

	return rc;
}


void project_point(point_t &point, canvas_t &canvas)
{
	point.x += canvas.width / 2;
	point.y += canvas.height / 2;
}


void project_figure_points(points_t &points, canvas_t &canvas)
{
	for (int i = 0; i < points.count; i++)
		project_point(get_point(points.data, i), canvas);
}


int draw_edges(edges_t &edges, points_t &points, canvas_t &canvas)
{
    int rc = check_data(edges.data, points.data);

    if (!rc)
    {
        rc = check_count(edges.count, points.count);
        if (!rc)
            for (int i = 0; i < edges.count; i++)
            {
                point_t vertex_a = get_point(points.data, get_edge_start(edges.data, i));
                point_t vertex_b = get_point(points.data, get_edge_end(edges.data, i));
                draw_line(vertex_a, vertex_b, canvas);
            }
    }

	return rc;
}


int draw_figure(figure_t &figure, canvas_t &canvas)
{
	points_t figure_points_copy;

	canvas.scene->clear();
	int rc = copy_points(figure_points_copy, figure.points);
	if (!rc)
	{
		project_figure_points(figure_points_copy, canvas);
		rc = draw_edges(figure.edges, figure_points_copy, canvas);
        free_data(get_points_data(figure_points_copy));
	}

	return rc;
}
