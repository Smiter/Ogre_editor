#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :  QMainWindow(parent),  ui(new Ui::MainWindow)/*, ogreWindow(new OgreWidget(this))*/
{

    ui->setupUi(this);
    ogreWindow = new OgreWidget();
    ui->dockOgre->setWidget(ogreWindow);
    this->setCentralWidget(ui->dockOgre);

    initProjectExplorer();
}

MainWindow::~MainWindow()
{
    delete fileSystemModel;
    delete ui;
}

void MainWindow::initProjectExplorer()
{
    // Project Explorer Tree Initialization
    fileSystemModel = new QFileSystemModel;
    fileSystemModel->setRootPath(QDir::currentPath());

    QStringList fileFilters;
    fileFilters.append("*.png");
    fileFilters.append("*.jpg");
    fileFilters.append("*.mesh");
    fileFilters.append("*.material");
    fileSystemModel->setNameFilters(fileFilters);
    fileSystemModel->setNameFilterDisables(false);

    ui->prExplorerTree->setModel(fileSystemModel);

    ui->prExplorerTree->setColumnHidden(1,true);
    ui->prExplorerTree->setColumnHidden(2,true);
    ui->prExplorerTree->setColumnHidden(3,true);

    ui->prExplorerTree->setAnimated(false);
    ui->prExplorerTree->setIndentation(20);
    ui->prExplorerTree->setSortingEnabled(true);

    ui->prExplorerTree->setWindowTitle(QObject::tr("Dir View"));
    ui->prExplorerTree->setRootIndex(fileSystemModel->index(QDir::currentPath()));

    ui->prExplorerTree->show();
}
