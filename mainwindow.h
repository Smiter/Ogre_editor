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

    static MainWindow * instance;
        static MainWindow * getInstance()
        {
            if (instance == 0)
                instance = new MainWindow;
            return instance;
        }


    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    OgreWidget *ogreWindow;

    void updateTransform(Ogre::SceneNode*, Ogre::Entity *);
    void createRobot(Ogre::Vector3);
    static int objectsCount;


private:

    void initSceneNodesList();
    void initProjectExplorer();


};

#endif // MAINWINDOW_H
