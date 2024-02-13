#include "action.h"
#include "structs.h"
#include "figure.h"
#include "read_data.h"
#include "figure_transform.h"
#include "memory.h"
#include "errors.h"


void set_request_action(request_t &request, action_t action)
{
	request.action = action;
}


void set_request_canvas(request_t &request, canvas_t &canvas)
{
	request.canvas = canvas;
}


void set_request_move(request_t &request, move_t &move)
{
	request.move = move;
}


void set_request_rotate(request_t &request, rotate_t &rotate)
{
	request.rotate = rotate;
}


void set_request_scale(request_t &request, scale_t &scale)
{
	request.scale = scale;
}


void set_request_filename(request_t &request, char *filename)
{
	request.filename = filename;
}


void set_move(move_t &move, double x, double y, double z)
{
	move.dx = x;
	move.dy = y;
	move.dz = z;
}


void set_rotate(rotate_t &rotate, double x, double y, double z)
{
	rotate.rx = x;
	rotate.ry = y;
	rotate.rz = z;
}


void set_scale(scale_t &scale, double x, double y, double z)
{
	scale.kx = x;
	scale.ky = y;
	scale.kz = z;
}


action_t get_request_action(request_t &request)
{
	return request.action;
}


canvas_t& get_request_canvas(request_t &request)
{
	return request.canvas;
}


move_t& get_request_move(request_t &request)
{
	return request.move;
}

rotate_t& get_request_rotate(request_t &request)
{
	return request.rotate;
}

scale_t& get_request_scale(request_t &request)
{
	return request.scale;
}


char* get_request_filename(request_t &request)
{
	return request.filename;
}


int process_action(request_t request)
{
	int rc = OK;
	static figure_t figure = init_figure();
	action_t action = get_request_action(request);

	if (action == LOAD)
		rc = read_figure(figure, get_request_filename(request));
	else if (action == DRAW)
		rc = draw_figure(figure, get_request_canvas(request));
	else if (action == MOVE)
		rc = move_figure(figure, get_request_move(request));
	else if (action == ROTATE)
		rc = rotate_figure(figure, get_request_rotate(request));
	else if (action == SCALE)
		rc = scale_figure(figure, get_request_scale(request));
	else if (action == QUIT)
		free_figure(figure);
	else
		rc = UNKNOWN_ACTION;

	return rc;
}
