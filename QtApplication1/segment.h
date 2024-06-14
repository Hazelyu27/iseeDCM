#include "VTKReadJpg_InQT_Test.h"
#include <iostream>

#include <vtkRendererCollection.h>
#include <itkImageToVTKImageFilter.h>
#include <vtkPointData.h>
#include "vtkStripper.h"
#include "vtkSmoothPolyDataFilter.h"
#include "vtkPolyDataNormals.h"
#include "vtkImageShrink3D.h"
#include "vtkDecimatePro.h"
#include <vector>
#include <string>
#include <vtkImageSliceMapper.h>
#include <vtkPNGReader.h>
#include <vtkSTLReader.h>
#include <vtkTexture.h>
#include <vtkTextureMapToCylinder.h>
#include <vtkImageFlip.h>
#include <vtkImageGradient.h>
#include <vtkImageGradient.h>
#include <vtkImageMagnitude.h>
#include <vtkImageShiftScale.h>
#include <vtkImageHybridMedian2D.h>
#include <vtkSphereSource.h>
#include <vtkTextProperty.h>
#include <vtkProperty2D.h>
#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkSliderWidget.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkPolyData.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkCommand.h>
#include <vtkWidgetEvent.h>
#include <vtkCallbackCommand.h>
#include <vtkWidgetEventTranslator.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkSliderWidget.h>
#include <vtkSliderRepresentation2D.h>
#include <vtkProperty.h>

#include "itkImageToVTKImageFilter.h"
#include "itkJPEGImageIOFactory.h"
#include "itkRGBPixel.h"
#include "itkImage.h"
#include "itkGDCMImageIO.h"
#include "itkGDCMSeriesFileNames.h"
#include "itkVTKImageToImageFilter.h"
#include "itkRescaleIntensityImageFilter.h"
#include "itkImageSeriesReader.h"
#include "itkImageSeriesWriter.h"
#include "itkCurvatureFlowImageFilter.h"
#include "itkConnectedThresholdImageFilter.h"
#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkCastImageFilter.h"
#include "itkPNGImageIOFactory.h"
#include "itksys/SystemTools.hxx"
#include "itkImageRegionIterator.h"
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>  
#include <itkPNGImageIOFactory.h>  
#include <itkConnectedThresholdImageFilter.h>  
#include <itkImageSeriesReader.h>  
#include <itkGDCMImageIO.h>  
#include <itkImageToVTKImageFilter.h>  
#include <vtkLookupTable.h>
#include <vtkImageProperty.h>
#include <vtkImageMapToColors.h>
#include "vtkImageViewer2.h"
#include <vtkWindowToImageFilter.h>
#include <vtkBMPWriter.h>
#pragma once
using namespace std;
typedef short PixelType;
const unsigned int   Dimension = 2;
typedef itk::Image< PixelType, Dimension > Input2dImageType;
typedef itk::GDCMImageIO   ImageIOType;//GDCMImageIO读DICOM
ImageIOType::Pointer gdcmImageIO = ImageIOType::New();
typedef itk::ImageFileReader< Input2dImageType > ReaderType2d;
ReaderType2d::Pointer reader2d = ReaderType2d::New();
vtkSmartPointer<vtkImageMapToColors> colorMap =
vtkSmartPointer<vtkImageMapToColors>::New();
vtkSmartPointer<vtkImageActor> colorActor =
vtkSmartPointer<vtkImageActor>::New();
vtkSmartPointer<vtkImageData> itkToVtk(Input2dImageType::Pointer image)
{
	typedef itk::ImageToVTKImageFilter< Input2dImageType> itkTovtkFilterType;
	itkTovtkFilterType::Pointer itkTovtkImageFilter = itkTovtkFilterType::New();
	itkTovtkImageFilter->SetInput(image);//设置图像数据从ITK转向VTK
	itkTovtkImageFilter->Update();

	return itkTovtkImageFilter->GetOutput();
}

Input2dImageType::Pointer connectedThreshold(int range[2], Input2dImageType::Pointer itkImage, Input2dImageType::IndexType seed)
{
	typedef itk::ConnectedThresholdImageFilter< Input2dImageType, Input2dImageType > ConnectedFilterType;
	ConnectedFilterType::Pointer connectedThres = ConnectedFilterType::New();
	connectedThres->SetInput(itkImage);
	connectedThres->SetLower(range[0]);
	connectedThres->SetUpper(range[1]);
	connectedThres->SetReplaceValue(3071);
	connectedThres->AddSeed(seed);
	connectedThres->Update();
	return connectedThres->GetOutput();
}

class LineInteractorStyle : public vtkInteractorStyleTrackballCamera
{
public:
	static LineInteractorStyle* New();
	vtkTypeMacro(LineInteractorStyle, vtkInteractorStyleTrackballCamera);

	~LineInteractorStyle();
	virtual void OnLeftButtonDown();
	virtual void OnRightButtonDown();

	Input2dImageType::Pointer itkImage = nullptr;
	vtkSmartPointer<vtkImageViewer2> viewer;
	Ui::Mainwindow* window;
private:

};

vtkStandardNewMacro(LineInteractorStyle);

LineInteractorStyle::~LineInteractorStyle()
{
}

