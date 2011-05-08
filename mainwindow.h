#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeWidgetItem>

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

    void UpdateComponents(Ogre::SceneNode*, Ogre::Entity *);
    void createMesh(Ogre::Vector3, Ogre::String, Ogre::String);
    void UpdateSceneNodesList(QString);

    static int objectsCount;

public slots:
    // SLOTS
    //
    // On item clicked in hierarchy list
    void OnSceneNodeClicked();


private:

    void initSceneNodesList();
    void initProjectExplorer();


};

#endif // MAINWINDOW_H
