#if !defined(TODOWIDGET_H)

#define TODOWIDGET_H
#include <QGroupBox>
#include <QVBoxLayout>
#include <QListWidget>
#include <QVector>
#include <QString>
#include <QMenuBar>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QComboBox>

#include <QFileDialog>
#include <QDebug>


#include <QFile>


//NOTE(hugo): A ToDo list is just a
//           vector<pair<string, vector<string> > >
struct ToDoCategory
{
    QString name;
    //NOTE(hugo): Can maybe be optimized with an array rather than a vector
    QVector<QString> items;
};

struct ToDoCategoryWidget
{
    QGroupBox* GroupBox;
    QVBoxLayout* Layout;
    QListWidget* Items;
};

class Checklist : public QWidget
{
Q_OBJECT

public:
    Checklist(QString filename, QWidget* window);
    ~Checklist();
    QVector<ToDoCategory*> GetCategories() const {return m_categories;}
    QGroupBox *GetMainGroupBox() const {return m_mainGroupBox;}

public slots:

    void addPressed();

    void addToDoItem();

    void addCatPressed();

    void addCategory();


private:
    QString m_filename;
    QVector<ToDoCategory*> m_categories;
    QVector<ToDoCategoryWidget*> m_QCategories;
    QGroupBox* m_mainGroupBox;
    QHBoxLayout *m_mainGroupBoxLayout;
    QWidget* actionWindow;
    QLineEdit* catNameLineEdit;
    QLineEdit* toDoNameLineEdit;
    QComboBox* categoryChoice;


    void LoadFile();
    QString color(int i);
    void CreatingWidgetsFromData();

};

#endif

