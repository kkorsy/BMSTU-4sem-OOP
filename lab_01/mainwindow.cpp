#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "structs.h"
#include "action.h"
#include "error_handler.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	connectSceneToView();
	initCanvas();
	connectMove();
	connectRotate();
	connectScale();
	drawOriginalFigure();
}


void MainWindow::connectSceneToView()
{
	view = ui->graphicsView;
	scene = new QGraphicsScene(this);
	scene->setSceneRect(0, 0, 600, 600);
	view->setScene(scene);
}


canvas_t& MainWindow::initCanvas()
{
	static canvas_t canvas;
	canvas.scene = scene;
	canvas.width = scene->width();
	canvas.height = scene->height();

	return canvas;
}


void MainWindow::connectMove()
{
	connect(ui->move_button, SIGNAL(released()), this, SLOT(move()));
}


void MainWindow::connectRotate()
{
	connect(ui->rotate_button, SIGNAL(released()), this, SLOT(rotate()));
}


void MainWindow::connectScale()
{
	connect(ui->scale_button, SIGNAL(released()), this, SLOT(scale()));
}


void MainWindow::drawOriginalFigure()
{
	request_t request;
	set_request_action(request, LOAD);
    set_request_filename(request, (char *)FILENAME);

	int rc = process_action(request);
	process_error(rc);

	set_request_action(request, DRAW);
	set_request_canvas(request, initCanvas());

	rc = process_action(request);
	process_error(rc);
}


void MainWindow::move()
{
	double move_x = ui->x_move->value();
	double move_y = ui->y_move->value();
	double move_z = ui->z_move->value();

	move_t move;
	set_move(move, move_x, move_y, move_z);

	request_t request;
	set_request_action(request, MOVE);
	set_request_move(request, move);

	int rc = process_action(request);
	process_error(rc);

	set_request_action(request, DRAW);
	set_request_canvas(request, initCanvas());

	rc = process_action(request);
	process_error(rc);
}


void MainWindow::rotate()
{
	double rotate_x = ui->x_rotate->value();
	double rotate_y = ui->y_rotate->value();
	double rotate_z = ui->z_rotate->value();

	rotate_t rotate;
	set_rotate(rotate, rotate_x, rotate_y, rotate_z);

	request_t request;
	set_request_action(request, ROTATE);
	set_request_rotate(request, rotate);

	int rc = process_action(request);
	process_error(rc);

	set_request_action(request, DRAW);
	set_request_canvas(request, initCanvas());

	rc = process_action(request);
	process_error(rc);
}


void MainWindow::scale()
{
	double scale_x = ui->x_scale->value();
	double scale_y = ui->y_scale->value();
	double scale_z = ui->z_scale->value();

	scale_t scale;
	set_scale(scale, scale_x, scale_y, scale_z);

	request_t request;
	set_request_action(request, SCALE);
	set_request_scale(request, scale);

	int rc = process_action(request);
	process_error(rc);

	set_request_action(request, DRAW);
	set_request_canvas(request, initCanvas());

	rc = process_action(request);
	process_error(rc);
}


MainWindow::~MainWindow()
{
	request_t request;
	set_request_action(request, QUIT);

	process_action(request);
    delete ui;
}
