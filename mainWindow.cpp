#include "mainWindow.h"
#include "ui_mainWindow.h"
#include <QDebug>
#include <QInputDialog>
#include <QtWidgets/QFileDialog>
#include <QTextStream>
#include <QtWidgets/QMessageBox>


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

void MainWindow::on_Save_clicked()
{
    QString nomeFile = QFileDialog::getSaveFileName(this,
                                                    tr("File di Testo (*.txt);;C++ File (*.cpp *.h)"));
    if (nomeFile != "") {
        QFile file(nomeFile);

        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
                  //  stream << ui->toPlainText();
            file.flush();
            file.close();
        }
        else {
            QMessageBox::critical(this, tr("Errore"), tr("Non posso salvare il file"));
            return;
        }
    }
};
void MainWindow::on_OpenFile_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Text Files ('''.txt);;C++ Files ('''.cpp '''.h)"));

    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"),
                                  tr("Could not open file"));
            return;
        }
        QString contents = file.readAll().constData();
        //textEdit->setPlainText(contents);
        file.close();
    }



}