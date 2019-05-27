#include "Checklist.h"


Checklist::Checklist(QString filename, QWidget* window)
        : m_filename(filename), m_categories(), m_QCategories()
{
    QWidget();



    //NOTE(hugo): Creating the main groupBox containing all the
    //IMPORTANT(hugo): What should the parent of this widget be ?
    m_mainGroupBox = new QGroupBox("ToDo", window);

    m_mainGroupBoxLayout = new QHBoxLayout(this);

//    CreatingWidgetsFromData();

    m_mainGroupBox->setLayout(m_mainGroupBoxLayout);
}

Checklist::~Checklist()
{

}





void
Checklist::addCatPressed()
{
    actionWindow = new QWidget();
    actionWindow->setVisible(true);
    actionWindow->setWindowTitle("Checklist Name");

    actionWindow->resize(200,100);

    QVBoxLayout* mainLayout = new QVBoxLayout(actionWindow);
    QLabel* catNameLabel = new QLabel("Checklist Name",
                                      actionWindow);
    catNameLineEdit = new QLineEdit(actionWindow);

    QPushButton* okButton = new QPushButton("Ok",
                                            actionWindow);

    mainLayout->addWidget(catNameLabel);
    mainLayout->addWidget(catNameLineEdit);
    mainLayout->addWidget(okButton);

    actionWindow->setLayout(mainLayout);

    QObject::connect(okButton,
                     SIGNAL(clicked()),
                     this,
                     SLOT(addCategory()));
}



void
Checklist::addCategory()
{
    QString catName = catNameLineEdit->text();
    ToDoCategory* newCategory = new ToDoCategory();
    newCategory->name = catName;
    newCategory->items = QVector<QString>();

    m_categories.append(newCategory);

    ToDoCategoryWidget* newQCategory = new ToDoCategoryWidget();
    newQCategory->GroupBox = new QGroupBox(catName,
                                           this);
    newQCategory->GroupBox->
            setStyleSheet("color: " + color(m_categories.size()-1));
    newQCategory->Layout = new QVBoxLayout(this);
    newQCategory->Items = new QListWidget(this);

    newQCategory->Layout->addWidget(newQCategory->Items);
    newQCategory->GroupBox->setLayout(newQCategory->Layout);
    m_mainGroupBoxLayout->addWidget(newQCategory->GroupBox);

    m_QCategories.append(newQCategory);


    delete actionWindow;

    if(!m_filename.isEmpty())
//	SaveFile();
        ;}


QString
Checklist::color(int i)
{
    if(i == 0)
        return "blue";
    if(i == 1)
        return "darkorange";
    if(i == 2)
        return "green";
    if(i == 3)
        return "gold";
    if(i == 4)
        return "red";

    return "black";
}





void
Checklist::addToDoItem()
{
    QString CategoryName = categoryChoice->currentText();
    QString ItemName = toDoNameLineEdit->text();

    for(int CategoryIndex = 0;
        CategoryIndex < m_categories.size();
        CategoryIndex++)
    {

        if(m_categories[CategoryIndex]->name == CategoryName)
        {
            m_categories[CategoryIndex]->items.push_back(ItemName);

            //NOTE(hugo): I assume that m_categories and m_QCategories
            // are correlated concerning the category they represent

            m_QCategories[CategoryIndex]->Items->addItem(
                    new QListWidgetItem(ItemName,
                                        m_QCategories[CategoryIndex]->Items));
            break;
        }
    }

    delete actionWindow;

    if(!m_filename.isEmpty())
//	SaveFile();
        ;}


void
Checklist::addPressed()
{

    actionWindow = new QWidget();
    actionWindow->setVisible(true);
    actionWindow->setWindowTitle("What to add ?");

    actionWindow->resize(200,100);

    QVBoxLayout* mainLayout = new QVBoxLayout(actionWindow);
    QLabel* catNameLabel = new QLabel("Checklist Name",
                                      actionWindow);
    //catNameLineEdit = new QLineEdit(actionWindow);
    categoryChoice = new QComboBox(actionWindow);
    for(int CategoryIndex = 0;
        CategoryIndex < m_categories.size();
        ++CategoryIndex)
    {
        categoryChoice->addItem(m_categories[CategoryIndex]->name);
    }
    QLabel* toDoNameLabel = new QLabel("Task Name",
                                       actionWindow);
    toDoNameLineEdit = new QLineEdit(actionWindow);

    QPushButton* okButton = new QPushButton("Ok",
                                            actionWindow);


    mainLayout->addWidget(catNameLabel);
    mainLayout->addWidget(categoryChoice);
    mainLayout->addWidget(toDoNameLabel);
    mainLayout->addWidget(toDoNameLineEdit);
    mainLayout->addWidget(okButton);

    actionWindow->setLayout(mainLayout);

    QObject::connect(okButton,
                     SIGNAL(clicked()),
                     this,
                     SLOT(addToDoItem()));
}













