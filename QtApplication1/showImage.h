# include "VTKReadJpg_InQT_Test.h"

#pragma once

void VTKReadJpg_InQT_Test::updateimage(void) {
    imageViewer->SetInputConnection(reader->GetOutputPort());
	QString Slice = ui.spinBox->text();
    QString ww = ui.spinBox_2->text();
    QString wl = ui.spinBox_3->text();
    if (Slice != "") {
        int tmp = Slice.toInt() - 1;
        imageViewer->SetSlice(tmp);
        int MaxSlice = imageViewer->GetSliceMax();
        int MinSlice = imageViewer->GetSliceMin();
        tmp = max(tmp, MinSlice);
        tmp = min(tmp, MaxSlice);
        std::string msg = StatusMessage::Format(tmp, MaxSlice);
        sliceTextMapper->SetInput(msg.c_str());
        myInteractorStyle->SetStatusMapper(sliceTextMapper);
    }
    if (ww != "")
    {
        int tmp = ww.toInt();
        imageViewer->SetColorWindow(tmp);
        
    }
    if (wl != "")
    {
        int tmp = wl.toInt();
        imageViewer->SetColorLevel(tmp);
    }
    imageViewer->Render();

}
void VTKReadJpg_InQT_Test::Reset(void) {
    //QString sww = QString::number(_ww);
    //QString swl = QString::number(_wl);

    ui.spinBox->setValue(0);
    ui.spinBox_2->setValue(_ww);
    ui.spinBox_3->setValue(_wl);
    VTKReadJpg_InQT_Test::updateimage();

}


class vtkMyMouseCommand2 : public vtkCommand
{
public:
    static vtkMyMouseCommand2* New()
    {
        return new vtkMyMouseCommand2;

    }

    virtual void Execute(vtkObject* caller, unsigned long eventId, void* callData)
    {
        int x, y;
        iren->GetEventPosition(x, y);
        window->label_9->setText(QString::number(x));
        window->label_10->setText(QString::number(y));



    }
    vtkRenderWindowInteractor* iren;
    Ui::Mainwindow* window;
};

void VTKReadJpg_InQT_Test::coloredimage(void) {

    //Build the lookupTable
   
    colorTable->SetRange(0.0, 255.0);
    colorTable->SetHueRange(0.1, 0.5);
    colorTable->SetValueRange(0.6, 1.0);
    colorTable->Build();

    //Mapping the color to the image.
   
    colorMap->SetInputConnection(reader->GetOutputPort());
    colorMap->SetLookupTable(colorTable);
    colorMap->Update();
    imageViewer->SetColorWindow(255.0);
    imageViewer->SetColorLevel(127.5);
    imageViewer->SetInputConnection(colorMap->GetOutputPort());
    imageViewer->Render();
    imageViewer->GetRenderer()->ResetCamera();
    ui.qvtkWidget->update();
}
void VTKReadJpg_InQT_Test::grayimage(void) {

    imageViewer->SetInputConnection(reader->GetOutputPort());
    imageViewer->Render();
    imageViewer->GetRenderer()->ResetCamera();
    ui.qvtkWidget->update();
}

void VTKReadJpg_InQT_Test::onOpenSlot(void) {
    
    ui.qvtkWidget->SetRenderWindow(imageViewer->GetRenderWindow());
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
        ui.lineEdit->setText(OpenFilePath);
        //使用vtkDICOMImageReader读取图像
        
        //注意把qstring转成char才能读
        char* ch;
        QByteArray ba = OpenFilePath.toLatin1(); // must
        ch = ba.data();
        reader->SetDirectoryName(ch);
        //reader->SetDirectoryName("D:/code/qtvtk/Heart-unzip");

        reader->Update();
        //将reader 的输出作为 viewer的输入，并且设置Viewer与渲染器的关联

        

        imageViewer->SetInputConnection(reader->GetOutputPort());
        _ww = imageViewer->GetColorWindow();
        _wl = imageViewer->GetColorLevel();
        // slice status message

        sliceTextProp->SetFontFamilyToCourier();
        sliceTextProp->SetFontSize(20);
        sliceTextProp->SetVerticalJustificationToBottom();
        sliceTextProp->SetJustificationToLeft();
        sliceTextProp->SetColor(1, 255, 1);

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

        QString strQ = QString::fromLocal8Bit(patientText.c_str());

        QString s1 = QString::number(imageViewer->GetSliceMin());
        QString s2 = QString::number(imageViewer->GetSliceMax());

        ui.label_12->setText(strQ);
        ui.label_14->setText(s1);
        ui.label_15->setText(s2);

        usageTextProp->SetFontFamilyToCourier();
        usageTextProp->SetFontSize(20);
        usageTextProp->SetColor(255, 1, 1);
        usageTextProp->SetVerticalJustificationToTop();
        usageTextProp->SetJustificationToLeft();



        usageTextMapper->SetInput(patientText.c_str());
        usageTextMapper->SetTextProperty(usageTextProp);


        usageTextActor->SetMapper(usageTextMapper);
        usageTextActor->GetPositionCoordinate()
            ->SetCoordinateSystemToNormalizedDisplay();
        usageTextActor->GetPositionCoordinate()->SetValue(0.02, 0.98);





        // make imageviewer2 and sliceTextMapper visible to our interactorstyle
        // to enable slice status message updates when scrolling through the slices
        myInteractorStyle->SetImageViewer(imageViewer);
        myInteractorStyle->SetStatusMapper(sliceTextMapper);

        // imageViewer->SetSliceOrientationToXZ();
        imageViewer->SetupInteractor(renderWindowInteractor);
        // make the interactor use our own interactorstyle
        // cause SetupInteractor() is defining it's own default interatorstyle
        // this must be called after SetupInteractor()
        renderWindowInteractor->SetInteractorStyle(myInteractorStyle);
        // add slice status message and usage hint message to the renderer
        imageViewer->GetRenderer()->AddActor2D(sliceTextActor);
        imageViewer->GetRenderer()->AddActor2D(usageTextActor);




        imageViewer->GetRenderer()->SetBackground(1.0, 1.0, 1.0);                        // 设置页面底部颜色值
        imageViewer->GetRenderer()->SetBackground2(0.55, 0.53, 0.44);    // 设置页面顶部颜色值
        imageViewer->GetRenderer()->SetGradientBackground(1);                           // 开启渐变色背景设置
        // initialize rendering and interaction
        imageViewer->Render();





        vtkNew<vtkMyMouseCommand2> mouseCommand;
       
        mouseCommand->iren = renderWindowInteractor;
        mouseCommand->window = &ui;


        renderWindowInteractor->AddObserver(vtkCommand::LeftButtonPressEvent, mouseCommand);



        imageViewer->GetRenderWindow()->SetSize(880, 750);
        imageViewer->GetRenderWindow()->SetWindowName("ReadDICOMSeries");
        imageViewer->Render();


        ui.qvtkWidget->GetRenderWindow()->Render();
        ui.qvtkWidget->update();


    }
}
void VTKReadJpg_InQT_Test::changeviewXZ(void) {
    imageViewer->SetSliceOrientationToXZ();
    imageViewer->Render();
}
void VTKReadJpg_InQT_Test::changeviewYZ(void) {
    imageViewer->SetSliceOrientationToYZ();
    imageViewer->Render();
}
void VTKReadJpg_InQT_Test::changeviewXY(void) {
    imageViewer->SetSliceOrientationToXY();
    imageViewer->Render();
}