#pragma once
//#pragma warning(disable: 26498 )
/*QT file*/
#include <QtWidgets/QMainWindow>
// #include "ui_VTKReadJpg_InQT_Test.h"
# include "ui_Mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <qstring.h>
#include <qlineedit.h>
#include <QpushButton>
#include <QMessageBox>
#include <QCloseEvent>
/*vtk File*/
#include <vtkActor.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkObjectFactory.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkImageViewer2.h>
#include <QVTKWidget.h>
#include <vtkImageActor.h>
#include <vtkEventQtSlotConnect.h>
#include "vtkCommand.h"
#include <vtkOutputWindow.h>
#include "vtkSmartPointer.h"
#include <vtkTextProperty.h>
#include <vtkTextMapper.h>
#include <vtkInteractorStyleImage.h>
#include <vtkActor2D.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkTextMapper.h>
#include <vtkTextProperty.h>
#include <vtkPropPicker.h>
#include <vtkCornerAnnotation.h>
#include <vtkMath.h>
#include <vtkRendererCollection.h>
#include <vtkImageMapToColors.h>
#include <vtkLookupTable.h>
#include <vtkMatrix4x4.h>
// 3
#include <vtkImagePlaneWidget.h>
#include <vtkAxesActor.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkCellPicker.h>
// 4panel
#include "vtkResliceImageViewerMeasurements.h"
#include <vtkLineSource.h>
// vloumn render
#include <vtkOpenGlGPUVolumeRayCastMapper.h>
#include <vtkVolumeProperty.h>
#include <vtkPiecewiseFunction.h>
#include <vtkColorTransferFunction.h>
#include <vtkSphereSource.h>
#include <vtkDataSetMapper.h>
#include <vtkVolumePicker.h>
#include <vtkProperty.h>
#include <vtkVectorText.h>
#include <vtkFollower.h>
#include <vtkPolyDataMapper.h>
#include <vtkPointHandleRepresentation3D.h>
#include <vtkImageData.h>
#include <vtkDistanceWidget.h>
//为了能够使用vtk添加代码
#include <sstream>
#include "vtkAutoInit.h"
// 子窗口
#include "QtWidgetsClass.h"
// centerline

VTK_MODULE_INIT(vtkRenderingOpenGL2); // VTK was built with vtkRenderingOpenGL2
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);
VTK_MODULE_INIT(vtkRenderingVolumeOpenGL2)
using namespace std;
class vtkImageViewer2;
class vtkRenderer;
class vtkEventQtSlotConnect;
class QVTKWidget;

namespace {

	// helper class to format slice status message
	class StatusMessage
	{
	public:
		static std::string Format(int slice, int maxSlice)
		{
			std::stringstream tmp;
			tmp << "Slice Number  " << slice + 1 << "/" << maxSlice + 1;
			return tmp.str();
		}
	};

	// Define own interaction style
	class myVtkInteractorStyleImage : public vtkInteractorStyleImage
	{
	public:
		static myVtkInteractorStyleImage* New();
		vtkTypeMacro(myVtkInteractorStyleImage, vtkInteractorStyleImage);

	protected:
		vtkImageViewer2* _ImageViewer;
		vtkTextMapper* _StatusMapper;
		int _Slice;
		int _MinSlice;
		int _MaxSlice;
	//public:
		//int cursorx;
		//int cursory;

	public:

		void SetImageViewer(vtkImageViewer2* imageViewer)
		{
			_ImageViewer = imageViewer;
			_MinSlice = imageViewer->GetSliceMin();
			_MaxSlice = imageViewer->GetSliceMax();
			_Slice = _MinSlice;
			cout << "Slicer: Min = " << _MinSlice << ", Max = " << _MaxSlice
				<< std::endl;
		}

		void SetStatusMapper(vtkTextMapper* statusMapper)
		{
			_StatusMapper = statusMapper;
		}

	protected:
		void MoveSliceForward()
		{
			if (_Slice < _MaxSlice)
			{
				_Slice += 1;
				_ImageViewer->SetSlice(_Slice);
				std::string msg = StatusMessage::Format(_Slice, _MaxSlice);
				_StatusMapper->SetInput(msg.c_str());
				_ImageViewer->Render();
				
			}
		}

