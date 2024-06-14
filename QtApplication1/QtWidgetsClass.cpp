//#include "QtWidgetsClass.h"
#include "VTKReadJpg_InQT_Test.h"
#include <vtkSmartPointer.h>
#include <vtkStructuredPointsReader.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkMarchingCubes.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <sstream>
#include <vtkSmoothPolyDataFilter.h>
#include <vtkFloatArray.h>
#include <vtkPointData.h>
#include <vtkProperty.h>

#include "itkImage.h"
#include "itkImageFileWriter.h"
#include "itkConnectedThresholdImageFilter.h"
#include "itkBinaryThresholdImageFilter.h"
#include "itkCastImageFilter.h"
#include "itkGradientMagnitudeRecursiveGaussianImageFilter.h"
#include "itkWatershedImageFilter.h"
#include <itkImageToVTKImageFilter.h>
#include <itkVTKImageToImageFilter.h>
#include "itkScalarToRGBColormapImageFilter.h"
#include <vtkImageActor.h>
#include <vtkImageMapper3D.h>
#include <vector>
#include <vtkCamera.h>
#include <vtkDataArray.h>
#include <vtkImageActor.h>
#include <vtkImageCast.h>
#include <vtkImageData.h>
#include <vtkImageLaplacian.h>
#include <vtkImageMapToWindowLevelColors.h>
#include <vtkImageMapper3D.h>
#include <vtkImageMathematics.h>
#include <vtkImageProperty.h>
#include <vtkImageReader2.h>
#include <vtkImageReader2Factory.h>
#include <vtkImageThreshold.h>
#include <vtkInteractorStyleImage.h>
#include <vtkNew.h>
#include <vtkNamedColors.h>
#include <vtkObjectFactory.h>
#include <vtkDICOMImageReader.h>
#include <vtkImageViewer2.h>
#include <vtkTextMapper.h>
#include <vtkPlane.h>
#include <vtkSTLWriter.h>
#include <vtkInteractorStyleTrackball.h>
#include <vtkClipPolyData.h>
typedef float  InternalPixelType;

using PixelType = short;
typedef itk::RGBPixel<unsigned char> RGBPixelType;

using ImageType = itk::Image<PixelType, 3>;
using RGBImageType = itk::Image<RGBPixelType, 3>;
using InternalImageType = itk::Image<InternalPixelType, 3>;
typedef itk::Image<itk::IdentifierType, 3> LabeledImageType;
static void CreateImage(ImageType::Pointer image);


