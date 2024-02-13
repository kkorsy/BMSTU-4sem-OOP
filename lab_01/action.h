#ifndef ACTION_H
#define ACTION_H

#include "structs.h"
#include "drawing.h"

#define FILENAME "D:\\OOP\\lab_01\\data.txt"

enum action_t
{
	LOAD,
	DRAW,
	MOVE,
	ROTATE,
	SCALE,
	QUIT
};

struct request_t
{
	action_t action;
	canvas_t canvas;
	union
	{
		move_t move;
		rotate_t rotate;
		scale_t scale;
		char *filename;
	};
};

void set_request_action(request_t &request, action_t action);
void set_request_canvas(request_t &request, canvas_t &canvas);
void set_request_move(request_t &request, move_t &move);
void set_request_rotate(request_t &request, rotate_t &rotate);
void set_request_scale(request_t &request, scale_t &scale);
void set_request_filename(request_t &request, char *filename);
void set_move(move_t &move, double x, double y, double z);
void set_rotate(rotate_t &rotate, double x, double y, double z);
void set_scale(scale_t &scale, double x, double y, double z);
int process_action(request_t request);

#endif // ACTION_H
