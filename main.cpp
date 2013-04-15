#include<QApplication>
#include<websis.h>
#include"gui.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Websis Desktop Application");
    a.setOrganizationName("LUG Manipal");
    a.setOrganizationDomain("rajatgupta431@gmail.com");
    qApp->addLibraryPath("C:/Qt/4.8.4/plugins/imageformats");


    makegui gogoi;


    return a.exec();
}
