#include "fourpanel.h"
#include "ui_fourpanel.h"

#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include "vtkResliceImageViewer.h"
#include "vtkResliceCursorLineRepresentation.h"
#include "vtkResliceCursorThickLineRepresentation.h"
#include "vtkResliceCursorWidget.h"
#include "vtkResliceCursorActor.h"
#include "vtkResliceCursorPolyDataAlgorithm.h"
#include "vtkResliceCursor.h"
#include "vtkDICOMImageReader.h"
#include "vtkCellPicker.h"
#include "vtkProperty.h"
#include "vtkPlane.h"
#include "vtkImageData.h"
#include "vtkCommand.h"
#include "vtkPlaneSource.h"
#include "vtkLookupTable.h"
#include "vtkImageMapToWindowLevelColors.h"
#include "vtkInteractorStyleImage.h"
#include "vtkImageSlabReslice.h"
#include "vtkBoundedPlanePointPlacer.h"
#include "vtkDistanceWidget.h"
#include "vtkDistanceRepresentation.h"
#include "vtkHandleRepresentation.h"
#include "vtkResliceImageViewerMeasurements.h"
#include "vtkDistanceRepresentation2D.h"
#include "vtkPointHandleRepresentation3D.h"
#include "vtkPointHandleRepresentation2D.h"
#include<QDebug>


#include<vtkRenderer.h>
#include<vtkRenderWindow.h>
#include<vtkRenderWindowInteractor.h>
#include<vtkDICOMImageReader.h>
#include<vtkContourFilter.h>
#include<vtkPolyDataNormals.h>
#include<vtkPolyDataMapper.h>
#include<vtkActor.h>
#include<vtkOutlineFilter.h>
#include<vtkCamera.h>
#include<vtkProperty.h>


#include<vtkInteractorStyleTrackballCamera.h>

#define VTK_CREATE(type,name) \
    vtkSmartPointer<type> name = vtkSmartPointer<type>::New()


class vtkResliceCursorCallback : public vtkCommand
{
public:
  static vtkResliceCursorCallback *New()
  { return new vtkResliceCursorCallback; }

  void Execute( vtkObject *caller, unsigned long ev,
                void *callData )
  {

    if (ev == vtkResliceCursorWidget::WindowLevelEvent ||
        ev == vtkCommand::WindowLevelEvent ||
        ev == vtkResliceCursorWidget::ResliceThicknessChangedEvent)
    {
      // Render everything
      for (int i = 0; i < 3; i++)
      {
        this->RCW[i]->Render();
      }
      this->IPW[0]->GetInteractor()->GetRenderWindow()->Render();
      return;
    }

    vtkImagePlaneWidget* ipw =
      dynamic_cast< vtkImagePlaneWidget* >( caller );
    if (ipw)
    {
      double* wl = static_cast<double*>( callData );

      if ( ipw == this->IPW[0] )
      {
        this->IPW[1]->SetWindowLevel(wl[0],wl[1],1);
        this->IPW[2]->SetWindowLevel(wl[0],wl[1],1);
      }
      else if( ipw == this->IPW[1] )
      {
        this->IPW[0]->SetWindowLevel(wl[0],wl[1],1);
        this->IPW[2]->SetWindowLevel(wl[0],wl[1],1);
      }
      else if (ipw == this->IPW[2])
      {
        this->IPW[0]->SetWindowLevel(wl[0],wl[1],1);
        this->IPW[1]->SetWindowLevel(wl[0],wl[1],1);
      }
    }

    vtkResliceCursorWidget *rcw = dynamic_cast<
      vtkResliceCursorWidget * >(caller);
    if (rcw)
    {
      vtkResliceCursorLineRepresentation *rep = dynamic_cast<
        vtkResliceCursorLineRepresentation * >(rcw->GetRepresentation());
      // Although the return value is not used, we keep the get calls
      // in case they had side-effects
      rep->GetResliceCursorActor()->GetCursorAlgorithm()->GetResliceCursor();
      for (int i = 0; i < 3; i++)
      {
        vtkPlaneSource *ps = static_cast< vtkPlaneSource * >(
            this->IPW[i]->GetPolyDataAlgorithm());
        ps->SetOrigin(this->RCW[i]->GetResliceCursorRepresentation()->
                                          GetPlaneSource()->GetOrigin());
        ps->SetPoint1(this->RCW[i]->GetResliceCursorRepresentation()->
                                          GetPlaneSource()->GetPoint1());
        ps->SetPoint2(this->RCW[i]->GetResliceCursorRepresentation()->
                                          GetPlaneSource()->GetPoint2());

        // If the reslice plane has modified, update it on the 3D widget
        this->IPW[i]->UpdatePlacement();
      }
    }

    // Render everything
    for (int i = 0; i < 3; i++)
    {
      this->RCW[i]->Render();
    }
    this->IPW[0]->GetInteractor()->GetRenderWindow()->Render();
  }

