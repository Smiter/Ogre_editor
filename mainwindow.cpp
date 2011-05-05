#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow)/*, ogreWindow(new OgreWidget(this))*/
{
    ui->setupUi(this);
    ogreWindow = new OgreWidget();
    ui->dockOgre->setWidget(ogreWindow);
    this->setCentralWidget(ui->dockOgre);
}

MainWindow::~MainWindow()
{
    delete ui;
}
