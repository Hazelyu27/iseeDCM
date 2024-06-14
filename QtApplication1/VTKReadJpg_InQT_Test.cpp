#include "VTKReadJpg_InQT_Test.h"
#include <vtkDICOMImageReader.h>
#include <itkImageToVTKImageFilter.h>
#include "fourpanel.h"
#include "segment.h"
#include "showImage.h"
#include "volumnRender.h"
#define VTK_CREATE(type,name) \
    vtkSmartPointer<type> name = vtkSmartPointer<type>::New()
// needed to easily convert int to std::string


VTKReadJpg_InQT_Test::VTKReadJpg_InQT_Test(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->setWindowIcon(QIcon("./aiej7-c3qli-001.ico"));
    //this->setStyleSheet(" QWidget{background-color:rgb(30,31,28);} QMenuBar{color:rgb(255,255,255)}  QMenu{color:rgb(255,255,255);}");
    
    this->resize(QSize(1200, 900));
    // 提示框
   /* ui.pushButton_4->setToolTip("pushButton_4");*/
    
//
    imageViewer = vtkSmartPointer<vtkImageViewer2>::New();
    sliceTextProp = vtkSmartPointer<vtkTextProperty>::New();
    sliceTextMapper = vtkSmartPointer<vtkTextMapper>::New();

    sliceTextActor = vtkSmartPointer<vtkActor2D>::New();

    usageTextProp = vtkSmartPointer<vtkTextProperty>::New();
    reader = vtkSmartPointer<vtkDICOMImageReader>::New();
    usageTextMapper = vtkSmartPointer<vtkTextMapper>::New();
    usageTextActor = vtkSmartPointer<vtkActor2D>::New();
    renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    renderWindow = vtkSmartPointer < vtkRenderWindow>::New();
    myInteractorStyle = vtkSmartPointer<myVtkInteractorStyleImage>::New();
    connect(ui.actionOpen_Directory, SIGNAL(triggered()), this, SLOT(onOpenSlot()));
    // 按下pushButton_2 三正交时，执行三正交 threeshow 函数
   // connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(threeshow()));
    // 按下pushButton_3 体渲染时，执行体渲染 函数
    connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(volumnRender()));

    connect(ui.pushButton_3, SIGNAL(clicked(bool)), this, SLOT(fourpa()));
    connect(ui.pushButton_4, SIGNAL(clicked(bool)), this, SLOT(onOpenSlot()));
    connect(ui.pushButton_8, SIGNAL(clicked(bool)), this, SLOT(Reset()));
    connect(ui.pushButton_5, SIGNAL(clicked(bool)), this, SLOT(segment()));
    connect(ui.pushButton_9, SIGNAL(clicked(bool)), this, SLOT(updateimage()));

    connect(ui.pushButton_11, SIGNAL(clicked(bool)), this, SLOT(coloredimage()));
    QPushButton * quitButton = new QPushButton("Quit");
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quit()));
    
   // connect(ui., SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(saveimage()));
    connect(ui.toolButton_4, SIGNAL(clicked()), this, SLOT(changeviewXZ()));
    connect(ui.toolButton_5, SIGNAL(clicked()), this, SLOT(changeviewYZ()));
    connect(ui.toolButton_3, SIGNAL(clicked()), this, SLOT(changeviewXY()));
    connect(ui.pushButton_10, SIGNAL(clicked(bool)), this, SLOT(seg3d()));
    connect(ui.pushButton_6, SIGNAL(clicked(bool)), this, SLOT(centerline()));
    
}
void VTKReadJpg_InQT_Test::seg3d() {
    cw = new QtWidgetsClass(this);
    cw->show();
}
//void VTKReadJpg_InQT_Test::mouseMoveEvent(QMouseEvent* e)
//{
//    this->setMouseTracking(true);//to hint text
//    this->setToolTip("yes");
//}
void VTKReadJpg_InQT_Test::closeEvent(QCloseEvent* event)
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
void VTKReadJpg_InQT_Test::showimage() {
    QString filedirectory = ui.lineEdit->text();
    vtkNew<vtkNamedColors> colors;
    char* ch;
    QByteArray ba = filedirectory.toLatin1(); // must
    ch = ba.data();
    if (ch != "") {
        //使用vtkDICOMImageReader读取图像
        vtkSmartPointer<vtkDICOMImageReader>reader = vtkSmartPointer<vtkDICOMImageReader>::New();
        //注意把qstring转成char才能读

        reader->SetDirectoryName(ch);
        //reader->SetDirectoryName("D:/code/qtvtk/Heart-unzip");

        reader->Update();
        //将reader 的输出作为 viewer的输入，并且设置Viewer与渲染器的关联


        imageViewer->SetInputConnection(reader->GetOutputPort());

        // slice status message

        sliceTextProp->SetFontFamilyToCourier();
        sliceTextProp->SetFontSize(20);
        sliceTextProp->SetVerticalJustificationToBottom();
        sliceTextProp->SetJustificationToLeft();


        std::string msg = StatusMessage::Format(imageViewer->GetSliceMin(),
            imageViewer->GetSliceMax());
        sliceTextMapper->SetInput(msg.c_str());
        sliceTextMapper->SetTextProperty(sliceTextProp);


        sliceTextActor->SetMapper(sliceTextMapper);
        sliceTextActor->GetPositionCoordinate()
            ->SetCoordinateSystemToNormalizedDisplay();
        sliceTextActor->GetPositionCoordinate()->SetValue(0.02, 0.02);

        // patient message
        std::string descriptive = reader->GetDescriptiveName();
        std::string name = reader->GetPatientName();
        std::string patientText = descriptive + "\n" + name;


        usageTextProp->SetFontFamilyToCourier();
        usageTextProp->SetFontSize(20);
        usageTextProp->SetVerticalJustificationToTop();
        usageTextProp->SetJustificationToLeft();



        usageTextMapper->SetInput(patientText.c_str());
        usageTextMapper->SetTextProperty(usageTextProp);


        usageTextActor->SetMapper(usageTextMapper);
        usageTextActor->GetPositionCoordinate()
            ->SetCoordinateSystemToNormalizedDisplay();
        usageTextActor->GetPositionCoordinate()->SetValue(0.02, 0.98);

        // create an interactor with our own style (inherit from
        // vtkInteractorStyleImage) in order to catch mousewheel and key events


        // make imageviewer2 and sliceTextMapper visible to our interactorstyle
        // to enable slice status message updates when scrolling through the slices
        myInteractorStyle->SetImageViewer(imageViewer);
        myInteractorStyle->SetStatusMapper(sliceTextMapper);

        imageViewer->SetupInteractor(renderWindowInteractor);
        // make the interactor use our own interactorstyle
        // cause SetupInteractor() is defining it's own default interatorstyle
        // this must be called after SetupInteractor()
        renderWindowInteractor->SetInteractorStyle(myInteractorStyle);
        // add slice status message and usage hint message to the renderer
        imageViewer->GetRenderer()->AddActor2D(sliceTextActor);
        imageViewer->GetRenderer()->AddActor2D(usageTextActor);

        // initialize rendering and interaction
        imageViewer->Render();
        imageViewer->GetRenderer()->ResetCamera();

        imageViewer->GetRenderWindow()->SetSize(880, 750);
        imageViewer->GetRenderWindow()->SetWindowName("ReadDICOMSeries");
        imageViewer->Render();


        ui.qvtkWidget->GetRenderWindow()->Render();
    }
   
}



