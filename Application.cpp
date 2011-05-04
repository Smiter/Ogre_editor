#include "QtWidget.h"
#include "mainwidget.h"

#include <QBoxLayout>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);


    MainWidget *window = new MainWidget;

    QBoxLayout *layout = new QBoxLayout(QBoxLayout::LeftToRight);
    layout->addWidget(window->ogreWindow);
    window->ogreWindow->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    layout->setMargin(20);
    layout->setAlignment(window->ogreWindow,Qt::AlignTop | Qt::AlignLeft);
    window->setLayout(layout);

    window->show();

    window->resize(640,480);

    return app.exec();
}
