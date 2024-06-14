/********************************************************************************
** Form generated from reading UI file 'Mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Mainwindow
{
public:
    QAction *actionOpen_Directory;
    QAction *actionSave;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLabel *label;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_5;
    QPushButton *pushButton_10;
    QPushButton *pushButton_6;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_4;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QSpinBox *spinBox;
    QLabel *label_5;
    QSpinBox *spinBox_2;
    QLabel *label_6;
    QSpinBox *spinBox_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;
    QVTKWidget *qvtkWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton_7;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_11;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Mainwindow)
    {
        if (Mainwindow->objectName().isEmpty())
            Mainwindow->setObjectName(QString::fromUtf8("Mainwindow"));
        Mainwindow->resize(645, 440);
        Mainwindow->setMaximumSize(QSize(16777215, 16777215));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/86158/Downloads/zoomin.png"), QSize(), QIcon::Normal, QIcon::Off);
        Mainwindow->setWindowIcon(icon);
        Mainwindow->setStyleSheet(QString::fromUtf8(""));
        actionOpen_Directory = new QAction(Mainwindow);
        actionOpen_Directory->setObjectName(QString::fromUtf8("actionOpen_Directory"));
        actionSave = new QAction(Mainwindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        centralwidget = new QWidget(Mainwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(0, 0));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("\n"
"font: 14pt \"DejaVu Sans Mono\";\n"
""));

        verticalLayout->addWidget(label_3);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(16777215, 16777215));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(30, 31, 28, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(201, 202, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(145, 147, 247, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(45, 46, 120, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(60, 62, 160, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(172, 174, 247, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush10(QColor(90, 93, 240, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush9);
#endif
        label->setPalette(palette);
        label->setStyleSheet(QString::fromUtf8("color:black;\n"
"font: 8pt \"DejaVu Sans Mono\";\n"
""));

        verticalLayout->addWidget(label);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("DejaVu Sans Mono"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        pushButton_4->setFont(font1);
        pushButton_4->setToolTipDuration(2000);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton:hover{ \n"
" background-color: rgb(236, 236, 233); \n"
" color: rgb(0, 0, 0);}\n"
"\n"
"\n"
"QPushButton{\n"
"color:rgb(0,0,0);\n"
"font: 9pt \"DejaVu Sans Mono\";\n"
"background-color:rgb(255,255,255);\n"
"border: 0 groove;\n"
"padding:8px 4px;\n"
"}"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton:hover{ \n"
"\n"
" color: rgb(0,0,0);}\n"
"\n"
"\n"
"QPushButton{\n"
"color:rgb(118,119,121);\n"
"font: 9pt \"DejaVu Sans Mono\";\n"
"background-color:rgb(196,199,204); \n"
"border: 0 groove;\n"
"padding:8px 4px;}"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton:hover{ \n"
"\n"
" color: rgb(0,0,0);}\n"
"\n"
"\n"
"QPushButton{\n"
"color:rgb(118,119,121);\n"
"font: 9pt \"DejaVu Sans Mono\";\n"
"background-color:rgb(196,199,204); \n"
"border: 0 groove;\n"
"padding:8px 4px;}"));

        verticalLayout->addWidget(pushButton_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton:hover{ \n"
"\n"
" color: rgb(0,0,0);}\n"
"\n"
"\n"
"QPushButton{\n"
"color:rgb(118,119,121);\n"
"font: 9pt \"DejaVu Sans Mono\";\n"
"background-color:rgb(196,199,204); \n"
"border: 0 groove;\n"
"padding:8px 4px;}"));

        horizontalLayout_5->addWidget(pushButton_5);

        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton:hover{ \n"
"\n"
" color: rgb(0,0,0);}\n"
"\n"
"\n"
"QPushButton{\n"
"color:rgb(118,119,121);\n"
"font: 9pt \"DejaVu Sans Mono\";\n"
"background-color:rgb(196,199,204); \n"
"border: 0 groove;\n"
"padding:8px 4px;}"));

        horizontalLayout_5->addWidget(pushButton_10);


        verticalLayout->addLayout(horizontalLayout_5);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton:hover{ \n"
"\n"
" color: rgb(0,0,0);}\n"
"\n"
"\n"
"QPushButton{\n"
"color:rgb(118,119,121);\n"
"font: 9pt \"DejaVu Sans Mono\";\n"
"background-color:rgb(196,199,204); \n"
"border: 0 groove;\n"
"padding:8px 4px;}"));

        verticalLayout->addWidget(pushButton_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setStyleSheet(QString::fromUtf8("\n"
"color:black;"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_5->addWidget(label_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setMinimumSize(QSize(0, 0));
        label_9->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"background-color:white;\n"
"color:black;"));

        horizontalLayout_7->addWidget(label_9);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"background-color:white;\n"
"color:black;"));

        horizontalLayout_7->addWidget(label_10);


        verticalLayout_5->addLayout(horizontalLayout_7);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_5->addWidget(label_11);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"background-color:white;\n"
"color:black;"));

        verticalLayout_5->addWidget(label_12);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_5->addWidget(label_13);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"background-color:white;\n"
"color:black;"));

        horizontalLayout_8->addWidget(label_14);

        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setStyleSheet(QString::fromUtf8("border:1px solid gray;\n"
"background-color:white;\n"
"color:black;"));

        horizontalLayout_8->addWidget(label_15);


        verticalLayout_5->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox);


        verticalLayout->addLayout(verticalLayout_3);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(0, 0));
        label_4->setMaximumSize(QSize(16777215, 16777215));
        label_4->setStyleSheet(QString::fromUtf8("\n"
"font: 8pt \"DejaVu Sans Mono\";"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setStyleSheet(QString::fromUtf8("\n"
"font: 8pt \"DejaVu Sans Mono\";"));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        verticalLayout->addWidget(label_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);
        verticalLayout->setStretch(4, 1);
        verticalLayout->setStretch(6, 1);
        verticalLayout->setStretch(7, 8);
        verticalLayout->setStretch(8, 1);
        verticalLayout->setStretch(9, 1);

        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(0, 0));
        label_7->setMaximumSize(QSize(16777215, 16777215));
        label_7->setStyleSheet(QString::fromUtf8("\n"
"font: 8pt \"DejaVu Sans Mono\";"));
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(true);

        horizontalLayout->addWidget(label_7);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setStyleSheet(QString::fromUtf8(""));
        spinBox->setMaximum(5000);

        horizontalLayout->addWidget(spinBox);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setMaximumSize(QSize(16777215, 16777215));
        label_5->setStyleSheet(QString::fromUtf8("\n"
"font: 8pt \"DejaVu Sans Mono\";"));
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);

        horizontalLayout->addWidget(label_5);

        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setStyleSheet(QString::fromUtf8(""));
        spinBox_2->setMaximum(5000);

        horizontalLayout->addWidget(spinBox_2);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(0, 0));
        label_6->setMaximumSize(QSize(16777215, 16777215));
        label_6->setStyleSheet(QString::fromUtf8("\n"
"font: 8pt \"DejaVu Sans Mono\";"));
        label_6->setAlignment(Qt::AlignCenter);
        label_6->setWordWrap(true);

        horizontalLayout->addWidget(label_6);

        spinBox_3 = new QSpinBox(centralwidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setStyleSheet(QString::fromUtf8(""));
        spinBox_3->setMaximum(5000);

        horizontalLayout->addWidget(spinBox_3);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setMaximumSize(QSize(16777215, 16777215));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton:hover{ \n"
" background-color: rgb(121, 123, 126); \n"
" color: rgb(255, 255, 255);}\n"
"\n"
"\n"
"QPushButton{\n"
"color:rgb(0,0,0);\n"
"font: 9pt \"DejaVu Sans Mono\";\n"
"background-color:rgb(196,199,204);\n"
"border: 0 groove;\n"
"padding:4px 4px;border-radius:5px;;}"));

        horizontalLayout->addWidget(pushButton_9);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton:hover{ \n"
" background-color: rgb(141, 136, 113); \n"
" color: rgb(255, 255, 255);}\n"
"\n"
"\n"
"QPushButton{\n"
"color:rgb(255,255,255);\n"
"font: 9pt \"DejaVu Sans Mono\";\n"
"background-color:rgb(219, 138, 49);\n"
"border: 0 groove;\n"
"padding:4px 4px;border-radius:5px;;}"));

        horizontalLayout->addWidget(pushButton_8);


        verticalLayout_2->addLayout(horizontalLayout);

        qvtkWidget = new QVTKWidget(centralwidget);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));

        verticalLayout_2->addWidget(qvtkWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:rgb(165, 169, 177);\n"
"border:0;\n"
"color:white;"));

        horizontalLayout_2->addWidget(lineEdit);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton:hover{ \n"
" background-color: rgb(236, 236, 233); \n"
" color: rgb(0, 0, 0);}\n"
"\n"
"\n"
"QPushButton{\n"
"color:rgb(255,255,255);\n"
"font: 9pt \"DejaVu Sans Mono\";\n"
"background-color:rgb(219,138,49);\n"
"border: 0 groove;\n"
"padding:4px 4px;\n"
"border-radius:5px ;}"));

        horizontalLayout_2->addWidget(pushButton_7);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 10);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setStyleSheet(QString::fromUtf8("background-color:rgb(235, 237, 239);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/86158/Downloads/icon_\350\211\262\345\275\251.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_11->setIcon(icon1);

        verticalLayout_4->addWidget(pushButton_11);

        toolButton_3 = new QToolButton(centralwidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));

        verticalLayout_4->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(centralwidget);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));

        verticalLayout_4->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(centralwidget);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));

        verticalLayout_4->addWidget(toolButton_5);


        horizontalLayout_4->addLayout(verticalLayout_4);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        Mainwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Mainwindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 645, 18));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuFile->setToolTipDuration(2000);
        menuFile->setToolTipsVisible(true);
        Mainwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Mainwindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Mainwindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_Directory);
        menuFile->addAction(actionSave);

        retranslateUi(Mainwindow);

        QMetaObject::connectSlotsByName(Mainwindow);
    } // setupUi

    void retranslateUi(QMainWindow *Mainwindow)
    {
        Mainwindow->setWindowTitle(QCoreApplication::translate("Mainwindow", "MainWindow", nullptr));
        actionOpen_Directory->setText(QCoreApplication::translate("Mainwindow", "Open Directory", nullptr));
        actionSave->setText(QCoreApplication::translate("Mainwindow", "Save ...", nullptr));
        label_3->setText(QCoreApplication::translate("Mainwindow", "iseeDCM", nullptr));
        label->setText(QCoreApplication::translate("Mainwindow", "iseeDCM Toolbox", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_4->setToolTip(QCoreApplication::translate("Mainwindow", "<html><head/><body><p><span style=\" color:#ff5500;\">opentheipmage</span></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        pushButton_4->setWhatsThis(QCoreApplication::translate("Mainwindow", "<html><head/><body><p>tisis</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        pushButton_4->setText(QCoreApplication::translate("Mainwindow", "Open Images", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Mainwindow", "Four Panel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Mainwindow", "Volunmn Render", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Mainwindow", "Seg(2D)", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Mainwindow", "Seg(3D)", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Mainwindow", "Center line", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Mainwindow", "Info", nullptr));
        label_8->setText(QCoreApplication::translate("Mainwindow", "Cursor position", nullptr));
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QCoreApplication::translate("Mainwindow", "Type", nullptr));
        label_12->setText(QString());
        label_13->setText(QCoreApplication::translate("Mainwindow", "Max and min slices", nullptr));
        label_14->setText(QString());
        label_15->setText(QString());
        label_4->setText(QCoreApplication::translate("Mainwindow", "version 1.0\n"
" Dec 20, 2022", nullptr));
        label_2->setText(QCoreApplication::translate("Mainwindow", "The project is\n"
" supported by USTC", nullptr));
        label_7->setText(QCoreApplication::translate("Mainwindow", "Slices", nullptr));
        label_5->setText(QCoreApplication::translate("Mainwindow", "Window width", nullptr));
        label_6->setText(QCoreApplication::translate("Mainwindow", "Window level", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Mainwindow", "Go", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Mainwindow", "Reset", nullptr));
        lineEdit->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("Mainwindow", "Save images", nullptr));
        pushButton_11->setText(QString());
        toolButton_3->setText(QCoreApplication::translate("Mainwindow", "XY", nullptr));
        toolButton_4->setText(QCoreApplication::translate("Mainwindow", "XZ", nullptr));
        toolButton_5->setText(QCoreApplication::translate("Mainwindow", "YZ", nullptr));
#if QT_CONFIG(tooltip)
        menuFile->setToolTip(QCoreApplication::translate("Mainwindow", "yes", nullptr));
#endif // QT_CONFIG(tooltip)
        menuFile->setTitle(QCoreApplication::translate("Mainwindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mainwindow: public Ui_Mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
