#include <QObject>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QListWidget>
#include <QMainWindow>
#include <QMenuBar>





int
main(int argc, char** argv)
{




    QApplication app(argc, argv);

    QMainWindow window(0, Qt::Window);
    window.setWindowTitle("To do List");
    window.resize(400,500);


    QVBoxLayout mainLayout;


    QWidget* centralWidget = new QWidget(&window);
    centralWidget->setLayout(&mainLayout);



    window.setCentralWidget(centralWidget);


    QMenuBar* menuBar = window.menuBar();
    QMenu* CheckMenu = menuBar->addMenu("Checklist"); // Qbutton to add new checklist
    QMenu* ToDoMenu = menuBar->addMenu("Task"); //Qbutton to add new task

     ToDoMenu->addAction("Add ToDo", centralWidget,
                          SLOT(addPressed()),
                          QKeySequence("Ctrl+A"));
      ToDoMenu->addAction("Delete ToDo", centralWidget,
                          SLOT(delPressed()));   //add or delete task

    CheckMenu->addAction("Add Checklist", centralWidget,
                        SLOT(addPressed()),
                        QKeySequence("Ctrl+B"));
    CheckMenu->addAction("Delete Checklist", centralWidget,
                        SLOT(delPressed())); //add or delete checklist



    window.show();


    return(app.exec());
}


