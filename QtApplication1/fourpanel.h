#ifndef FOURPANEL_H
#define FOURPANEL_H

#include <QMainWindow>

#include "vtkSmartPointer.h"
#include "vtkResliceImageViewer.h"
#include "vtkImagePlaneWidget.h"
#include "vtkDistanceWidget.h"
#include "vtkResliceImageViewerMeasurements.h"

namespace Ui {
class FourPanel;
}

class FourPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit FourPanel(QWidget *parent = 0);
    ~FourPanel();



public slots:

  virtual void slotExit(QCloseEvent* event);
protected:
  vtkSmartPointer< vtkResliceImageViewer > riw[3];
  vtkSmartPointer< vtkImagePlaneWidget > planeWidget[3];
  vtkSmartPointer< vtkDistanceWidget > DistanceWidget[3];
  vtkSmartPointer< vtkResliceImageViewerMeasurements > ResliceMeasurements;
private slots:
  void on_actionReset_triggered();

private:
    Ui::FourPanel *ui;
};

#endif // FOURPANEL_H
