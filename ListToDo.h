#ifndef ListToDo_H
#define ListToDo_H

#include <QWidget>

namespace Ui {
    class ListToDo;
}

class ListToDo : public QWidget
{
Q_OBJECT

public:
    explicit ListToDo(const QString &name, QWidget *parent=0);
    ~ListToDo();

    void setName(const QString &name);
    QString name() const;
    bool isCompleted() const;

public slots:
    void rename();

signals:
    void removed(ListToDo *listToDo);
    void statusChanged(ListToDo *listToDo);
private slots:
    void checked(bool checked);
    void on_checkbox_clicked();
private:
    Ui::ListToDo *ui;
};

#endif // TASK_H
