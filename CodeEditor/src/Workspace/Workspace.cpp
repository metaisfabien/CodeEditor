#include "Workspace.h"
#include "Perspective.h"
#include "MainWindow.h"
#include "Workspace/DockData.h"
#include "Workspace/PerspectiveDock.h"
#include "Dock/DockManager.h"
#include "Dock/Dock.h"
#include "CodeEditor.h"

#include <QDir>
#include <QApplication>
#include <QJsonDocument>
#include <QString>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

namespace CE {
Workspace::Workspace(MainWindow *mainWindow, DockManager *dockManager)
{
    mMainWindow = mainWindow;
    mDockManager = dockManager;
    mCurrentPerspective = 0;

    load();

    restoreWindowSize();
    addDocks();

    connect(mMainWindow, SIGNAL(closeWindow()), this, SLOT(save()));
    connect(mMainWindow, SIGNAL(stateChange()), this, SLOT(updateWindowState()));
    connect(mMainWindow, SIGNAL(windowResize(QSize)), this, SLOT(updateWindowSize(QSize)));
}

Workspace::~Workspace()
{
    vector<Perspective*>::const_iterator perspectiveIterator;
    for(perspectiveIterator = mPerspectives.begin(); perspectiveIterator != mPerspectives.end(); ++perspectiveIterator) {
        delete (*perspectiveIterator);
    }
}

void Workspace::restoreWindowSize()
{
    qDebug() << "Restore window size";

    Perspective *perspective = getCurrentPerspective();

    qDebug() << "Restore window size2";
    mMainWindow->resize(perspective->getWindowSize());
    qDebug() << "Restore window size4";
    if (perspective->getWindowState() == Qt::WindowMaximized) {
        mMainWindow->showMaximized();
    }
    qDebug() << "Restore window size3";
}

void Workspace::addDocks()
{
    qDebug() << "add docks";

    Perspective *perspective = getCurrentPerspective();
    QHashIterator<QString, PerspectiveDock*> dockIterator(perspective->getPerspectiveDocks());
    while (dockIterator.hasNext()) {
        dockIterator.next();
        PerspectiveDock *perspectiveDock = dockIterator.value();
        qDebug() << "add dock " + perspectiveDock->getId() + " to perspective " + perspective->getName();
        perspectiveDock->getDock()->loadWidget();
        mMainWindow->addDockWidget(perspectiveDock->getArea(), perspectiveDock->getDock());
    }
}

/**
 * @brief Workspace::load
 *
 * Load the workspace from his json config file
 */
void Workspace::load()
{
    qDebug() << "Load workspace";

    QDir dataDir = QDir(QApplication::applicationDirPath() + "/data");
    if (dataDir.exists()){
        QFile projectsFile(dataDir.absoluteFilePath("workspace.json"));
        if (projectsFile.exists()) {
            projectsFile.open(QIODevice::ReadOnly | QIODevice::Text);
            QString projectsJson = projectsFile.readAll();
            QJsonDocument jsonDocument = QJsonDocument::fromJson(projectsJson.toUtf8());
            QJsonObject workspaceConfig = jsonDocument.object();
            if (workspaceConfig["perspectives"].toArray().count()) {
                loadPerspectives(workspaceConfig["perspectives"].toArray());
            } else {
                qDebug() << "Load workspace perspectives from workspace.json fail";
                // Throw new Exception ("No perspective in config file")
            }
        } else {
             qDebug() << "workspace.json not exist, load workspace fail";
        }
    } else {
        qDebug() << "data directory not exist, load workspace fail";
    }
}

void Workspace::loadPerspectives(QJsonArray perspectivesArray)
{
    qDebug() << "Load Perspectives";
    for(int i = 0; i < perspectivesArray.count(); i++) {
        QJsonObject perspectiveObject = perspectivesArray[i].toObject();
        Perspective *perspective = new Perspective(perspectiveObject["name"].toString(), perspectiveObject["icone"].toString());

        addDocksToPerpective(perspectiveObject, perspective);

        if (perspectiveObject.contains("window_size")) {
            perspective->setWindowSize(perspectiveObject["window_size"].toString());
        }

        if (perspectiveObject.contains("window_state")) {
            if (perspectiveObject["window_state"].toString().toInt() == Qt::WindowMaximized) {
                perspective->setWindowState(Qt::WindowMaximized);
            } else {
               perspective->setWindowState(Qt::WindowNoState);
            }
        }

        if (!mCurrentPerspective || (perspectiveObject.contains("current") && perspectiveObject["current"].toBool())) {
            mCurrentPerspective = perspective;
        }

        mPerspectives.push_back(perspective);
    }
}

void Workspace::addDocksToPerpective(QJsonObject perspectiveObject, Perspective* perspective)
{
    QJsonArray docksArray = perspectiveObject["docks"].toArray();
    if (docksArray.count()) {
         for(int i = 0; i < docksArray.count(); i++) {
            QJsonObject dockObject = docksArray[i].toObject();

            QString dockId = dockObject["id"].toString();
            Dock* dock = CodeEditor::getDockManager()->getDock(dockId);
            if (dock) {
                PerspectiveDock *perspectiveDock = new PerspectiveDock(dockId);
                if (dockObject.contains("area")) {
                    int area = dockObject["area"].toString().toInt();
                    Qt::DockWidgetArea dockArea;
                    if (area == Qt::RightDockWidgetArea) {
                        dockArea = Qt::RightDockWidgetArea;
                    } else if (area == Qt::LeftDockWidgetArea) {
                        dockArea = Qt::LeftDockWidgetArea;
                    } else if (area == Qt::TopDockWidgetArea) {
                        dockArea = Qt::TopDockWidgetArea;
                    } else if (area == Qt::BottomDockWidgetArea) {
                        dockArea = Qt::BottomDockWidgetArea;
                    }

                    perspectiveDock->setArea(dockArea);
                }
                perspectiveDock->setDock(dock);
                perspective->addPerspectiveDock(perspectiveDock);
            }
         }

     }
}

Perspective* Workspace::getCurrentPerspective()
{
    return mCurrentPerspective;
}

/**
 * @brief Workspace::save
 *
 * Save the workspace in his json config file
 */
void Workspace::save()
{
    qDebug() << "save workspace";

    QJsonDocument jsonDocument;
    QJsonObject object;
    QJsonArray perspectives;

    vector<Perspective*>::const_iterator perspectiveIterator;
    for(perspectiveIterator = mPerspectives.begin(); perspectiveIterator != mPerspectives.end(); ++perspectiveIterator) {
        QJsonObject * perspectiveObject = new QJsonObject;
        Perspective *perspective = (*perspectiveIterator);

        perspectiveObject->insert("name", perspective->getName());
        perspectiveObject->insert("current", perspective->isCurrent());
        perspectiveObject->insert("window_state", perspective->getWindowState());
        QSize windowSize = perspective->getWindowSize();
        perspectiveObject->insert("window_size", QString::number(windowSize.width()) + "x" + QString::number(windowSize.height()));

        addDocksToPerpectiveObject(perspectiveObject, perspective);

        perspectives.push_back(*perspectiveObject);
    }

    object["perspectives"] = perspectives;

    jsonDocument.setObject(object);

    //save the file
    QDir dataDir = QDir(QApplication::applicationDirPath() + "/data");
    if (!dataDir.exists()){
        dataDir.mkdir(".");
    }
    QFile workspaceFile(dataDir.absoluteFilePath("workspace.json"));
    workspaceFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);

