#include "QtWidget.h"
#include "mainwindow.h"
#include "QtWidget.h"
#include <QBoxLayout>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow::getInstance()->show();

    MainWindow::getInstance()->createMesh(Ogre::Vector3(200,0,100),
                                           "robot", "RobotMaterial");
    MainWindow::getInstance()->createMesh(Ogre::Vector3(100,0,100),
                                           "razor", "RobotMaterial");
    MainWindow::getInstance()->createMesh(Ogre::Vector3(0,0,100),
                                           "robot", "Template/texture_map");

    return app.exec();
}
