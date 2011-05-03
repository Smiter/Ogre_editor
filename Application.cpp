#include "QtWidget.h"
#include "mainwidget.h"

#include <QBoxLayout>
#include <QPushButton>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);


    MainWidget *window = new MainWidget;
    OgreWidget * test = new OgreWidget();

    QBoxLayout *layout = new QBoxLayout(QBoxLayout::LeftToRight);
    layout->addWidget(test);
    test->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    layout->setMargin(20);
    layout->setAlignment(test,Qt::AlignTop | Qt::AlignLeft);
    window->setLayout(layout);

    window->show();
    test->show();

    window->resize(1024,768);
    test->resize(500,500);
    test->move(20,20);


    return app.exec();
}
