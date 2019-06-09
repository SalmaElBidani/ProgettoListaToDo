#ifndef BOARD_H
#define BOARD_H

#include <QDialog>
#include <ListToDo.h>
#include <task.h>

namespace Ui {
    class Board;
}

class Board : public QDialog
{
Q_OBJECT

public:
    explicit Board(QWidget *parent = 0);


    ~Board();

private slots:
    void on_Board_accepted();
void on_addTaskButton_clicked();
void updateStatus();
void saveTask();
void removeTask(Task*task);
void taskstatusChanged(Task *task);



private:
    Ui::Board *ui;
    QVector<Task*> mTask;
};

#endif // BOARD_H
