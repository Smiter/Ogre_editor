#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget),
    ogreWindow(new OgreWidget)

{
    ui->setupUi(this);

}

MainWidget::~MainWidget()
{
    delete ui;
}
