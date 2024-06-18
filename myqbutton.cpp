#include "stdafx.h"

#include "myqbutton.h"

#include "qwidget.h"

MyQbutton::MyQbutton(QWidget* center, QWidget* parent)
	: QPushButton(parent) 
	,center(center)
{
	setFixedSize(100, 50);
	setText("cute button");
}

void MyQbutton::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
       
        startPos = event->globalPos();
        startWidgetPos = this->pos();
    }

}

void MyQbutton::mouseMoveEvent(QMouseEvent* event)
{

    if (event->buttons() & Qt::LeftButton)
    {
        //偏移量
        QPoint delta = event->globalPos() - startPos;
       
        this->move(startWidgetPos + delta);
    }

}

void MyQbutton::contextMenuEvent(QContextMenuEvent* event)
{
    QMenu menu(this);
    QAction* colorAction = menu.addAction("Change Color");
    QAction* fontAction = menu.addAction("Change Font");
    QAction* sizeAction = menu.addAction("Change Size");
    QAction* deleteAction = menu.addAction("delete");

    connect(colorAction, &QAction::triggered, this, &MyQbutton::changeColor);
    connect(fontAction, &QAction::triggered, this, &MyQbutton::changeFont);
    connect(sizeAction, &QAction::triggered, this, &MyQbutton::changeSize);
    connect(deleteAction, &QAction::triggered, this, &MyQbutton::deleteButton);


    menu.exec(event->globalPos());

}

void MyQbutton::mouseReleaseEvent(QMouseEvent* event) 
{
    startPos = QPoint();
    if (center && !center->rect().intersects(geometry()))
    {
        emit deleteButton();
        return;
    }
    emit clicked();
}

void MyQbutton::changeColor()
{

    QColor color = QColorDialog::getColor(this->palette().color(QPalette::Button), this, tr("Select Color"));
    if (color.isValid()) {

        QString style = QString("background-color: %1;").arg(color.name());
        setStyleSheet(style);

    }
}

void MyQbutton::changeFont()
{
    bool fontOk;
    QFont font = QFontDialog::getFont(&fontOk, this->font(), this, tr("Select Font"));
    if (fontOk) {
        this->setFont(font);
    }


}

void MyQbutton::changeSize()
{
    bool sizeOk;
    int size = QInputDialog::getInt(this, tr("Change Size"), tr("Enter new size:"), this->font().pointSize(), 1, 100, 1, &sizeOk);
    if (sizeOk) {
        QFont font = this->font();
        font.setPointSize(size);
        this->setFont(font);
    }

}

void MyQbutton::deleteButton()
{
    emit deleteRequested(this);
}

MyQbutton::~MyQbutton()
{}
