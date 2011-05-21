#include "projectexplorertree.h"

#include <QFileSystemModel>

ProjectExplorerTree::ProjectExplorerTree(QWidget *parent) :
    QTreeView(parent)
{

    // Widget init
    setObjectName(QString::fromUtf8("prExplorerTree"));
    setMinimumSize(QSize(0, 0));
    setMaximumSize(QSize(65656, 76767));
    setSizeIncrement(QSize(0, 0));
    setDragEnabled(true);
    setDragDropMode(QAbstractItemView::DragOnly);
    setAnimated(true);

    // Tree init
    QFileSystemModel *fileSystemModel = new QFileSystemModel();
    fileSystemModel->setRootPath(QDir::currentPath());

    QStringList filters;
    filters.append("*.jpg");
    filters.append("*.png");
    filters.append("*.mesh");
    filters.append("*.material");
    fileSystemModel->setNameFilters(filters);
    fileSystemModel->setNameFilterDisables(false);

    setModel(fileSystemModel);
    setColumnHidden(1, true);
    setColumnHidden(2, true);
    setColumnHidden(3, true);

    setRootIndex(fileSystemModel->index(QDir::currentPath()));
    show();

}

void ProjectExplorerTree::startDrag(Qt::DropActions supportedActions)
{
        QMimeData *data = new QMimeData;
        QDrag *drag = new QDrag(this);

        data->setText(static_cast<QFileSystemModel*>(model())->fileName(currentIndex()));
        drag->setMimeData(data);

        drag->start(supportedActions);
}
