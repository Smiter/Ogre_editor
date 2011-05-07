#include "QtWidget.h"
#include "mainwindow.h"
#include "QtWidget.h"
#include <QBoxLayout>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MainWindow::getInstance()->show();

    return app.exec();
}
