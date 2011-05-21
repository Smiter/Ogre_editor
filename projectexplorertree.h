#ifndef PROJECTEXPLORERTREE_H
#define PROJECTEXPLORERTREE_H

#include <QTreeView>

class ProjectExplorerTree : public QTreeView
{
    Q_OBJECT
public:
    explicit ProjectExplorerTree(QWidget *parent = 0);
    void startDrag(Qt::DropActions supportedActions);

signals:

public slots:
//    void OnMouseDown();
};

#endif // PROJECTEXPLORERTREE_H
