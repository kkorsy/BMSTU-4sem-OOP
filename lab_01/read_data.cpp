#include "read_data.h"
#include "memory.h"
#include "errors.h"


int get_points_count(points_t &points)
{
	return points.count;
}


void copy_figure(figure_t &dst, figure_t &src)
{
	dst = src;
}


int read_count(int &count, FILE *f)
{
	int rc = OK;

	if (fscanf(f, "%d", &count) != 1)
		rc = READ_ERR;

	return rc;
}


int read_point(point_t &point, FILE *f)
{
	int rc = OK;

	if (fscanf(f, "%lf %lf %lf", &point.x, &point.y, &point.z) != 3)
		rc = READ_ERR;

	return rc;
}


int read_points_array(point_t *arr, int n, FILE *f)
{
	int rc = OK;

	for (int i = 0; !rc && i < n; i++)
		if (read_point(arr[i], f))
			rc = READ_ERR;

	return rc;
}


int read_points(points_t &points, FILE *f)
{
	int rc = OK;

	rc = read_count(points.count, f);
	if (!rc)
		rc = allocate_points(&points.data, points.count);
	if (!rc)
	{
		rc = read_points_array(points.data, points.count, f);
		if (rc)
			free_data(points.data);
	}

	return rc;
}


int read_edge(edge_t &edge, FILE *f)
{
	int rc = OK;

	if (fscanf(f, "%d %d", &edge.start, &edge.end) != 2)
		rc = READ_ERR;

	return rc;
}


int read_edges_array(edge_t *arr, int n, FILE *f)
{
	int rc = OK;

	for (int i = 0; !rc && i < n; i++)
        if (read_edge(arr[i], f))
			rc = READ_ERR;

	return rc;
}


int read_edges(edges_t &edges, FILE *f)
{
	int rc = OK;

	rc = read_count(edges.count, f);
	if (!rc)
		rc = allocate_edges(&edges.data, edges.count);
	if (!rc)
	{
        rc = read_edges_array(edges.data, edges.count, f);
		if (rc)
			free_data(edges.data);
	}

	return rc;
}


void replace_points(points_t &old_points, points_t &new_points)
{
    free_data(get_points_data(old_points));
    old_points = new_points;
}


void replace_edges(edges_t &old_edges, edges_t &new_edges)
{
    free_data(get_edges_data(old_edges));
    old_edges = new_edges;
}


int read_figure(figure_t &figure, const char *filename)
{
	FILE *f = fopen(filename, "r");
    if (f == nullptr)
		return FILE_ERR;

	int rc = OK;
	figure_t temp_figure;

	rc = read_point(temp_figure.center, f);
	if (!rc)
    {
		rc = read_points(temp_figure.points, f);
        if (!rc)
        {
            rc = read_edges(temp_figure.edges, f);
            if (rc)
                free_data(get_points_data(temp_figure.points));
        }
    }
	fclose(f);

	if (!rc)
    {
        replace_points(figure.points, temp_figure.points);
        replace_edges(figure.edges, temp_figure.edges);
    }

	return rc;
}
