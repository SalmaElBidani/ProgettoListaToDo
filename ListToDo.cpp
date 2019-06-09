#include "ListToDo.h"
#include "ui_ListToDo.h"
#include <QInputDialog>
#include <QFont>
#include <Board.h>
#include <QApplication>


ListToDo::ListToDo(const QString &name, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::ListToDo)
{
    ui->setupUi(this);
    setName(name);
    connect(ui->editButton, &QPushButton::clicked,
            this, &ListToDo::rename);


    connect(ui->removeButton, &QPushButton::clicked,
            [this] {
                emit removed(this);
            });

    connect(ui->checkbox, &QPushButton::toggled, this, &ListToDo::checked);
}

ListToDo::~ListToDo()
{
    delete ui;
}


void ListToDo::setName(const QString &name)
{
    ui->checkbox->setText(name);
}

QString ListToDo::name() const
{
    return ui->checkbox->text();
}

bool ListToDo::isCompleted() const
{
    return ui->checkbox->isChecked();
}

void ListToDo::rename()
{
    bool ok;
    QString value = QInputDialog::getText(this, tr("Edit listToDo"),
                                          tr("ListToDo name"),
                                          QLineEdit::Normal,
                                          this->name(), &ok);
    if (ok && !value.isEmpty()) {
        setName(value);
    }
}

void ListToDo::checked(bool checked)
{

    QFont font(ui->checkbox->font());

    font.setStrikeOut(checked);

    ui->checkbox->setFont(font);

    emit statusChanged(this);
}

void ListToDo::on_checkbox_clicked()
{
 Board Board;
    Board.setModal(true);
    Board.exec();
}
