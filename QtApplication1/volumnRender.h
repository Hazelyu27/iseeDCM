#pragma once
#include "VTKReadJpg_InQT_Test.h"
class vtkMyMouseCommand : public vtkCommand
{
public:
    static vtkMyMouseCommand* New()
    {
        return new vtkMyMouseCommand;
    }

    virtual void Execute(vtkObject* caller, unsigned long eventId, void* callData)
    {
        int x, y;
        iren->GetEventPosition(x, y);
        picker->Pick(x, y, 0, ren);

        double p[3];
        picker->GetPickPosition(p);
        cout << "coordinate: " << p[0] << " " << p[1] << " " << p[2] << std::endl;

        int dims[3];
        reader->GetOutput()->GetDimensions(dims);
        //std::cout << dims[0] << " " << dims[1] << " " << dims[2] << std::endl;
        int intp[3];
        intp[0] = int(p[0]);
        intp[1] = int(p[1]);
        intp[2] = int(p[2] / 3);
        if (intp[0] >= 0 && intp[0] < dims[0] && intp[1] >= 0 && intp[1] < dims[1] && intp[2] >= 0 && intp[2] < dims[2])
        {
            unsigned char* pixel = (unsigned char*)(reader->GetOutput()->GetScalarPointer(intp[0], intp[1], intp[2]));
            cout << "voxel value: " << int(*pixel) << " " << int(*(pixel + 1)) << " " << int(*(pixel + 2)) << std::endl;
            string str[3];
            str[0] = to_string(int(*pixel));
            str[1] = to_string(int(*(pixel + 1)));
            str[2] = to_string(int(*(pixel + 2)));
            string strpixel = str[0] + "," + str[1] + "," + str[2];
            const char* conchar;
            conchar = strpixel.c_str();
            textSource->SetText(conchar);

            redCone->SetPosition(p[0], p[1], p[2]);
            blueCone->SetPosition(p[0], p[1], p[2]);

            textMapper->SetInputConnection(textSource->GetOutputPort());
            textFollower->SetPosition(p[0] + 36, p[1] + 36, p[2] + 36);
            textFollower->SetMapper(textMapper);
            textFollower->GetProperty()->SetColor(0.0, 0.0, 1.0);
            textFollower->SetScale(15, 15, 15);
            textFollower->SetCamera(ren->GetActiveCamera());
            ren->AddActor(textFollower);

            distanceWidget->SetInteractor(iren);

            distanceWidget->CreateDefaultRepresentation();
            static_cast<vtkPointHandleRepresentation3D*> (distanceWidget->GetRepresentation());
            //->SetHandleSize(10);
            distanceWidget->On();

            iren->Render();
        }
    }
    vtkDICOMImageReader* reader;
    vtkRenderWindow* renWin;
    vtkRenderer* ren;
    vtkRenderWindowInteractor* iren;
    vtkVolumePicker* picker;
    vtkActor* redCone;
    vtkActor* blueCone;
    vtkFollower* textFollower;
    vtkVectorText* textSource;
    vtkPolyDataMapper* textMapper;
    vtkDistanceWidget* distanceWidget;
};
void VTKReadJpg_InQT_Test::volumnRender(void) {

    QString filedirectory = ui.lineEdit->text();
    vtkNew<vtkNamedColors> colors;
    char* ch;
    QByteArray ba = filedirectory.toLatin1(); // must
    ch = ba.data();



    vtkNew<vtkDICOMImageReader> reader;
    reader->SetDirectoryName(ch);
    reader->Update();

    vtkNew<vtkPiecewiseFunction> opacityTransferFunction;
    opacityTransferFunction->AddPoint(20, 0.0);
    opacityTransferFunction->AddPoint(255, 0.1);
    opacityTransferFunction->AddPoint(1005, 0.6);

    vtkNew<vtkColorTransferFunction> colorTransferFunction;
    colorTransferFunction->AddRGBPoint(0.0, 0.0, 0.5, 0.0);
    colorTransferFunction->AddRGBPoint(60.0, 1.0, 0.0, 0.0);
    colorTransferFunction->AddRGBPoint(128.0, 0.2, 0.1, 0.9);
    colorTransferFunction->AddRGBPoint(196.0, 0.27, 0.21, 0.1);
    colorTransferFunction->AddRGBPoint(255.0, 0.8, 0.8, 0.8);

    vtkNew<vtkVolumeProperty> volumeProperty;
    volumeProperty->SetColor(colorTransferFunction);
    volumeProperty->SetScalarOpacity(opacityTransferFunction);
    volumeProperty->ShadeOn();
    volumeProperty->SetInterpolationTypeToLinear();
    volumeProperty->SetAmbient(0.2);
    volumeProperty->SetDiffuse(0.4);
    volumeProperty->SetSpecular(0.6);
    volumeProperty->SetSpecularPower(10);

    vtkNew<vtkGPUVolumeRayCastMapper> volumeMapper;
    volumeMapper->SetInputConnection(reader->GetOutputPort());

    vtkNew<vtkVolume> volume;
    volume->SetMapper(volumeMapper);
    volume->SetProperty(volumeProperty);

    vtkNew<vtkRenderer> renderer;
    renderer->AddVolume(volume);
    renderer->SetBackground(1.0, 1.0, 1.0);                        // 设置页面底部颜色值
    renderer->SetBackground2(0.529, 0.8078, 0.92157);    // 设置页面顶部颜色值
    renderer->SetGradientBackground(1);                           // 开启渐变色背景设置


    vtkNew<vtkSphereSource> sphereSource;
    sphereSource->SetCenter(0, 0, 0);
    sphereSource->SetRadius(10);
    sphereSource->SetThetaResolution(40);
    sphereSource->SetPhiResolution(40);
    sphereSource->Update();

    vtkNew<vtkDataSetMapper> coneMapper;
    coneMapper->SetInputConnection(sphereSource->GetOutputPort());

    vtkNew<vtkActor> blueCone;
    blueCone->PickableOff();
    blueCone->SetMapper(coneMapper);
    blueCone->GetProperty()->SetColor(0, 0, 1);

    vtkNew<vtkActor> redCone;
    redCone->PickableOff();
    redCone->SetMapper(coneMapper);
    redCone->GetProperty()->SetColor(1, 0, 0);

    //renderer->AddViewProp(redCone);
    renderer->AddViewProp(blueCone);;

    //the picker
    vtkNew<vtkVolumePicker> picker;
    picker->SetTolerance(1e-6);
    picker->SetVolumeOpacityIsovalue(0.1);

    vtkNew<vtkRenderWindow> renWin;
    vtkNew<vtkRenderWindowInteractor> iren;
    iren->SetRenderWindow(renWin);

    ui.qvtkWidget->SetRenderWindow(iren->GetRenderWindow());
    renWin->AddRenderer(renderer);
    renWin->SetSize(640, 480);
    renWin->Render();
    renWin->SetWindowName("volumeRender");


    
    vtkNew<vtkVectorText>textSource;
    auto textMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    auto textFollower = vtkSmartPointer<vtkFollower>::New();

    vtkNew<vtkDistanceWidget> distanceWidget;

    vtkNew<vtkMyMouseCommand> mouseCommand;
    mouseCommand->reader = reader;
    mouseCommand->renWin = renWin;
    mouseCommand->ren = renderer;
    mouseCommand->iren = iren;
    mouseCommand->picker = picker;
    mouseCommand->redCone = redCone;
    mouseCommand->blueCone = blueCone;
    mouseCommand->textFollower = textFollower;
    mouseCommand->textSource = textSource;
    mouseCommand->textMapper = textMapper;
    mouseCommand->distanceWidget = distanceWidget;
    iren->AddObserver(vtkCommand::LeftButtonPressEvent, mouseCommand);

    vtkNew<vtkInteractorStyleTrackballCamera> style;
    iren->SetInteractorStyle(style);

    iren->Initialize();
    iren->Start();


    ui.qvtkWidget->GetRenderWindow()->Render();
    ui.qvtkWidget->update();
}