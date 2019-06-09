#include "mainWindow.h"
#include "ui_mainWindow.h"
#include <QDebug>
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow),
        mListToDos()
{

    ui->setupUi(this);

    connect(ui->addListToDoButton, &QPushButton::clicked,
            this, &MainWindow::addListToDo);


    updateStatus();

}

MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::addListToDo()
{
    bool ok;


    QString name = QInputDialog::getText(this,
                                         tr("Add listToDo"),
                                         tr("ListToDo name"),
                                         QLineEdit::Normal,
                                         tr("Untitled listToDo"), &ok);
    if (ok && !name.isEmpty()) {
        qDebug() << "Adding new listToDo";
        ListToDo *listToDo = new ListToDo(name);
        connect(listToDo, &ListToDo::removed, this, &MainWindow::removeListToDo);
        connect(listToDo, &ListToDo::statusChanged, this, &MainWindow::listToDoStatusChanged);
        mListToDos.append(listToDo);

        ui->listToDosLayout->addWidget(listToDo);
        updateStatus();
    }
}

void MainWindow::saveListToDo()
{



}



void MainWindow::removeListToDo(ListToDo *listToDo)
{
    mListToDos.removeOne(listToDo);
    ui->listToDosLayout->removeWidget(listToDo);

    listToDo->setParent(0);
    delete listToDo;
    updateStatus();
}

void MainWindow::listToDoStatusChanged(ListToDo *listToDo)
{
    updateStatus();
}

void MainWindow::updateStatus()
{
    int completedCount = 0;

    for (auto t : mListToDos) {
        if (t->isCompleted()) {
            completedCount++;
        }
    }
    int todoCount = mListToDos.size() - completedCount;

    ui->statusLabel->setText(
            QString("Status: %1 Checklist ")
                    .arg(todoCount)
                    .arg(completedCount));
}
