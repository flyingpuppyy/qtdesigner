#include "stdafx.h"
#include "mytextbox.h"

MyTextbox::MyTextbox(QWidget* center, QWidget* parent)
	: QTextEdit(parent)
	,center(center)
{
	setFixedSize(100,200);

}

MyTextbox::~MyTextbox()
{}


void MyTextbox::contextMenuEvent(QContextMenuEvent* event) {
    QMenu menu(this);
    QAction* colorAction = menu.addAction("Change Color");
    QAction* fontAction = menu.addAction("Change Font");
    QAction* sizeAction = menu.addAction("Change Size");
    QAction* deleteAction = menu.addAction("delete");

    connect(colorAction, &QAction::triggered, this, &MyTextbox::changeColor);
    connect(fontAction, &QAction::triggered, this, &MyTextbox::changeFont);
    connect(sizeAction, &QAction::triggered, this, &MyTextbox::changeSize);
    connect(deleteAction, &QAction::triggered, this, &MyTextbox::deleteBox);


    menu.exec(event->globalPos());
}



void MyTextbox::mousePressEvent(QMouseEvent* event){
    if (event->button() == Qt::LeftButton) {
        startPos = event->globalPos();
        startWidgetPos = this->pos();
    }
}


void  MyTextbox::mouseMoveEvent(QMouseEvent* event)  {
    if (event->buttons() & Qt::LeftButton) {
        QPoint delta = event->globalPos() - startPos;
        this->move(startWidgetPos + delta);
    }
}

void MyTextbox::mouseReleaseEvent(QMouseEvent* event)  {


    if (center && !center->rect().intersects(geometry()))
    {
        emit deleteBox();
    }
    startPos = QPoint();
}