  vtkResliceCursorCallback() {}
  vtkImagePlaneWidget* IPW[3];
  vtkResliceCursorWidget *RCW[3];
};

FourPanel::FourPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FourPanel)
{
    ui->setupUi(this);
    this->resize(QSize(1200, 900));
    vtkSmartPointer< vtkDICOMImageReader > reader =
      vtkSmartPointer< vtkDICOMImageReader >::New();
    reader->SetDirectoryName("D://code//qtvtk//Heart-unzip");
    reader->Update();
    int imageDims[3];//256-256-20
    reader->GetOutput()->GetDimensions(imageDims);

    for (int i = 0; i < 3; i++)
    {
      riw[i] = vtkSmartPointer< vtkResliceImageViewer >::New();
    }

    this->ui->view1->SetRenderWindow(riw[0]->GetRenderWindow());
    riw[0]->SetupInteractor(
        this->ui->view1->GetRenderWindow()->GetInteractor());
    //riw[0]->SetResliceMode(1);

    this->ui->view2->SetRenderWindow(riw[1]->GetRenderWindow());
    riw[1]->SetupInteractor(
        this->ui->view2->GetRenderWindow()->GetInteractor());
    //riw[1]->SetResliceMode(1);

    this->ui->view3->SetRenderWindow(riw[2]->GetRenderWindow());
    riw[2]->SetupInteractor(
        this->ui->view3->GetRenderWindow()->GetInteractor());
    //riw[2]->SetResliceMode(1);

    for (int i = 0; i < 3; i++)
    {
      // make them all share the same reslice cursor object.
      vtkResliceCursorLineRepresentation *rep =
        vtkResliceCursorLineRepresentation::SafeDownCast(
            riw[i]->GetResliceCursorWidget()->GetRepresentation());
      riw[i]->SetResliceCursor(riw[0]->GetResliceCursor());

      rep->GetResliceCursorActor()->
        GetCursorAlgorithm()->SetReslicePlaneNormal(i);

      riw[i]->SetInputData(reader->GetOutput());
      riw[i]->SetSliceOrientation(i);
      riw[i]->SetResliceModeToAxisAligned();
    }

    vtkSmartPointer<vtkCellPicker> picker =
      vtkSmartPointer<vtkCellPicker>::New();
    picker->SetTolerance(0.005);

    vtkSmartPointer<vtkProperty> ipwProp =
      vtkSmartPointer<vtkProperty>::New();

    vtkSmartPointer< vtkRenderer > ren =
      vtkSmartPointer< vtkRenderer >::New();

    this->ui->view4->GetRenderWindow()->AddRenderer(ren);
    vtkRenderWindowInteractor *iren = this->ui->view4->GetInteractor();
    double color[3][3]={{0.18, 0.37, 0.45},{0.42, 0.28, 0.24},{0.36, 0.24, 0.41} };
    double color2[3][3] = { {0.25, 0, 0},{0, 0.25,0},{0, 0, 0.25} };
    
    for (int i = 0; i < 3; i++)
    {
      planeWidget[i] = vtkSmartPointer<vtkImagePlaneWidget>::New();
      planeWidget[i]->SetInteractor( iren );
      planeWidget[i]->SetPicker(picker);
      planeWidget[i]->RestrictPlaneToVolumeOn();
      /*double color[3] = {0, 0, 0};
      color[i] = 1;*/
      planeWidget[i]->GetPlaneProperty()->SetColor(color2[i]);

      //color[0] /= 4.0;
      //color[1] /= 4.0;
      //color[2] /= 4.0;
      riw[i]->GetRenderer()->SetBackground( color[i]);

      planeWidget[i]->SetTexturePlaneProperty(ipwProp);
      planeWidget[i]->TextureInterpolateOff();
      planeWidget[i]->SetResliceInterpolateToLinear();
      planeWidget[i]->SetInputConnection(reader->GetOutputPort());
      planeWidget[i]->SetPlaneOrientation(i);
      planeWidget[i]->SetSliceIndex(imageDims[i]/2);
      planeWidget[i]->DisplayTextOn();
      planeWidget[i]->SetDefaultRenderer(ren);
      planeWidget[i]->SetWindowLevel(1358, -27);
      planeWidget[i]->On();
      planeWidget[i]->InteractionOn();
    }

    vtkSmartPointer<vtkResliceCursorCallback> cbk =
      vtkSmartPointer<vtkResliceCursorCallback>::New();

    for (int i = 0; i < 3; i++)
    {
      cbk->IPW[i] = planeWidget[i];
      cbk->RCW[i] = riw[i]->GetResliceCursorWidget();
      riw[i]->GetResliceCursorWidget()->AddObserver(
          vtkResliceCursorWidget::ResliceAxesChangedEvent, cbk );
      riw[i]->GetResliceCursorWidget()->AddObserver(
          vtkResliceCursorWidget::WindowLevelEvent, cbk );
      riw[i]->GetResliceCursorWidget()->AddObserver(
          vtkResliceCursorWidget::ResliceThicknessChangedEvent, cbk );
      riw[i]->GetResliceCursorWidget()->AddObserver(
          vtkResliceCursorWidget::ResetCursorEvent, cbk );
      riw[i]->GetInteractorStyle()->AddObserver(
          vtkCommand::WindowLevelEvent, cbk );

      // Make them all share the same color map.
      riw[i]->SetLookupTable(riw[0]->GetLookupTable());
      planeWidget[i]->GetColorMap()->SetLookupTable(riw[0]->GetLookupTable());
      //planeWidget[i]->GetColorMap()->SetInput(riw[i]->GetResliceCursorWidget()->GetResliceCursorRepresentation()->GetColorMap()->GetInput());
      planeWidget[i]->SetColorMap(riw[i]->GetResliceCursorWidget()->GetResliceCursorRepresentation()->GetColorMap());

    }

    for (int i = 0; i < 3; i++)
    {
      riw[i]->SetResliceMode(1);
      riw[i]->GetRenderer()->ResetCamera();
      riw[i]->Render();
    }
}

