#include "QtWidget.h"
#include "mainwindow.h"
#include "QtWidget.h"
#include <QBoxLayout>
#include <QPushButton>

#include "Engine/Object.h"
#include "Engine/GameObject.h"
#include "Engine/Component.h"
#include "Engine/MeshRenderer.h"


int main(int argc, char **argv)
{

    QApplication app(argc, argv);
    MainWindow::getInstance()->show();

    GameObject go("object");
    go.AddComponent(new MeshRenderer(go.name, "robot.mesh", "Robot"));

    GameObject go2("object2");
    go2.AddComponent(new MeshRenderer(go2.name, "razor.mesh", "Razor"));

    GameObject go3("object3");
    go3.AddComponent(new MeshRenderer(go3.name, "penguin.mesh", "Penguin"));

    return app.exec();
}
