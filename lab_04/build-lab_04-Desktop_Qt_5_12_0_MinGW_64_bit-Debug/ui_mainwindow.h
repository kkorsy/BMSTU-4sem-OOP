/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *floors_layout;
    QLabel *floor_label;
    QPushButton *fbtn_10;
    QPushButton *fbtn_09;
    QPushButton *fbtn_08;
    QPushButton *fbtn_07;
    QPushButton *fbtn_06;
    QPushButton *fbtn_05;
    QPushButton *fbtn_04;
    QPushButton *fbtn_03;
    QPushButton *fbtn_02;
    QPushButton *fbtn_01;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(230, 745);
        MainWindow->setMinimumSize(QSize(230, 745));
        MainWindow->setMaximumSize(QSize(230, 745));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        floors_layout = new QVBoxLayout();
        floors_layout->setObjectName(QString::fromUtf8("floors_layout"));
        floor_label = new QLabel(centralwidget);
        floor_label->setObjectName(QString::fromUtf8("floor_label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Fira Code Retina"));
        font.setPointSize(16);
        floor_label->setFont(font);
        floor_label->setAlignment(Qt::AlignCenter);

        floors_layout->addWidget(floor_label);

        fbtn_10 = new QPushButton(centralwidget);
        fbtn_10->setObjectName(QString::fromUtf8("fbtn_10"));
        fbtn_10->setEnabled(true);
        fbtn_10->setMinimumSize(QSize(70, 60));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Chandas"));
        font1.setPointSize(14);
        fbtn_10->setFont(font1);

        floors_layout->addWidget(fbtn_10);

        fbtn_09 = new QPushButton(centralwidget);
        fbtn_09->setObjectName(QString::fromUtf8("fbtn_09"));
        fbtn_09->setMinimumSize(QSize(70, 60));
        fbtn_09->setFont(font1);

        floors_layout->addWidget(fbtn_09);

        fbtn_08 = new QPushButton(centralwidget);
        fbtn_08->setObjectName(QString::fromUtf8("fbtn_08"));
        fbtn_08->setMinimumSize(QSize(70, 60));
        fbtn_08->setFont(font1);

        floors_layout->addWidget(fbtn_08);

        fbtn_07 = new QPushButton(centralwidget);
        fbtn_07->setObjectName(QString::fromUtf8("fbtn_07"));
        fbtn_07->setMinimumSize(QSize(70, 60));
        fbtn_07->setFont(font1);

        floors_layout->addWidget(fbtn_07);

        fbtn_06 = new QPushButton(centralwidget);
        fbtn_06->setObjectName(QString::fromUtf8("fbtn_06"));
        fbtn_06->setMinimumSize(QSize(70, 60));
        fbtn_06->setFont(font1);

        floors_layout->addWidget(fbtn_06);

        fbtn_05 = new QPushButton(centralwidget);
        fbtn_05->setObjectName(QString::fromUtf8("fbtn_05"));
        fbtn_05->setMinimumSize(QSize(70, 60));
        fbtn_05->setFont(font1);

        floors_layout->addWidget(fbtn_05);

        fbtn_04 = new QPushButton(centralwidget);
        fbtn_04->setObjectName(QString::fromUtf8("fbtn_04"));
        fbtn_04->setMinimumSize(QSize(70, 60));
        fbtn_04->setFont(font1);

        floors_layout->addWidget(fbtn_04);

        fbtn_03 = new QPushButton(centralwidget);
        fbtn_03->setObjectName(QString::fromUtf8("fbtn_03"));
        fbtn_03->setMinimumSize(QSize(70, 60));
        fbtn_03->setFont(font1);

        floors_layout->addWidget(fbtn_03);

        fbtn_02 = new QPushButton(centralwidget);
        fbtn_02->setObjectName(QString::fromUtf8("fbtn_02"));
        fbtn_02->setMinimumSize(QSize(70, 60));
        fbtn_02->setFont(font1);

        floors_layout->addWidget(fbtn_02);

        fbtn_01 = new QPushButton(centralwidget);
        fbtn_01->setObjectName(QString::fromUtf8("fbtn_01"));
        fbtn_01->setMinimumSize(QSize(70, 60));
        fbtn_01->setFont(font1);

        floors_layout->addWidget(fbtn_01);


        horizontalLayout->addLayout(floors_layout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "lab_04", nullptr));
        floor_label->setText(QApplication::translate("MainWindow", "\320\255\321\202\320\260\320\266\320\270", nullptr));
        fbtn_10->setText(QApplication::translate("MainWindow", "10", nullptr));
        fbtn_09->setText(QApplication::translate("MainWindow", "9", nullptr));
        fbtn_08->setText(QApplication::translate("MainWindow", "8", nullptr));
        fbtn_07->setText(QApplication::translate("MainWindow", "7", nullptr));
        fbtn_06->setText(QApplication::translate("MainWindow", "6", nullptr));
        fbtn_05->setText(QApplication::translate("MainWindow", "5", nullptr));
        fbtn_04->setText(QApplication::translate("MainWindow", "4", nullptr));
        fbtn_03->setText(QApplication::translate("MainWindow", "3", nullptr));
        fbtn_02->setText(QApplication::translate("MainWindow", "2", nullptr));
        fbtn_01->setText(QApplication::translate("MainWindow", "1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
