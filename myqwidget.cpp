#include "stdafx.h"
#include "myqwidget.h"


MyQwidget::MyQwidget(QWidget *parent)
    : QMainWindow(parent)
    , m_offset(0, 0)
    , ui(new Ui::MyQwidgetClass())
{

    ui->setupUi(this);
    this->resize(1000, 800);

    /*
    // 创建拖拽源头，放置需要拖拽的控件
    QPushButton* button = new QPushButton("Button");


    // 设置控件的拖拽操作
    //button->setDragEnabled(true);
    

    // 将控件添加到布局中
    //layout->addWidget(button);
   // left->addWidget(button);

    //这一步分是纯单部件的移动实现
    MyQbutton* kk = new MyQbutton(this);

    kk->setFixedSize(100, 50);;
    kk->setStyleSheet("background-color:pink;");

    MyQbutton* kk2 = new MyQbutton(this);

    kk2->setFixedSize(100, 50);;
    kk2->setStyleSheet("background-color:black;");


    //拖拽的实现和测试
    setAcceptDrops(true);
    // 创建一个按钮用于添加新组件
    /*addButton = new QPushButton("Add Component", this);
    addButton->move(10, 10);
    addButton->resize(150, 30);*/



    count=0;


    createWidget();

    createCanvas();

    createLayout();

    myWindow->setLayout(mainLayout);
    middle->addWidget(childWindow);

    createToolbar();

    setAcceptDrops(true);

    createComboxes();


}


void MyQwidget::createComboxes()
{

    senderBox = new QComboBox;
    signalBox = new QComboBox;
    receiverBox = new QComboBox;
    slotBox = new QComboBox;

    connectButton = new QPushButton("Connect");
    connect(connectButton, &QPushButton::clicked, this, &MyQwidget::realConnect);

    right->addWidget(senderBox);
    right->addWidget(signalBox);
    right->addWidget(receiverBox);
    right->addWidget(slotBox);
    right->addWidget(connectButton);
    

    signalBox->addItem("clicked()");
    slotBox->addItem("beRed()");
    slotBox->addItem("beWhite()");

}

//创建主窗口
void MyQwidget::createWidget()
{
     myWindow = new QWidget();
     this->setCentralWidget(myWindow);

}

//创建三等分布局
void MyQwidget::createLayout()
{
    mainLayout = new QHBoxLayout(this);

    left = new QVBoxLayout();
    middle = new QVBoxLayout();
    right = new QVBoxLayout();

    mainLayout->addLayout(left);
    mainLayout->addLayout(middle);
    mainLayout->addLayout(right);


    mainLayout->setStretchFactor(middle, 3);
    mainLayout->setStretchFactor(left, 1); 
    mainLayout->setStretchFactor(right, 1); 
}

//创建放置画布
void MyQwidget::createCanvas()
{
    childWindow = new QWidget(this);
    childWindow->setStyleSheet("background-color: #FFCC66;");

}

void MyQwidget::createToolbar()
{

    // 自定义按钮，按钮母体
    createButton = new MyDragbutton("Create Button", this);
    createButton->setStyleSheet("background-color: #9999CC;");
    left->addWidget(createButton);

    //label母体
    createLabel = new MyDraglabel("Create Label",this);
    createLabel->setStyleSheet("background-color:  	#3399FF;");
    left->addWidget(createLabel);

    //box母体
    createBox = new MyDragbox("Create Box", this);
    createBox->setStyleSheet("background-color:  	#FF9966;");
    left->addWidget(createBox);
}

void MyQwidget::updateButbox()
{
    senderBox->clear();
    for (const Button button : butList) {
        senderBox->addItem(button.name);
    }

}

void MyQwidget::updateLabbox()
{
    receiverBox->clear();

    for (const Label lab : labList) {
        receiverBox->addItem(lab.name);
    }
}


