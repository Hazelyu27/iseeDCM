#include "fourpanel.h"
# include "VTKReadJpg_InQT_Test.h"

#include <QtWidgets/QApplication>


int main(int argc, char* argv[])
{
    // move the warning
    vtkOutputWindow::SetGlobalWarningDisplay(0);
    QApplication a(argc, argv);

    //Mainwindow w;
    
    VTKReadJpg_InQT_Test w;
    w.show();
    return a.exec();
}

