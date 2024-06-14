#pragma once
#include <QMainWindow>
#include <ui_Mainwindow.h>
#include <vtkOutputWindow.h>

class Mainwindow : public QMainWindow
{
    Q_OBJECT

public:
    Mainwindow(QWidget* parent = Q_NULLPTR);

//public slots:
//    virtual void slotExit();
//protected:

private:
    Ui::Mainwindow* ui;
};