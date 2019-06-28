#include "task.h"
#include "ui_task.h"
#include <QInputDialog>
#include <QFont>
#include <Board.h>
#include <stdio.h>
#include <QtWidgets/QLabel>
#include <QtWidgets/QColorDialog>
#include <QPixmap>
#include <QFont>
#include <QMouseEvent>


Task::Task(const QString &name, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Task)
{


    ui->setupUi(this);
    setName(name);
    connect(ui->editButton, &QPushButton::clicked,
            this, &Task::rename);


    connect(ui->removeButton, &QPushButton::clicked,
            [this] {
                emit removed(this);
            });

    connect(ui->checkbox, &QCheckBox::toggled, this, &Task::checked);


}

Task::~Task()
{
    delete ui;
}


void Task::setName(const QString &name)
{
    ui->checkbox->setText(name);
}

QString Task::name() const
{
    return ui->checkbox->text();
}

bool Task::isCompleted() const
{
    return ui->checkbox->isChecked();
}

void Task::rename()
{
    bool ok;
    QString value = QInputDialog::getText(this, tr("Edit task"),
                                          tr("Task name"),
                                          QLineEdit::Normal,
                                          this->name(), &ok);
    if (ok && !value.isEmpty()) {
        setName(value);
    }
}

void Task::checked(bool checked)
{
    QFont font(ui->checkbox->font());

    font.setStrikeOut(checked);

    ui->checkbox->setFont(font);

    emit statusChanged(this);
}


void Task::on_Important_clicked()
{
    QPixmap pix("/home/valeria/Scrivania/qt5-cpp-todo-master080619/qt5-cpp-todo-master/stella.png");
    ui->label_pic-> setPixmap(pix.scaled(15,15,Qt::KeepAspectRatio));

    QPalette palette = ui->checkbox->palette();
    palette.setColor(ui->checkbox->foregroundRole(), Qt::red);
    ui->checkbox->setPalette(palette);

    }

void Task::on_NotImportant_clicked()
{

    QPixmap pix("");
    ui->label_pic-> setPixmap(pix.scaled(15,15,Qt::KeepAspectRatio));
    QPalette palette = ui->checkbox->palette();
    palette.setColor(ui->checkbox->foregroundRole(), Qt::black);
    ui->checkbox->setPalette(palette);

}