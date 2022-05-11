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
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PlaneGameClass
{
public:
    QAction *actionNewGame;
    QAction *actionPauseGame;
    QAction *action_easy;
    QAction *action_mid;
    QAction *action_hard;
    QAction *actionStartGame;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PlaneGameClass)
    {
        if (PlaneGameClass->objectName().isEmpty())
            PlaneGameClass->setObjectName(QString::fromUtf8("PlaneGameClass"));
        PlaneGameClass->resize(600, 400);
        actionNewGame = new QAction(PlaneGameClass);
        actionNewGame->setObjectName(QString::fromUtf8("actionNewGame"));
        actionPauseGame = new QAction(PlaneGameClass);
        actionPauseGame->setObjectName(QString::fromUtf8("actionPauseGame"));
        action_easy = new QAction(PlaneGameClass);
        action_easy->setObjectName(QString::fromUtf8("action_easy"));
        action_mid = new QAction(PlaneGameClass);
        action_mid->setObjectName(QString::fromUtf8("action_mid"));
        action_hard = new QAction(PlaneGameClass);
        action_hard->setObjectName(QString::fromUtf8("action_hard"));
        actionStartGame = new QAction(PlaneGameClass);
        actionStartGame->setObjectName(QString::fromUtf8("actionStartGame"));
        centralWidget = new QWidget(PlaneGameClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        PlaneGameClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PlaneGameClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menu_2);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        PlaneGameClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PlaneGameClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        PlaneGameClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PlaneGameClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        PlaneGameClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionStartGame);
        menu->addAction(actionNewGame);
        menu->addAction(actionPauseGame);
        menu_2->addAction(menu_3->menuAction());
        menu_3->addAction(action_easy);
        menu_3->addAction(action_mid);
        menu_3->addAction(action_hard);

        retranslateUi(PlaneGameClass);

        QMetaObject::connectSlotsByName(PlaneGameClass);
    } // setupUi

    void retranslateUi(QMainWindow *PlaneGameClass)
    {
        PlaneGameClass->setWindowTitle(QCoreApplication::translate("PlaneGameClass", "PlaneGame", nullptr));
        actionNewGame->setText(QCoreApplication::translate("PlaneGameClass", "\346\226\260\346\270\270\346\210\217", nullptr));
        actionPauseGame->setText(QCoreApplication::translate("PlaneGameClass", "\346\232\202\345\201\234\346\270\270\346\210\217", nullptr));
        action_easy->setText(QCoreApplication::translate("PlaneGameClass", "\347\256\200\345\215\225", nullptr));
        action_mid->setText(QCoreApplication::translate("PlaneGameClass", "\344\270\255\347\255\211", nullptr));
        action_hard->setText(QCoreApplication::translate("PlaneGameClass", "\345\233\260\351\232\276", nullptr));
        actionStartGame->setText(QCoreApplication::translate("PlaneGameClass", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        menu->setTitle(QCoreApplication::translate("PlaneGameClass", "\350\217\234\345\215\225", nullptr));
        menu_2->setTitle(QCoreApplication::translate("PlaneGameClass", "\345\267\245\345\205\267", nullptr));
        menu_3->setTitle(QCoreApplication::translate("PlaneGameClass", "\351\232\276\345\272\246\351\200\211\346\213\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlaneGameClass: public Ui_PlaneGameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANEGAME_H
