#include <QtWidgets/QInputDialog>
#include "Board.h"
#include "ui_Board.h"
#include <mainWindow.h>
#include <task.h>
#include <QDebug>
#include <QScrollArea>

Board::Board(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Board),
    mTask()
{
    ui->setupUi(this);
    updateStatus();
}

Board::~Board()
{
    delete ui;
}

void Board::on_Board_accepted()
{

}
void Board::on_addTaskButton_clicked()
{

    bool ok;


    QString name = QInputDialog::getText(this,
                                         tr("Add task"),
                                         tr("Task name"),
                                         QLineEdit::Normal,
                                         tr("Untitled task"), &ok);

    if (ok && !name.isEmpty()) {
        qDebug() << "Adding new task";
        Task *task = new Task(name);
        connect(task, &Task::removed, this, &Board::removeTask);
        connect(task, &Task::statusChanged, this, &Board::taskstatusChanged);
        mTask.append(task);

        ui->TaskLayout->addWidget(task);
        updateStatus();
    }


}

void Board::saveTask()
{



}



void Board::removeTask(Task*task)
{
    mTask.removeOne(task);
    ui->TaskLayout->removeWidget(task);

    task->setParent(0);
    delete task;
    updateStatus();
}

void Board::taskstatusChanged(Task *task)
{
    updateStatus();
}




void Board::updateStatus()
{
    int completedCount = 0;

    for (auto t : mTask) {
        if (t->isCompleted()) {
            completedCount++;
        }
    }
    int todoCount = mTask.size() - completedCount;

    ui->statusLabel->setText(
            QString("Status: %1 todo / %2 completed")
                    .arg(todoCount)
                    .arg(completedCount));
}
