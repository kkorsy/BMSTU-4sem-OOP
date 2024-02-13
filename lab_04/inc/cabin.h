#pragma once

#include <QObject>

#include "constants.h"
#include "controller.h"
#include "doors.h"

class Cabin : public QObject 
{
Q_OBJECT

    enum CabinState
    {
        MOVE,
        STOPPED,
        LOCKED,
        UNLOCKED,
        PREPARE 
    };

public:
    explicit Cabin(QObject *parent = nullptr);

signals:
    void prepared();                // Cabin::cabin_move
    void floor_passed(int floor);   // Controller::target_setting
    void need_floor(int floor);     // Cabin::cabin_stopped
    void stopped(int floor);        // Cabin::cabin_lock
    void unlocked();                // Controller::target_updating
    void locked();                  // Doors::doors_opening

public slots:
    void cabin_prepare(int floor, Direction dir);
    void cabin_move();
    void cabin_stopped();
    void cabin_lock();
    void cabin_unlock();

private:
    int curr_floor;
    int target_floor;

    CabinState state;
    Direction direction;
    Doors doors;
    QTimer pass_floor_timer;
};
