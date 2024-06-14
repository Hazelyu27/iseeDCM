/********************************************************************************
** Form generated from reading UI file 'fourpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOURPANEL_H
#define UI_FOURPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_FourPanel
{
public:
    QAction *actionReset;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVTKWidget *view1;
    QVTKWidget *view2;
    QVTKWidget *view3;
    QVTKWidget *view4;
    QMenuBar *menubar;
    QMenu *menuOperate;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FourPanel)
    {
        if (FourPanel->objectName().isEmpty())
            FourPanel->setObjectName(QString::fromUtf8("FourPanel"));
        FourPanel->resize(597, 385);
        actionReset = new QAction(FourPanel);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        centralwidget = new QWidget(FourPanel);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        view1 = new QVTKWidget(centralwidget);
        view1->setObjectName(QString::fromUtf8("view1"));

        gridLayout->addWidget(view1, 0, 0, 1, 1);

        view2 = new QVTKWidget(centralwidget);
        view2->setObjectName(QString::fromUtf8("view2"));

        gridLayout->addWidget(view2, 0, 1, 1, 1);

        view3 = new QVTKWidget(centralwidget);
        view3->setObjectName(QString::fromUtf8("view3"));

        gridLayout->addWidget(view3, 1, 0, 1, 1);

        view4 = new QVTKWidget(centralwidget);
        view4->setObjectName(QString::fromUtf8("view4"));

        gridLayout->addWidget(view4, 1, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        FourPanel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FourPanel);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 597, 18));
        menuOperate = new QMenu(menubar);
        menuOperate->setObjectName(QString::fromUtf8("menuOperate"));
        FourPanel->setMenuBar(menubar);
        statusbar = new QStatusBar(FourPanel);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FourPanel->setStatusBar(statusbar);

        menubar->addAction(menuOperate->menuAction());
        menuOperate->addAction(actionReset);

        retranslateUi(FourPanel);

        QMetaObject::connectSlotsByName(FourPanel);
    } // setupUi

    void retranslateUi(QMainWindow *FourPanel)
    {
        FourPanel->setWindowTitle(QCoreApplication::translate("FourPanel", "MainWindow", nullptr));
        actionReset->setText(QCoreApplication::translate("FourPanel", "reset", nullptr));
        menuOperate->setTitle(QCoreApplication::translate("FourPanel", "Operate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FourPanel: public Ui_FourPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOURPANEL_H
