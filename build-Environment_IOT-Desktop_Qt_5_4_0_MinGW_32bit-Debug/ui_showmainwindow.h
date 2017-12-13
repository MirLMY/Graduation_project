/********************************************************************************
** Form generated from reading UI file 'showmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWMAINWINDOW_H
#define UI_SHOWMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowMainWindow
{
public:
    QWidget *centralwidget;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ShowMainWindow)
    {
        if (ShowMainWindow->objectName().isEmpty())
            ShowMainWindow->setObjectName(QStringLiteral("ShowMainWindow"));
        ShowMainWindow->resize(800, 600);
        centralwidget = new QWidget(ShowMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(200, 150, 256, 192));
        ShowMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ShowMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        ShowMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ShowMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ShowMainWindow->setStatusBar(statusbar);

        retranslateUi(ShowMainWindow);

        QMetaObject::connectSlotsByName(ShowMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ShowMainWindow)
    {
        ShowMainWindow->setWindowTitle(QApplication::translate("ShowMainWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class ShowMainWindow: public Ui_ShowMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWMAINWINDOW_H