void LineInteractorStyle::OnLeftButtonDown()
{
		//视口坐标
		int* clickPos;
		clickPos = this->GetInteractor()->GetEventPosition();
		double point1[3]{ 0 };
		point1[0] = clickPos[0];
		point1[1] = clickPos[1];

		//世界坐标
		double worldPoint[3]{ 0 };
		this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->SetDisplayPoint(point1[0], point1[1], 0);
		this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->DisplayToWorld();
		worldPoint[0] = (this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->GetWorldPoint())[0];
		worldPoint[1] = (this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->GetWorldPoint())[1];
		worldPoint[2] = (this->Interactor->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->GetWorldPoint())[2];

		window->label_9->setText(QString::number(worldPoint[0]));
		window->label_10->setText(QString::number(worldPoint[1]));

		typedef itk::Point< double, 2 > PointType;
		PointType point;
		point[0] = worldPoint[0];
		point[1] = worldPoint[1];
		Input2dImageType::IndexType pixelIndex;
		bool isInside = this->itkImage->TransformPhysicalPointToIndex(point, pixelIndex);
		if (!isInside)
			return;
		int range[2] = { 226,3071 };
		Input2dImageType::PixelType value = this->itkImage->GetPixel(pixelIndex);
		if (value<range[0] || value>range[1])
			return;
		Input2dImageType::Pointer image1 = connectedThreshold(range, this->itkImage, pixelIndex);
		vtkSmartPointer<vtkImageData> image2 = itkToVtk(image1);
		vtkSmartPointer<vtkLookupTable> pColorTable = vtkSmartPointer<vtkLookupTable>::New();
		pColorTable->SetNumberOfColors(2);
		pColorTable->SetTableRange(0, 3071);
		pColorTable->SetTableValue(0, 0.0, 0.0, 0.0, 0.0);
		static bool flag = true;
		if (flag)
			pColorTable->SetTableValue(1, 0, 1, 0, 1.0);
		else
			pColorTable->SetTableValue(1, 0, 0, 1, 1.0);
		flag = !flag;
		pColorTable->Build();

		
		colorMap->SetInputData(image2);
		colorMap->SetLookupTable(pColorTable);
		colorMap->Update();


		colorActor->SetInputData(colorMap->GetOutput());
		colorActor->SetInterpolate(false);
		viewer->GetRenderer()->AddActor(colorActor);
		viewer->Render();
		
}

void LineInteractorStyle::OnRightButtonDown()
{
	viewer->GetRenderer()->RemoveActor(colorActor);
	viewer->Render();
}


Input2dImageType::Pointer read2dImage(const char* path)
{
	reader2d->SetFileName(path);
	reader2d->SetImageIO(gdcmImageIO);
	reader2d->Update();
	return reader2d->GetOutput();
}

void VTKReadJpg_InQT_Test::segment() {
	QString fileName = QFileDialog::getOpenFileName(
		this, tr("open image file"),
		"./", tr("Image files(*.dcm);;All files (*.*)"));

    vtkNew<vtkNamedColors> colors;
    char* ch;
    QByteArray ba = fileName.toLatin1(); // must
    ch = ba.data();
	ui.lineEdit->setText(fileName);
	Input2dImageType::Pointer itkImage = read2dImage(ch);
	imageViewer->SetInputData(itkToVtk(itkImage));
	imageViewer->SetSliceOrientationToXY();
	imageViewer->Render();
	imageViewer->GetRenderer()->SetBackground(0.5, 0.5, 0.5);
	imageViewer->SetColorLevel(0);
	imageViewer->SetColorWindow(1000);

	vtkSmartPointer<LineInteractorStyle> style = vtkSmartPointer<LineInteractorStyle>::New();
	style->itkImage = itkImage;
	style->viewer = imageViewer;
	style->window = &ui;


	imageViewer->GetRenderer()->SetBackground(1.0, 1.0, 1.0);                        // 设置页面底部颜色值
	imageViewer->GetRenderer()->SetBackground2(0.55, 0.53, 0.44);    // 设置页面顶部颜色值
	imageViewer->GetRenderer()->SetGradientBackground(1);


	imageViewer->SetupInteractor(renderWindowInteractor);
	renderWindowInteractor->SetInteractorStyle(style);
	imageViewer->GetRenderer()->GetRenderWindow()->GetInteractor()->SetInteractorStyle(style);
	
	imageViewer->Render();
	imageViewer->GetRenderer()->ResetCamera();
	ui.qvtkWidget->SetRenderWindow(imageViewer->GetRenderWindow());
	ui.qvtkWidget->GetRenderWindow()->Render();
	ui.qvtkWidget->update();
}

void VTKReadJpg_InQT_Test::saveimage(void) {
	QString fileName = QFileDialog::getSaveFileName(this,
		tr("save the file"),
		"",
		tr("BMP file(*.bmp)"));
	QFile file(fileName);

	if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		QMessageBox::critical(this, "critical", tr("文件保存失败！"),
			QMessageBox::Yes, QMessageBox::Yes);
	}
	else
	{
		char* ch;
		QByteArray ba = fileName.toLatin1(); // must
		ch = ba.data();
		vtkSmartPointer<vtkWindowToImageFilter> windowto_image_filter = vtkSmartPointer<vtkWindowToImageFilter>::New();
		windowto_image_filter->SetInput(imageViewer->GetRenderWindow());
		windowto_image_filter->SetScale(1);
		windowto_image_filter->SetInputBufferTypeToRGB();
		windowto_image_filter->ReadFrontBufferOff();
		windowto_image_filter->Update();
		vtkSmartPointer<vtkBMPWriter> writer = vtkSmartPointer<vtkBMPWriter>::New();
		writer->SetFileName(ch);
		writer->SetInputConnection(windowto_image_filter->GetOutputPort());
		writer->Write();
	}
}