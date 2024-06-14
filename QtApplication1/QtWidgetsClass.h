#pragma once

#include <QMainWindow>
#include "ui_QtWidgetsClass.h"

class VTKReadJpg_InQT_Test;
class QtWidgetsClass : public QMainWindow
{
	Q_OBJECT

public:
	QtWidgetsClass(QWidget *parent);
	~QtWidgetsClass();
private slots:
	void exeseg(void);
	void opendict(void);

private:
	Ui::QtWidgetsClassClass ui;
	VTKReadJpg_InQT_Test* m_parent;
};


