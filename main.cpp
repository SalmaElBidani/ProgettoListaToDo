#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QListWidget>
#include <QMainWindow>
#include <QKeySequence>
#include <QMenuBar>
#include <QMenu>

#include <QVector>
#include <QString>
#include <QStringList>

#include <QFile>
#include <QTextStream>


#include <QDebug>

#include "Task.h"
#include "Checklist.h"


int
main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QMainWindow window(0, Qt::Window);
    window.setWindowTitle("To Do List");
    window.resize(400,500);


    QVBoxLayout mainLayout;


    QWidget* centralWidget = new QWidget(&window);
    centralWidget->setLayout(&mainLayout);

   Checklist* mainWidget = new Checklist(QString(), &window);

    window.setCentralWidget(centralWidget);


    QMenuBar* menuBar = window.menuBar();
    QMenu* ToDoMenu = menuBar->addMenu("Task");
    QMenu* CheMenu = menuBar->addMenu("Checklist");


    ToDoMenu->addAction("Add Task", mainWidget,
                        SLOT(addPressed()),
                        QKeySequence("Ctrl+A"));
    ToDoMenu->addAction("Delete Task", mainWidget,
                        SLOT());
    ToDoMenu->addAction("Modify Task", mainWidget,
                        SLOT());


    CheMenu->addAction("Add Checklist", mainWidget,
                       SLOT(addCatPressed()));
    CheMenu->addAction("Delete Checklist", mainWidget,
                       SLOT());
    CheMenu->addAction("Modify Task", mainWidget,
                       SLOT());

    mainLayout.addWidget(mainWidget->GetMainGroupBox());


    window.show();


    return(app.exec());
}



