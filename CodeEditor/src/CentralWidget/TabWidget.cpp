#include "CentralWidget/TabWidget.h"
#include "CentralWidget/TabBar.h"
#include "CentralWidget/Overlay.h"
#include "CentralWidget/Splitter.h"


#include "CodeEditor.h"
#include "TabWidgetManager.h"
#include "Editor/EditorWidget.h"
#include "Editor/EditorManager.h"

#include <QDrag>
#include <QDropEvent>
#include <QMimeData>
#include <QBuffer>
#include <QPainter>
#include <QDebug>
#include <QRect>

namespace CE {
CentralWidgetTabWidget::CentralWidgetTabWidget(CentralWidgetSplitter* parent)
   : QTabWidget(parent)
{

    mDropAreaOverlay = 0;
    mParentSplitter = parent;

    CentralWidgetTabBar* tabBar = new CentralWidgetTabBar(this);
    connect(tabBar, SIGNAL(tabMoveRequested(int, int)), this, SLOT(moveTab(int, int)));
    connect(tabBar, SIGNAL(startDrag(QDrag*)), this, SLOT(startDragTab(QDrag*)));
    connect(tabBar, SIGNAL(currentChanged(int)), this, SLOT(currentTabChanged(int)));

    setAcceptDrops(true);
    setTabBar(tabBar);
}

CentralWidgetTabWidget::~CentralWidgetTabWidget()
{
    if (mDropAreaOverlay) {
        delete mDropAreaOverlay;
        mDropAreaOverlay = 0;
    }
}

/**
 * @brief CentralWidgetTabWidget::tabBar
 *
 * Return the CentralWidgetTabBar
 *
 * @return
 */
CentralWidgetTabBar *CentralWidgetTabWidget::tabBar()
{
    return qobject_cast<CentralWidgetTabBar *>(QTabWidget::tabBar());
}

/**
 * @brief CentralWidgetTabWidget::addEditorWidget
 *
 * Add an editor widget to the tab widget and set is parent
 *
 * @param editorWidget
 * @param label
 */
void CentralWidgetTabWidget::addEditorWidget(EditorWidget *editorWidget, QString label)
{
    editorWidget->setParentTabWidget(this);
    editorWidget->setTabText(label);
    addTab(editorWidget, label);
}

EditorWidget *CentralWidgetTabWidget::getEditorWidget(int tabIndex)
{
    EditorWidget *editorWidget = qobject_cast<EditorWidget *>(widget(tabIndex));
    return editorWidget;
}

/**
 * @brief CentralWidgetTabWidget::closeTab
 *
 * Close a tab
 *
 * @param index
 */
void CentralWidgetTabWidget::closeTab(const int& index)
{
    if (index == -1) {
        return;
    }

    EditorWidget* editorWidget = getEditorWidget(index);
    removeTab(index);

    delete(editorWidget);
    editorWidget = 0;
}

/**
 * @brief CentralWidgetTabWidget::getEditorWidgetIndex
 *
 * Return the index of an editor widget
 *
 * @param editorWidget
 * @return
 */
int CentralWidgetTabWidget::getEditorWidgetIndex(EditorWidget *editorWidget)
{
    int tabIndexFound = -1;
    for(int i = 0; i < count(); ++i) {
        if(editorWidget == getEditorWidget(i)) {
            tabIndexFound = i;
            break;
        }
    }

    return tabIndexFound;
}



/**
 * @brief CentralWidgetTabWidget::currentTabChanged
 * @param tabIndex
 */
void CentralWidgetTabWidget::currentTabChanged(int tabIndex)
{
    EditorWidget *editorWidget = qobject_cast<EditorWidget *>(widget(tabIndex));
    CodeEditor::getEditorManager()->setCurrentEditorWidget(editorWidget);
}


void CentralWidgetTabWidget::moveTab(int fromIndex, int toIndex)
{
    // Save the desired tab properties
    QWidget* w = widget(fromIndex);
    QIcon icon = tabIcon(fromIndex);
    QString text = tabText(fromIndex);

    // remove the tab and insert a new tab
    // with the stored properties
    removeTab(fromIndex);
    insertTab(toIndex, w, icon, text);
    setCurrentIndex(toIndex);
}

/**
 * @brief TabWidget::startDragTab
 *
 * Slot call when an tab of this tab widget start to drag
 *
 * it create a pixmap of the current tab widget set transparency on it
 * and show it
 *
 * @param drag
 */
void CentralWidgetTabWidget::startDragTab(QDrag* drag)
{
    QPixmap pixmap(currentWidget()->size());
    currentWidget()->render(&pixmap);
    pixmap = pixmap.scaled(200, 200, Qt::KeepAspectRatio);

    QPixmap transparent(pixmap.size());
    // Do transparency
    transparent.fill(Qt::transparent);
    QPainter p(&transparent);
    p.setCompositionMode(QPainter::CompositionMode_Source);
    p.drawPixmap(0, 0, pixmap);
    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    // Set transparency level to 150 (possible values are 0-255)
    // The alpha channel of a color specifies the transparency effect,
    // 0 represents a fully transparent color, while 255 represents
    // a fully opaque color.
    p.fillRect(transparent.rect(), QColor(0, 0, 0, 150));
    p.end();

    // Set original picture's reference to new transparent one
    pixmap = transparent;
    drag->setPixmap(pixmap);
}

void CentralWidgetTabWidget::dragEnterEvent(QDragEnterEvent* event)
{
    // Only accept if it's an tab-reordering request
    const QMimeData* m = event->mimeData();
    QStringList formats = m->formats();
    if (formats.contains("action") && (m->data("action") == "drag-tab")) {
        event->acceptProposedAction();
    }
}

void CentralWidgetTabWidget::dropEvent(QDropEvent* event)
{
    qDebug() << "TabWidget::dropEvent";
    const QMimeData* mimeData = event->mimeData();
    QStringList formats = mimeData->formats();
    if (formats.contains("action") && (mimeData->data("action") == "drag-tab")
        && formats.contains("from") && formats.contains("index")) {
        //remove the drop overlay
        if (mDropAreaOverlay) {
            delete mDropAreaOverlay;
            mDropAreaOverlay = 0;
        }

        //get the drop area
        DropArea dropArea = getDropArea(event->pos());

        int toTabWidgetIndex = CodeEditor::getTabWidgetManager()->indexOf(this);
        mParentSplitter->dropTab(dropArea, toTabWidgetIndex, mimeData->data("from").toInt(), mimeData->data("index").toInt());
        event->acceptProposedAction();
    }
}

DropArea CentralWidgetTabWidget::getDropArea(QPoint point)
{
    int height = geometry().height() * 25 / 100;//25% of the widget height
    int width = geometry().width() * 25 / 100;//25% of the widget width

    //calcul the drop area rectangle
    QRect leftArea = QRect(QPoint(0, 0), QSize(width, geometry().height()));
    QRect topArea = QRect(QPoint(width, 0), QSize(geometry().width() - (width * 2), height));
    QRect rightArea = QRect(QPoint(geometry().width() - width, 0), QSize(width, geometry().height()));
    QRect bottomArea = QRect(QPoint(width, geometry().height() - height), QSize(geometry().width() - (width * 2), height));

    //left area
    if (topArea.contains(point)) {
        return TopDropArea;
    //top area
    } else if (leftArea.contains(point)) {
        return LeftDropArea;
    //right area
    } else if (rightArea.contains(point)) {
        return RightDropArea;
    //bottom area
    } else if (bottomArea.contains(point)) {
        return BottomDropArea;
    //center area
    } else {
        return CenterDropArea;
    }
}

/**
 * @brief CentralWidgetTabWidget::dragMoveEvent
 *
 * Show the drop zone overlay
 *
 * @param event
 */
void CentralWidgetTabWidget::dragMoveEvent(QDragMoveEvent *event)
{
    DropArea dropArea = getDropArea(event->pos());

    int overlayHeight = geometry().height() * 50 / 100;//50% of the widget height
    int overlayWidth = geometry().width() * 50 / 100;//50% of the widget width

    QRect overlayDropArea;

    //left area
    if (dropArea == LeftDropArea) {
        overlayDropArea = QRect(QPoint(0, 0), QSize(overlayWidth, geometry().height()));

    //top area
    } else if (dropArea == TopDropArea) {
        overlayDropArea = QRect(QPoint(0, 0), QSize(geometry().width(), overlayHeight));

    //right area
    } else if (dropArea == RightDropArea) {
        overlayDropArea = QRect(QPoint(geometry().width() - overlayWidth, 0), QSize(overlayWidth, geometry().height()));

    //bottom area
    } else if (dropArea == BottomDropArea) {
        overlayDropArea = QRect(QPoint(0, geometry().height() - overlayHeight), QSize(geometry().width(), overlayHeight));

    //center area
    } else {
        overlayDropArea = QRect(QPoint(0, 0), QSize(geometry().width(), geometry().height()));
    }

    //create the overlay to highlight the drop zone
    if (!mDropAreaOverlay) {
        mDropAreaOverlay = new CentralWidgetDropOverlay();
        mDropAreaOverlay->setParent(this);
        mDropAreaOverlay->raise();
        mDropAreaOverlay->show();
    }

    mDropAreaOverlay->move(overlayDropArea.x(), overlayDropArea.y());
    mDropAreaOverlay->resize(overlayDropArea.width(), overlayDropArea.height());

    event->acceptProposedAction();
}

/**
 * @brief CentralWidgetTabWidget::dragLeaveEvent
 *
 * Remove the drop zone overlay
 */
void CentralWidgetTabWidget::dragLeaveEvent(QDragLeaveEvent *)
{
    if (mDropAreaOverlay) {
        delete mDropAreaOverlay;
        mDropAreaOverlay = 0;
    }
}


void CentralWidgetTabWidget::setParentSplitter(CentralWidgetSplitter *parent)
{
    mParentSplitter = parent;
    setParent(parent);
}
}
