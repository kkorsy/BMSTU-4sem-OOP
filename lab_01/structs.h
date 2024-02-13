#ifndef STRUCTS_H
#define STRUCTS_H

struct point_t
{
	double x;
	double y;
	double z;
};

struct edge_t
{
	int start;
	int end;
};

struct points_t
{
	point_t *data;
	int count;
};

struct edges_t
{
	edge_t *data;
	int count;
};

struct figure_t
{
	point_t center;
	points_t points;
	edges_t edges;
};


struct move_t
{
	double dx;
	double dy;
	double dz;
};


struct scale_t
{
	double kx;
	double ky;
	double kz;
};


struct rotate_t
{
	double rx;
	double ry;
	double rz;
};


#endif // STRUCTS_H
