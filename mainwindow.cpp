#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow)/*, ogreWindow(new OgreWidget(this))*/
{
    ui->setupUi(this);
    ogreWindow = new OgreWidget();
    this->setCentralWidget(ui->tabWidget);
    ui->tabWidget->insertTab(0,ogreWindow,"Scene");
    ui->tabWidget->removeTab(1);
    ui->tabWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}
