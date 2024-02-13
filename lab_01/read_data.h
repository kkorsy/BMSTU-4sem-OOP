#ifndef READ_DATA_H
#define READ_DATA_H

#include <stdio.h>
#include "structs.h"

int read_figure(figure_t &figure, const char *filename);
void replace_figure(figure_t &old_figure, figure_t &new_figure);

#endif // READ_DATA_H