    workspaceFile.write(jsonDocument.toJson());
    workspaceFile.close();
}

/**
 * @brief Workspace::addDocksToPerpectiveObject
 *
 * Add the dock array to the perspective json object
 *
 * @param perspectiveObject
 * @param perspective
 */
void Workspace::addDocksToPerpectiveObject(QJsonObject *perspectiveObject, Perspective *perspective)
{
    QJsonArray docksArray;

    QHashIterator<QString, PerspectiveDock*> dockIterator(perspective->getPerspectiveDocks());
    while (dockIterator.hasNext()) {
        dockIterator.next();
        PerspectiveDock *perspectiveDock = dockIterator.value();
        QJsonObject dockObject;

        dockObject["id"] = perspectiveDock->getId();
        dockObject["area"] = perspectiveDock->getArea();

        docksArray.push_back(dockObject);
    }

    perspectiveObject->insert("docks", docksArray);
}

void Workspace::updateWindowState()
{
    if (mMainWindow->windowState() == Qt::WindowNoState) {
        getCurrentPerspective()->setWindowState(Qt::WindowNoState);
    } else if (mMainWindow->windowState() == Qt::WindowMaximized) {
       getCurrentPerspective()->setWindowState(Qt::WindowMaximized);
    }
}

void Workspace::updateWindowSize(QSize windowSize)
{
    getCurrentPerspective()->setWindowSize(windowSize.width(), windowSize.height());
}
}