void MyQwidget::realConnect()
{

    QObject* senderPtr = nullptr;
    QObject* receiverPtr = nullptr;

    QString senderName = senderBox->currentText();
    QString signalName = signalBox->currentText();
    QString receiverName = receiverBox->currentText();
    QString slotName = slotBox->currentText();


    //获取对象指针

    for (auto it = butList.begin(); it != butList.end(); ++it) {
        if (it->name == senderName) {
            senderPtr = it->but;
        }
    }

    for (auto it = labList.begin(); it != labList.end(); ++it) {
        if (it->name == receiverName) {
            receiverPtr = it->lab;
        }
    }


    //建立连接
    //判断对象和槽是否有效，如果有效则建立连接
    if (senderPtr && receiverPtr) {

        qDebug() << senderPtr;
        qDebug() << signalName.toStdString().c_str();
        qDebug() << slotName.toStdString().c_str();
        qDebug() << receiverPtr;
    
        if(slotName.toStdString()=="beWhite()")
        {
        
            bool success = connect(senderPtr, SIGNAL(clicked()), receiverPtr, SLOT(beWhite()));
            if (success) QMessageBox::information(nullptr, "Success", "Generation successful!");
            else QMessageBox::critical(nullptr, "Error", "Generation failed!");
            return;
        }
        else if(slotName.toStdString() == "beRed()")
        {
            bool success = connect(senderPtr, SIGNAL(clicked()), receiverPtr, SLOT(beRed()));
            if (success) QMessageBox::information(nullptr, "Success", "Generation successful!");
            else QMessageBox::critical(nullptr, "Error", "Generation failed!");
            return;
        
        }

        QMessageBox::critical(nullptr, "Error", "Generation failed!");
    }

}


//看起来这里需要一个list来进行管理
void MyQwidget::dropEvent(QDropEvent* event)  {

    //加入一个当前放置位置是否是在可放置窗口范围内的判断 /可以枚举+swicth来  


    QPoint dropPos = event->pos();


    if (childWindow->geometry().contains(dropPos)) {

        //确定被放置物品类型
        if (event->mimeData()->hasText())
        {
            QString text = event->mimeData()->text();
            if (text == "Button")
            {
                // 获取拖放的文本数据

                // 在鼠标释放的位置创建一个新按钮


                //还可写个类 no time
                MyQbutton* button = new MyQbutton(childWindow, this);
                Button temp;
                temp.name = QString("but") + QString::number(count++);
                temp.but = button;



                connect(button, &MyQbutton::deleteRequested, this, &MyQwidget::deleteButton);
                buttonList.append(button);
                butList.append(temp);
                updateButbox();

                //test
                for (MyQbutton* button : buttonList) {
                    qDebug() << button << "add";
                }


                button->move(event->pos());
                button->show();



            }
            if (text == "Label")
            {
                MyLabel* label = new MyLabel(childWindow, this);


                connect(label, &MyLabel::deleteLabelrequested, this, &MyQwidget::deleteLabel);
                Label temp;
                temp.name = QString("lab") + QString::number(count++);
                temp.lab = label;


                labelList.append(label);
                labList.append(temp);
                updateLabbox();


                //test
                for (MyLabel* label : labelList) {
                    qDebug() << label << "add";
                }


                label->move(event->pos());
                label->show();

            }
            if (text == "Textbox")
            {
                MyTextbox* box = new MyTextbox(childWindow, this);
                connect(box, &MyTextbox::deleteTextBox, this, &MyQwidget::deleteTextbox);
                boxList.append(box);

                box->move(event->pos());
                box->show();
            }
            event->accept();
        }
        else
        {
            event->ignore();
        }
    }
}

void MyQwidget::dragEnterEvent(QDragEnterEvent* event)  {

    event->accept();
}

MyQwidget::~MyQwidget()
{
    delete ui;
}


void MyQwidget::deleteButton(MyQbutton* delbutton) {

    buttonList.removeOne(delbutton);
    for (auto it = butList.begin(); it != butList.end(); ++it) {
        if (it->but == delbutton) {
            it = butList.erase(it);
            break;
        }
    }


    qDebug() << delbutton << "delete" << endl;
    delbutton->deleteLater();
    updateButbox();
}


void MyQwidget::deleteLabel(MyLabel* dellabel) {
    labelList.removeOne(dellabel);
    for (auto it = labList.begin(); it != labList.end(); ++it) {
        if (it->lab == dellabel) {
            it = labList.erase(it); 
            break;
        }
    }
    qDebug() << dellabel << "delete" << endl;
    dellabel->deleteLater();

    updateLabbox();
}


void  MyQwidget::deleteTextbox(MyTextbox* box) {

    boxList.removeOne(box);
    qDebug() << box << "delete" << endl;
    box->deleteLater();
}