//void VTKReadJpg_InQT_Test::threeshow(void)
//{
//    QString filedirectory = ui.lineEdit->text();
//    vtkNew<vtkNamedColors> colors;
//    char* ch;
//    QByteArray ba = filedirectory.toLatin1(); // must
//    ch = ba.data();
// 
//    //// Read all the DICOM files in the specified directory.
//    //vtkNew<vtkDICOMImageReader> reader;
//    reader->SetDirectoryName(ch);
//    reader->Update();
//
//    // Get the dimensions of the image.
//    int dimensions[3] = { 0,0,0 };
//    reader->GetOutput()->GetDimensions(dimensions);
//
//    //Init the vtkImagePlaneWidget for the x、y、z orientation.
//    vtkNew<vtkImagePlaneWidget> imagePlaneX;
//    vtkNew<vtkImagePlaneWidget> imagePlaneY;
//    vtkNew<vtkImagePlaneWidget> imagePlaneZ;
//
//    //Init the picker for the vtkImagePlaneWidget.
//    vtkNew<vtkCellPicker> picker;
//
//    //Set the property of the imagePlane.
//    imagePlaneX->SetInputData(reader->GetOutput());
//    imagePlaneX->SetPicker(picker);
//    imagePlaneX->RestrictPlaneToVolumeOn();
//    //  imagePlaneX->GetMarginProperty()->SetOpacity(0);
//    imagePlaneX->SetMarginSizeX(0);
//    imagePlaneX->SetMarginSizeY(0);
//    imagePlaneX->DisplayTextOn();
//    imagePlaneX->SetResliceInterpolateToLinear();
//    imagePlaneX->SetPlaneOrientationToXAxes();
//    imagePlaneX->SetWindowLevel(800, 400, 0);
//    imagePlaneX->SetSliceIndex(dimensions[0] / 2);
//    imagePlaneX->SetLeftButtonAction(1);
//    imagePlaneX->SetMiddleButtonAction(0);
//    // imagePlaneX->GetTexturePlaneProperty()->SetOpacity(1);
//
//    imagePlaneY->SetInputData(reader->GetOutput());
//    imagePlaneY->SetPicker(picker);
//    imagePlaneY->RestrictPlaneToVolumeOn();
//    // imagePlaneY->GetMarginProperty()->SetOpacity(0);
//    imagePlaneY->SetMarginSizeX(0);
//    imagePlaneY->SetMarginSizeY(0);
//    imagePlaneY->DisplayTextOn();
//    imagePlaneY->SetResliceInterpolateToLinear();
//    imagePlaneY->SetPlaneOrientationToYAxes();
//    imagePlaneY->SetWindowLevel(800, 400, 0);
//    imagePlaneY->SetSliceIndex(dimensions[1] / 2);
//    imagePlaneY->SetLeftButtonAction(1);
//    imagePlaneY->SetMiddleButtonAction(0);
//    //  imagePlaneY->GetTexturePlaneProperty()->SetOpacity(1);
//
//    imagePlaneZ->SetInputData(reader->GetOutput());
//    imagePlaneZ->SetPicker(picker);
//    imagePlaneZ->RestrictPlaneToVolumeOn();
//    //  imagePlaneZ->GetMarginProperty()->SetOpacity(0);
//    imagePlaneZ->SetMarginSizeX(0);
//    imagePlaneZ->SetMarginSizeY(0);
//    imagePlaneZ->DisplayTextOn();
//    imagePlaneZ->SetResliceInterpolateToLinear();
//    imagePlaneZ->SetPlaneOrientationToZAxes();
//    imagePlaneZ->SetWindowLevel(800, 400, 0);
//    imagePlaneZ->SetSliceIndex(dimensions[2] / 2);
//    imagePlaneZ->SetLeftButtonAction(1);
//    imagePlaneZ->SetMiddleButtonAction(0);
//    //  imagePlaneZ->GetTexturePlaneProperty()->SetOpacity(1);
//
//        // initialize rendering and interaction
//    vtkNew<vtkRenderer> renderer;
//    /*vtkNew<vtkRenderWindow> renderWindow;*/
//   
//    ui.qvtkWidget->SetRenderWindow(renderWindow);
//    renderWindow->AddRenderer(renderer);
//    renderWindow->SetSize(880, 750);
//    renderWindow->SetWindowName("3D");
//
//    
//    renderWindowInteractor->SetRenderWindow(renderWindow);
//
//    vtkNew<vtkInteractorStyleTrackballCamera> style;
//    renderWindowInteractor->SetInteractorStyle(style);
//
//    // vtkOrientationMarkerWidget
//    vtkNew<vtkAxesActor> iconActor;
//    vtkNew<vtkOrientationMarkerWidget> orientationWidget;
//    orientationWidget->SetOutlineColor(0.9300, 0.5700, 0.1300);
//    orientationWidget->SetOrientationMarker(iconActor);
//    orientationWidget->SetInteractor(renderWindowInteractor);
//    orientationWidget->SetViewport(0.0, 0.0, 0.2, 0.2);
//    orientationWidget->SetEnabled(1);
//    orientationWidget->InteractiveOn();
//
//    //Render
//    renderWindow->Render();
//    imagePlaneX->SetInteractor(renderWindowInteractor);
//    imagePlaneY->SetInteractor(renderWindowInteractor);
//    imagePlaneZ->SetInteractor(renderWindowInteractor);
//
//    renderWindowInteractor->Initialize();
//    imagePlaneX->On();
//    imagePlaneY->On();
//    imagePlaneZ->On();
//    renderer->ResetCamera();
//
//    ui.qvtkWidget->GetRenderWindow()->Render();
//
//}

void VTKReadJpg_InQT_Test::fourpa(void) {
    FourPanel *pic = new FourPanel;
    pic->show();
    
}