		void MoveSliceBackward()
		{
			if (_Slice > _MinSlice)
			{
				_Slice -= 1;
				_ImageViewer->SetSlice(_Slice);
				std::string msg = StatusMessage::Format(_Slice, _MaxSlice);
				_StatusMapper->SetInput(msg.c_str());
				_ImageViewer->Render();
			}
		}

		virtual void OnKeyDown()
		{
			std::string key = this->GetInteractor()->GetKeySym();
			if (key.compare("Up") == 0)
			{
				// cout << "Up arrow key was pressed." << endl;
				MoveSliceForward();
			}
			else if (key.compare("Down") == 0)
			{
				// cout << "Down arrow key was pressed." << endl;
				MoveSliceBackward();
			}
			// forward event
			vtkInteractorStyleImage::OnKeyDown();
		}

		virtual void OnMouseWheelForward()
		{
			// std::cout << "Scrolled mouse wheel forward." << std::endl;
			MoveSliceForward();
			// don't forward events, otherwise the image will be zoomed
			// in case another interactorstyle is used (e.g. trackballstyle, ...)
			// vtkInteractorStyleImage::OnMouseWheelForward();
		}

		virtual void OnMouseWheelBackward()
		{
			// std::cout << "Scrolled mouse wheel backward." << std::endl;
			if (_Slice > _MinSlice)
			{
				MoveSliceBackward();
			}
			// don't forward events, otherwise the image will be zoomed
			// in case another interactorstyle is used (e.g. trackballstyle, ...)
			// vtkInteractorStyleImage::OnMouseWheelBackward();
		}
	};

	vtkStandardNewMacro(myVtkInteractorStyleImage);

} // namespace


class VTKReadJpg_InQT_Test : public QMainWindow
{
    Q_OBJECT

public:
    VTKReadJpg_InQT_Test(QWidget* parent = Q_NULLPTR);
	void seg3d2(void);
private:
    Ui::Mainwindow ui;
private slots: //声明槽函数，private slots是用来写纯虚函数的
	
   void onOpenSlot(void);
   // void threeshow(void);
	void volumnRender(void);
	void fourpa(void);
	void showimage(void);
	void Reset(void);
	void segment(void);
	void updateimage(void);
	void closeEvent(QCloseEvent* event);//关闭窗口事件，可以询问是否退出
	void coloredimage(void);
	void grayimage(void);
	void saveimage(void);
	void changeviewXZ(void);
	void changeviewYZ(void);
	void changeviewXY(void);
	void seg3d(void);
	//void centerline(void);
	
	//void mouseMoveEvent(QMouseEvent* e) override;//hint text
private:
	int _ww, _wl;

	QtWidgetsClass* cw;
    vtkSmartPointer<vtkImageViewer2> imageViewer;
    vtkSmartPointer<vtkRenderer> m_pRenderer;
    vtkSmartPointer<vtkTextProperty> sliceTextProp;
    vtkSmartPointer<vtkTextMapper> sliceTextMapper;
    vtkSmartPointer<vtkActor2D> sliceTextActor;
    vtkSmartPointer<vtkTextProperty> usageTextProp;
    vtkSmartPointer<vtkTextMapper> usageTextMapper;
   vtkSmartPointer<vtkActor2D> usageTextActor;
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor;
 vtkSmartPointer<myVtkInteractorStyleImage> myInteractorStyle;
 vtkSmartPointer<vtkDICOMImageReader>reader;
 vtkSmartPointer<vtkRenderWindow> renderWindow;
 vtkSmartPointer< vtkResliceImageViewer > riw[3];
 vtkSmartPointer< vtkImagePlaneWidget > planeWidget[3];
 vtkSmartPointer< vtkDistanceWidget > DistanceWidget[3];
 vtkSmartPointer< vtkResliceImageViewerMeasurements > ResliceMeasurements;

 vtkNew<vtkLookupTable> colorTable;
 vtkNew<vtkImageMapToColors> colorMap;

    //QVTKWidget m_qvtkWidget;
 //vtkSmartPointer<vtkPropPicker> Picker;
 //vtkSmartPointer<vtkCornerAnnotation> Annotation;
 //vtkSmartPointer<vtkPropPicker> propPicker;


};

