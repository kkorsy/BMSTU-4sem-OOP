QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    action.cpp \
    drawing.cpp \
    error_handler.cpp \
    figure.cpp \
    figure_transform.cpp \
    main.cpp \
    mainwindow.cpp \
    memory.cpp \
    read_data.cpp \
    canvas_drawing.cpp

HEADERS += \
    action.h \
    drawing.h \
    error_handler.h \
    errors.h \
    figure.h \
    figure_transform.h \
    mainwindow.h \
    memory.h \
    read_data.h \
    structs.h \
    canvas_drawing.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
	data.txt