FourPanel::~FourPanel()
{
    delete ui;
}

#include <QFileDialog>
#include <QDir>
#include <qstring.h>
#include <qlineedit.h>
#include <QpushButton>
#include <QMessageBox>
#include <QCloseEvent>

void FourPanel::slotExit(QCloseEvent* event)
{
    QPushButton* okbtn = new QPushButton(QString::fromLocal8Bit("Yes"));
    QPushButton* cancelbtn = new QPushButton(QString::fromLocal8Bit("Cancel"));
    QMessageBox* mymsgbox = new QMessageBox;

    mymsgbox->setIcon(QMessageBox::Warning);
    mymsgbox->setWindowTitle(QString::fromLocal8Bit("Hint"));
    mymsgbox->setText(QString::fromLocal8Bit("Are you sure to exit?"));
    mymsgbox->addButton(okbtn, QMessageBox::AcceptRole);
    mymsgbox->addButton(cancelbtn, QMessageBox::RejectRole);
    mymsgbox->show();

    mymsgbox->exec();//阻塞等待用户输入
    if (mymsgbox->clickedButton() == okbtn)//点击了OK按钮
    {
        event->accept();
    }
    else {
        event->ignore();
    }
}

void FourPanel::on_actionReset_triggered()
{
    // Reset the reslice image views
    for (int i = 0; i < 3; i++)
    {
      riw[i]->Reset();
    }

    // Also sync the Image plane widget on the 3D top right view with any
    // changes to the reslice cursor.
    for (int i = 0; i < 3; i++)
    {
      vtkPlaneSource *ps = static_cast< vtkPlaneSource * >(
          planeWidget[i]->GetPolyDataAlgorithm());
      ps->SetNormal(riw[0]->GetResliceCursor()->GetPlane(i)->GetNormal());
      ps->SetCenter(riw[0]->GetResliceCursor()->GetPlane(i)->GetOrigin());

      // If the reslice plane has modified, update it on the 3D widget
      this->planeWidget[i]->UpdatePlacement();
    }

    // Render in response to changes.
    for (int i = 0; i < 3; i++)
    {
      riw[i]->Render();
    }
    this->ui->view3->GetRenderWindow()->Render();
}
