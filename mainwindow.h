#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QTreeWidgetItem>

#include "QtWidget.h"
#include "projectexplorertree.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    // CTOR and DTOR
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // Main Frame Parts
    //
    // The FORMS object
    Ui::MainWindow *ui;
    // The Ogre window
    OgreWidget *ogreWindow;
    ProjectExplorerTree  *prExplorerTree;

    // Components GUI functions
    //
    // Updating SceneNode and Entity components
    void UpdateComponents(Ogre::SceneNode*, Ogre::Entity *);

    // Update the Image View in material viwer
    void UpdateMaterialView(Ogre::Entity *);

    // SceneNodesList functions
    //
    // Update is called while objects Raycasting on scene
    void UpdateSceneNodesList(QString);
    // Add is called when a new object is created. It pulls it into list
    void AddItemToSceneList(Ogre::String);


    // Other functions
    //
    // Singleton getInstance implementation
    static MainWindow * getInstance()
    {
        if (instance == 0)
            instance = new MainWindow;
        return instance;
    }
    static MainWindow * instance;




public slots:
    // SLOTS
    //
    // Is called when user clicked on an item in SceneNodesList
    void OnSceneNodeClicked();
    void ProcessToolBar();

    // When object's position is changed via ComponentsGUI
    void OnPositionChanged(const QString &);
    // When object's material is picking
    void OnMaterialButtonDown();
    // When object's mesh is picking
    void OnMeshButtonDown();

private:
    // Initialization Form's components
    //
    // File system tree's initialization
    void initProjectExplorer();


};

#endif // MAINWINDOW_H
