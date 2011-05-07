#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>

#include "QtWidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    OgreWidget *ogreWindow;

    static MainWindow * instance;
    static MainWindow * getInstance()
    {
        if (instance == 0)
            instance = new MainWindow;
        return instance;
    }
    void updateTransform(Ogre::SceneNode*, Ogre::Entity *);

private:

    void initProjectExplorer();


};

#endif // MAINWINDOW_H
