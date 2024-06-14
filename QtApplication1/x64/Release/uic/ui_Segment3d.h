/********************************************************************************
** Form generated from reading UI file 'Segment3d.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEGMENT3D_H
#define UI_SEGMENT3D_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVTKWidget *qvtkWidget;
    QVTKWidget *qvtkWidget_2;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(575, 376);
        qvtkWidget = new QVTKWidget(Form);
        qvtkWidget->setObjectName(QString::fromUtf8("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(20, 40, 251, 241));
        qvtkWidget_2 = new QVTKWidget(Form);
        qvtkWidget_2->setObjectName(QString::fromUtf8("qvtkWidget_2"));
        qvtkWidget_2->setGeometry(QRect(280, 40, 251, 241));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEGMENT3D_H
