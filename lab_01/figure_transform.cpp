#include <math.h>
#include "figure_transform.h"
#include "drawing.h"
#include "memory.h"


double degrees_to_radians(double degrees)
{
	return degrees * (M_PI / 180);
}


point_t get_point_copy(point_t point)
{
	static point_t copy;
	copy.x = point.x;
	copy.y = point.y;
	copy.z = point.z;

	return copy;
}


void sub_center(point_t &point, point_t &center)
{
	point.x -= center.x;
	point.y -= center.y;
	point.z -= center.z;
}


void add_center(point_t &point, point_t &center)
{
	point.x += center.x;
	point.y += center.y;
	point.z += center.z;
}


void move_point(point_t &point, move_t &changes)
{
	point.x += changes.dx;
	point.y += changes.dy;
	point.z += changes.dz;
}


void move_points(points_t &points, move_t &changes)
{
	for (int i = 0; i < points.count; i++)
		move_point(get_point(points.data, i), changes);
}


int move_figure(figure_t &figure, move_t &changes)
{
	int rc = check_data(get_edges_data(figure.edges), get_points_data(figure.points));
	if (!rc)
	{
		move_points(figure.points, changes);
		move_point(figure.center, changes);
	}

	return rc;
}


void x_rotation(point_t &point, rotate_t &changes)
{
	point_t tmp = get_point_copy(point);
	double radians = degrees_to_radians(changes.rx);

	point.y = tmp.y * cos(radians) + tmp.z * sin(radians);
	point.z = -tmp.y * sin(radians) + tmp.z * cos(radians);
}


void y_rotation(point_t &point, rotate_t &changes)
{
	point_t tmp = get_point_copy(point);
	double radians = degrees_to_radians(changes.ry);

	point.x = tmp.x * cos(radians) + tmp.z * sin(radians);
	point.z = -tmp.x * sin(radians) + tmp.z * cos(radians);
}


void z_rotation(point_t &point, rotate_t &changes)
{
	point_t tmp = get_point_copy(point);
	double radians = degrees_to_radians(changes.rz);

	point.x = tmp.x * cos(radians) + tmp.y * sin(radians);
	point.y = -tmp.x * sin(radians) + tmp.y * cos(radians);
}


void rotate_point(point_t &point, point_t &center, rotate_t &changes)
{
	sub_center(point, center);

	x_rotation(point, changes);
	y_rotation(point, changes);
	z_rotation(point, changes);

	add_center(point, center);
}


void rotate_points(points_t &points, point_t &center, rotate_t &changes)
{
	for (int i = 0; i < points.count; i++)
		rotate_point(get_point(points.data, i), center, changes);
}


int rotate_figure(figure_t &figure, rotate_t &changes)
{
	int rc = check_data(get_edges_data(figure.edges), get_points_data(figure.points));
	if (!rc)
		rotate_points(figure.points, figure.center, changes);

	return rc;
}


void scale_point(point_t &point, point_t &center, scale_t &changes)
{
	point.x = changes.kx * (point.x - center.x) + center.x;
	point.y = changes.ky * (point.y - center.y) + center.y;
	point.z = changes.kz * (point.z - center.z) + center.z;
}


void scale_points(points_t &points, point_t &center, scale_t &changes)
{
	for (int i = 0; i < points.count; i++)
		scale_point(get_point(points.data, i), center, changes);
}


int scale_figure(figure_t &figure, scale_t &changes)
{
	int rc = check_data(get_edges_data(figure.edges), get_points_data(figure.points));
	if (!rc)
		scale_points(figure.points, figure.center, changes);

	return rc;
}
