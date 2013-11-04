#include "CentralWidget/Splitter.h"
#include "CentralWidget/Overlay.h"

#include "CodeEditor.h"
#include "TabWidgetManager.h"

#include <QPainter>
#include <QMimeData>
#include <QDebug>
#include <QDropEvent>

namespace CE {
CentralWidgetSplitter::CentralWidgetSplitter(SplitterType type, CentralWidgetSplitter *parent) : QSplitter(parent)
{
    if (type == VerticalSplitter) {
        setOrientation(Qt::Vertical);
    } else {
        setAcceptDrops(true);
        setOrientation(Qt::Horizontal);
    }
    if (parent) {
        mParentSplitter = parent;
    } else {
        mParentSplitter = 0;
    }
}


void CentralWidgetSplitter::dropEvent(QDropEvent* event)
{
 /*   const QMimeData* m = event->mimeData();
    QStringList formats = m->formats();
    if (formats.contains("action") && (m->data("action") == "drag-tab")) {
        qDebug() << "TabBar::dropEvent" + m->data("action");
        if (formats.contains("from")) {
            qDebug() << "From " + m->data("from");
            if (m->data("from") == mParent->getId()) {
                qDebug() << "same tabBar";
            } else {

                qDebug() << "other tabBar";
            }
        }
    }
    int fromIndex = tabAt(mDragStartPos);
    int toIndex   = tabAt(event->pos());

    // Tell interested objects that
    if (fromIndex != toIndex)
       emit tabMoveRequested(fromIndex, toIndex);
*/
    event->acceptProposedAction();
}


void CentralWidgetSplitter::dragEnterEvent(QDragEnterEvent* event)
{
    // Only accept if it's an tab-reordering request
    const QMimeData* m = event->mimeData();
    QStringList formats = m->formats();
    if (formats.contains("action") && (m->data("action") == "drag-tab")) {
        event->acceptProposedAction();
    }
}


void CentralWidgetSplitter::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->pos().x() == 0 || event->pos().x() == geometry().width()) {
        int width = geometry().width() / 2;
        int height = geometry().height();

        int x = 0;
        int y = 0;
        if (event->pos().x() == geometry().width()) {
            x = geometry().width() / 2;
        }
        //create the overlay to highlight the drop zone
        if (!mDropAreaOverlay) {
            mDropAreaOverlay = new CentralWidgetDropOverlay();
            mDropAreaOverlay->setParent(this);
            mDropAreaOverlay->raise();
            mDropAreaOverlay->show();
        }

        mDropAreaOverlay->move(x, x);
        mDropAreaOverlay->resize(width, height);

        event->acceptProposedAction();
    }
}

void CentralWidgetSplitter::dropTab(DropArea dropArea, int toTabWidgetIndex, int fromTabWidgetIndex, int tabIndex)
{
    //get from and to tabWidget to drop
    CentralWidgetTabWidget *toTabWidget = CodeEditor::getTabWidgetManager()->getTabWidget(toTabWidgetIndex);
    CentralWidgetTabWidget *fromTabWidget = CodeEditor::getTabWidgetManager()->getTabWidget(fromTabWidgetIndex);

    //get the index of the "to" tabwidget in the splitter
    int toTabWidgetSpliterIndex = indexOf(toTabWidget);

    //drop in the center area: no split
    if (dropArea == CenterDropArea) {
        if (toTabWidgetIndex != fromTabWidgetIndex) {
            toTabWidget->addTab(fromTabWidget->widget(tabIndex), fromTabWidget->tabText(tabIndex));
        }
    } else {
        //create a new tab widget
        CentralWidgetTabWidget *droppedTabWidget = CodeEditor::getTabWidgetManager()->createTabWidget(this);
        droppedTabWidget->addTab(fromTabWidget->widget(tabIndex), fromTabWidget->tabText(tabIndex));

        //Drop in top area or bottom area
        if (dropArea == TopDropArea || dropArea == BottomDropArea) {
            if (orientation() == Qt::Vertical && dropArea == TopDropArea) {
                //insert the new tab widget in the splitter
                insertWidget(toTabWidgetSpliterIndex, droppedTabWidget);
                resizeSplitter(toTabWidgetSpliterIndex);
            } else if (orientation() == Qt::Vertical && dropArea == BottomDropArea) {
                //insert the new tab widget in the splitter
                insertWidget(toTabWidgetSpliterIndex + 1, droppedTabWidget);
                resizeSplitter(toTabWidgetSpliterIndex);
            } else {
                //if the parent splitter of the "to" tabWiget is not vertical, it's necessary to create a vertical splitter
                createChildSplitter(VerticalSplitter, droppedTabWidget, toTabWidget, dropArea, toTabWidgetSpliterIndex);
            }
        //Drop in left or right area
        } else if (dropArea == LeftDropArea || dropArea == RightDropArea) {
            if (orientation() == Qt::Horizontal && dropArea == LeftDropArea) {
                insertWidget(toTabWidgetSpliterIndex, droppedTabWidget);
                resizeSplitter(toTabWidgetSpliterIndex);
            } else if (orientation() == Qt::Horizontal && dropArea == RightDropArea) {
                insertWidget(toTabWidgetSpliterIndex + 1, droppedTabWidget);
                resizeSplitter(toTabWidgetSpliterIndex);
            } else {
                    //if the parent splitter of the "to" tabWiget is not horizontal, it's necessary to create an horizontal splitter
                createChildSplitter(HorrizontalSplitter, droppedTabWidget, toTabWidget, dropArea, toTabWidgetSpliterIndex);
            }
        }
    }

    clean(fromTabWidget);
}

