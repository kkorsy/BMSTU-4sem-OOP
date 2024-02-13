#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "drawing.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
	void connectSceneToView();
	canvas_t& initCanvas();
	void connectMove();
	void connectRotate();
	void connectScale();
	void move();
	void rotate();
	void scale();
	void drawOriginalFigure();

private:
    Ui::MainWindow *ui;
	QGraphicsScene *scene;
	QGraphicsView *view;
	canvas_t canvas;
};

#endif // MAINWINDOW_H