void VTKReadJpg_InQT_Test::seg3d2(void) {
	std::string folder = "D://code//qtvtk//Heart-New";

	vtkNew<vtkDICOMImageReader> reader;
	reader->SetDirectoryName(folder.c_str());
	reader->Update();

	using ConnectorVTKType = itk::VTKImageToImageFilter<ImageType>;
	ConnectorVTKType::Pointer connectorVtk = ConnectorVTKType::New();
	connectorVtk->SetInput(reader->GetOutput());
	connectorVtk->Update();

	ImageType::Pointer image = connectorVtk->GetOutput();
	float lower = 340;
	float upper = 490;

	using ConnectedFilterType = itk::ConnectedThresholdImageFilter<ImageType, ImageType>;
	ConnectedFilterType::Pointer connectedThreshold = ConnectedFilterType::New();

	connectedThreshold->SetLower(lower);
	connectedThreshold->SetUpper(upper);

	connectedThreshold->SetReplaceValue(255);

	ImageType::IndexType seed1;
	seed1[0] = 222;
	seed1[1] = 253;
	seed1[2] = 171;
	connectedThreshold->SetSeed(seed1);
	connectedThreshold->SetInput(image);

	// Visualize
	using ConnectorType = itk::ImageToVTKImageFilter<ImageType>;
	ConnectorType::Pointer connector2 = ConnectorType::New();
	connector2->SetInput(connectedThreshold->GetOutput());

	vtkSmartPointer<vtkImageActor> actor2 = vtkSmartPointer<vtkImageActor>::New();
	actor2->SetZSlice(14);
#if VTK_MAJOR_VERSION <= 5
	actor2->SetInput(connector->GetOutput());
#else
	connector2->Update();
	actor2->GetMapper()->SetInputData(reader->GetOutput());
#endif

	// Visualize joined image
	ConnectorType::Pointer addConnector = ConnectorType::New();
	addConnector->SetInput(connectedThreshold->GetOutput());

	vtkSmartPointer<vtkImageActor> addActor = vtkSmartPointer<vtkImageActor>::New();
	addActor->SetZSlice(14);
#if VTK_MAJOR_VERSION <= 5
	addActor->SetInput(connector->GetOutput());
#else
	addConnector->Update();
	addActor->GetMapper()->SetInputData(addConnector->GetOutput());
#endif

	//用移动立方体法提取等值面。
	vtkSmartPointer<vtkMarchingCubes> marchingCubes = vtkSmartPointer<vtkMarchingCubes>::New();
	marchingCubes->SetInputData(connector2->GetOutput());
	marchingCubes->SetValue(0, 255);

	//平滑
	vtkSmartPointer<vtkSmoothPolyDataFilter> smoothFilter = vtkSmartPointer<vtkSmoothPolyDataFilter>::New();
	smoothFilter->SetInputConnection(marchingCubes->GetOutputPort());
	smoothFilter->SetNumberOfIterations(100);
	smoothFilter->Update();

	//定义一个平面
	vtkNew<vtkPlane> clipPlane;
	clipPlane->SetNormal(1, 0, -1);
	clipPlane->SetOrigin(50, 40, 96);

	//平面来切割三维数据
	vtkSmartPointer<vtkClipPolyData> clipper = vtkSmartPointer<vtkClipPolyData>::New();
	clipper->SetInputConnection(smoothFilter->GetOutputPort());
	clipper->SetClipFunction(clipPlane);
	clipper->InsideOutOn();
	clipper->GenerateClipScalarsOn();
	clipper->GenerateClippedOutputOn();
	clipper->SetValue(0.5);
	clipper->Update();

	//-------------------------------------------------------------------------
		//定义一个平面
	vtkNew<vtkPlane> clipPlane2;
	clipPlane2->SetNormal(1, 0, 1);
	clipPlane2->SetOrigin(60, 60, 45);

	//平面来切割三维数据
	vtkSmartPointer<vtkClipPolyData> clipper2 = vtkSmartPointer<vtkClipPolyData>::New();
	clipper2->SetInputConnection(clipper->GetOutputPort());
	clipper2->SetClipFunction(clipPlane2);
	//clipper2->InsideOutOn();
	clipper2->GenerateClipScalarsOn();
	clipper2->GenerateClippedOutputOn();
	clipper2->SetValue(0.5);
	clipper2->Update();

	//定义一个平面
	vtkNew<vtkPlane> clipPlane3;
	clipPlane3->SetNormal(0.03, 1, 0);
	clipPlane3->SetOrigin(90, 68, 45);
	//clipPlane3->SetNormal(-0.3, 1, 0);
	//clipPlane3->SetOrigin(90, 95, 45);

	//平面来切割三维数据
	vtkSmartPointer<vtkClipPolyData> clipper3 = vtkSmartPointer<vtkClipPolyData>::New();
	clipper3->SetInputConnection(clipper2->GetOutputPort());
	clipper3->SetClipFunction(clipPlane3);
	//clipper2->InsideOutOn();
	clipper3->GenerateClipScalarsOn();
	clipper3->GenerateClippedOutputOn();
	clipper3->SetValue(0.5);
	clipper3->Update();

	//定义一个平面
	vtkNew<vtkPlane> clipPlane4;
	clipPlane4->SetNormal(1, 0, 1);
	clipPlane4->SetOrigin(60, 60, 150);
	//clipPlane4->SetOrigin(60, 60, 122);

	//平面来切割三维数据
	vtkSmartPointer<vtkClipPolyData> clipper4 = vtkSmartPointer<vtkClipPolyData>::New();
	clipper4->SetInputConnection(clipper3->GetOutputPort());
	clipper4->SetClipFunction(clipPlane4);
	clipper4->InsideOutOn();
	clipper4->GenerateClipScalarsOn();
	clipper4->GenerateClippedOutputOn();
	clipper4->SetValue(0.5);
	clipper4->Update();
	//----------------------------------------------------------------------

	//将生成的等值面数据进行Mapper
	vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapper->SetInputConnection(clipper4->GetOutputPort());
	mapper->SetColorModeToMapScalars();
	//mapper->AddClippingPlane(clipPlane);

	//写出为STL格式
	std::string file_path_str = "D:/0fly/homework/Vessel-Heart.stl";
	vtkSmartPointer<vtkSTLWriter> stlWriter = vtkSmartPointer<vtkSTLWriter>::New();
	stlWriter->SetFileName(file_path_str.c_str());
	stlWriter->SetInputConnection(clipper4->GetOutputPort());
	stlWriter->Write();
	stlWriter->Update();

	//把Mapper的输出送入渲染引擎进行显示
	//////////////////////////////////////渲染引擎部分////////////////////////////////////
	vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);

	vtkSmartPointer<vtkProperty> property = vtkSmartPointer<vtkProperty>::New();
	property->SetDiffuseColor(1, 0.49, 0.25);
	property->SetDiffuse(0.7);
	property->SetSpecular(0.3);
	property->SetSpecularPower(20);
	property->SetOpacity(0.3);
	actor->SetProperty(property); //设置透明度


	// There will be one render window
	vtkSmartPointer<vtkRenderWindow> renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
	renderWindow->SetSize(1000, 500);

	vtkSmartPointer<vtkRenderWindowInteractor> interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
	interactor->SetRenderWindow(renderWindow);

	// Setup both renderers
	vtkSmartPointer<vtkRenderer> rightRenderer = vtkSmartPointer<vtkRenderer>::New();
	renderWindow->AddRenderer(rightRenderer);
	rightRenderer->SetBackground(.4, .5, .6);

	// Add the sphere to the left and the cube to the right
	rightRenderer->AddActor(actor);
	rightRenderer->ResetCamera();
	renderWindow->Render();

	vtkSmartPointer<vtkInteractorStyleTrackballCamera> style = vtkSmartPointer<vtkInteractorStyleTrackballCamera>::New();
	interactor->SetInteractorStyle(style);
	ui.qvtkWidget->SetRenderWindow(renderWindow);
	ui.qvtkWidget->update();
	/*interactor->Start();*/
}

QtWidgetsClass::QtWidgetsClass(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	m_parent = static_cast<VTKReadJpg_InQT_Test*>(parent);
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(exeseg()));
	connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(opendict()));

}

QtWidgetsClass::~QtWidgetsClass()
{
}
void QtWidgetsClass::opendict(void) {
	QString FileInstruction;
	FileInstruction = "Image Files(*.dcm);;All(*.*)";
	QDir FileDir;
	QString Directory = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "D://", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
	QString OpenFilePath;
	if (Directory != "")
	{
		//显示路径
		QFileInfo OpenFileInfo;
		OpenFileInfo = QFileInfo(Directory);
		OpenFilePath = OpenFileInfo.filePath();
		ui.textEdit_4->setText(OpenFilePath);
	}
}
void QtWidgetsClass::exeseg(void) {
	this->close();
	m_parent->seg3d2();
}


