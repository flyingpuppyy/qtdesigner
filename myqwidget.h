#ifndef MYQWIDGET_H
#define MYQWIDGET_H

#include <QtWidgets/QMainWindow>
#include "ui_myqwidget.h"
#include "qdrag.h"
#include "qlist"
#include "qpair.h"


#include "myqbutton.h"
#include "mydragbutton.h"
#include "mydraglabel.h"
#include "mylabel.h"
#include "mydragbox.h"
#include "mytextbox.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MyQwidgetClass; };
QT_END_NAMESPACE

struct  Button
{
    QString name;
    MyQbutton* but;
};

struct  Label
{
    QString name;
    MyLabel* lab;
};


class MyQwidget : public QMainWindow
{
    Q_OBJECT

public:
    MyQwidget(QWidget *parent = nullptr);
    ~MyQwidget();


private:
    void createCanvas();
    void createLayout();
    void createWidget();
    void createToolbar();
    void createComboxes();

    void updateButbox();
    void updateLabbox();

protected:

    
    void dropEvent(QDropEvent* event) override;

    void dragEnterEvent(QDragEnterEvent* event) override;

private slots:


    void realConnect();

    void deleteButton(MyQbutton* delbutton);


    void deleteLabel(MyLabel* dellabel);


    void deleteTextbox(MyTextbox* box);

private:
    QPoint m_offset; // 偏移量
   
    QToolBar* m_toolbar;



    QPoint startPos;



    //拖拽的测试
    QPushButton* addButton;

    QList<MyQbutton*> buttonList;
    QList<MyLabel*> labelList;
    QList<MyTextbox*> boxList;

    QList<Button> butList;
    QList<Label> labList;

    //能够拖放的页面
    QWidget* childWindow;

    QVBoxLayout* left;
    QVBoxLayout* middle;
    QVBoxLayout* right;

    QHBoxLayout* mainLayout;


    //主窗口
    QWidget* myWindow;

    //生成button
    MyDragbutton* createButton;
    MyDraglabel* createLabel;
    MyDragbox* createBox;

    //box
    QComboBox* senderBox;
    QComboBox* signalBox;
    QComboBox* receiverBox;
    QComboBox* slotBox;
    QPushButton* connectButton;

    //防止重名
    int count;

private:
    Ui::MyQwidgetClass *ui;
};

#endif