void CentralWidgetSplitter::createChildSplitter(SplitterType type, CentralWidgetTabWidget *droppedTabWidget, CentralWidgetTabWidget *toTabWidget,
                                                DropArea dropArea, int toTabWidgetSpliterIndex)
{
    QList<int> sizesList = sizes();
    int size = sizesList[toTabWidgetSpliterIndex] / 2;

    CentralWidgetSplitter *splitter = new CentralWidgetSplitter(type, this);

    droppedTabWidget->setParentSplitter(splitter);
    toTabWidget->setParentSplitter(splitter);

    if (dropArea == LeftDropArea || dropArea == TopDropArea) {
        splitter->insertWidget(0, toTabWidget);
        splitter->insertWidget(0, droppedTabWidget);
    } else {
        splitter->insertWidget(0, droppedTabWidget);
        splitter->insertWidget(0, toTabWidget);
    }

    insertWidget(toTabWidgetSpliterIndex, splitter);

    QList<int> childSizesList = splitter->sizes();

    childSizesList[0] = size;
    childSizesList[1] = size;
    splitter->setSizes(childSizesList);
    setSizes(sizesList);
}


void CentralWidgetSplitter::resizeSplitter(int toTabWidgetSpliterIndex)
{
    QList<int> sizesList = sizes();

    int size = sizesList[toTabWidgetSpliterIndex] / 2;
    sizesList[toTabWidgetSpliterIndex] = size;
    sizesList[toTabWidgetSpliterIndex + 1] = size;
    setSizes(sizesList);
}

/**
 * @brief CentralWidgetSplitter::clean
 *
 * remove empty tabwidget and splitter with only one child widget
 *
 * @param fromTabWidget
 */
void CentralWidgetSplitter::clean(CentralWidgetTabWidget *fromTabWidget)
{
    CentralWidgetSplitter *parentSplitter = fromTabWidget->getParentSplitter();
    int fromTabWidgetIndex = CodeEditor::getTabWidgetManager()->indexOf(fromTabWidget);

    //remove the "from" tabWidget if there is empty
    if (fromTabWidget->count() == 0) {
        CodeEditor::getTabWidgetManager()->removeTab(fromTabWidgetIndex);
        qDebug() << "remove tabwidget later";
        fromTabWidget->deleteLater();
        fromTabWidget->hide();
    }



    //while the parent have a parent and it a CentralWidgetSplitter
    while (parentSplitter->getParentSplitter()) {
        CentralWidgetSplitter *parentToDelete = parentSplitter;
        parentSplitter = qobject_cast<CentralWidgetSplitter *>(parentSplitter->getParentSplitter());

        //calcul the number of visible children
        int numChild = 0;
        int i = 0;
        while (parentToDelete->widget(i)) {
            if (parentToDelete->widget(i)->isVisible()) {
                ++numChild;
            }
            ++i;
        }

        qDebug() << "num child " << numChild;

        if (numChild <=  1) {
            //move the widget to the parent splitter
            if (numChild == 1) {

                QList<int> sizesList = parentSplitter->sizes();


                CentralWidgetTabWidget *tabWidget = qobject_cast<CentralWidgetTabWidget *>(parentToDelete->widget(0));
                tabWidget->setParentSplitter(parentSplitter);
                int splitterIndex = parentSplitter->indexOf(parentToDelete);
                parentSplitter->insertWidget(splitterIndex, tabWidget);

                parentSplitter->setSizes(sizesList);

                qDebug() << "Move widget to parent splitter";
            }
            qDebug() << "remove a splitter later";
            parentToDelete->deleteLater();
        }
    }


}
}
