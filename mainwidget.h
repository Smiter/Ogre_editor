#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QDockWidget>
#include "QtWidget.h"


namespace Ui {
    class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

public:
    Ui::MainWidget *ui;
    OgreWidget *ogreWindow;

};

#endif // MAINWIDGET_H
