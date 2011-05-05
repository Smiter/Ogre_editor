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

    initProjectExplorer();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initProjectExplorer()
{
    fileSystemModel = new QFileSystemModel();
    fileSystemModel->setRootPath(QDir::currentPath());

    QStringList filters;
    filters.append("*.jpg");
    filters.append("*.png");
    filters.append("*.mesh");
    filters.append("*.material");
    fileSystemModel->setNameFilters(filters);
    fileSystemModel->setNameFilterDisables(false);

    ui->prExplorerTree->setModel(fileSystemModel);
    ui->prExplorerTree->setColumnHidden(1, true);
    ui->prExplorerTree->setColumnHidden(2, true);
    ui->prExplorerTree->setColumnHidden(3, true);

    ui->prExplorerTree->setRootIndex(fileSystemModel->index(QDir::currentPath()));

    ui->prExplorerTree->show();

}
