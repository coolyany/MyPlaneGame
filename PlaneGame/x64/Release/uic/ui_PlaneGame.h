/********************************************************************************
** Form generated from reading UI file 'PlaneGame.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANEGAME_H
#define UI_PLANEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlaneGameClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PlaneGameClass)
    {
        if (PlaneGameClass->objectName().isEmpty())
            PlaneGameClass->setObjectName(QString::fromUtf8("PlaneGameClass"));
        PlaneGameClass->resize(600, 400);
        centralWidget = new QWidget(PlaneGameClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        PlaneGameClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PlaneGameClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        PlaneGameClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PlaneGameClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PlaneGameClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PlaneGameClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PlaneGameClass->setStatusBar(statusBar);

        retranslateUi(PlaneGameClass);

        QMetaObject::connectSlotsByName(PlaneGameClass);
    } // setupUi

    void retranslateUi(QMainWindow *PlaneGameClass)
    {
        PlaneGameClass->setWindowTitle(QCoreApplication::translate("PlaneGameClass", "PlaneGame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaneGameClass: public Ui_PlaneGameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANEGAME_H
