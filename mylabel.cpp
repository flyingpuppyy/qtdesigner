#include "stdafx.h"
#include "mylabel.h"


MyLabel::MyLabel(QWidget* center, QWidget* parent)
	: QLabel(parent)
	,center(center)
{
	setFixedSize(100, 50);

	QPalette palette;

	palette.setColor(QPalette::Background, Qt::white);
	this->setPalette(palette);
	this->setAutoFillBackground(true);
	setText("cute label");
}

MyLabel::~MyLabel()
{}


void MyLabel::contextMenuEvent(QContextMenuEvent* event)  {
    QMenu menu(this);
    QAction* colorAction = menu.addAction("Change Color");
    QAction* fontAction = menu.addAction("Change Font");
    QAction* sizeAction = menu.addAction("Change Size");
    QAction* deleteAction = menu.addAction("delete");

    connect(colorAction, &QAction::triggered, this, &MyLabel::changeColor);
    connect(fontAction, &QAction::triggered, this, &MyLabel::changeFont);
    connect(sizeAction, &QAction::triggered, this, &MyLabel::changeSize);
    connect(deleteAction, &QAction::triggered, this, &MyLabel::deleteLabel);


    menu.exec(event->globalPos());


}


void MyLabel::mousePressEvent(QMouseEvent* event)  {
    if (event->button() == Qt::LeftButton) {

        startPos = event->globalPos();
        startWidgetPos = this->pos();
    }
}


void MyLabel::mouseMoveEvent(QMouseEvent* event)  {
    if (event->buttons() & Qt::LeftButton) {

        QPoint delta = event->globalPos() - startPos;
        this->move(startWidgetPos + delta);
    }


}


void MyLabel::mouseReleaseEvent(QMouseEvent* event)  {

    startPos = QPoint();

    if (center && !center->rect().intersects(geometry()))
    {
        emit deleteLabel();
    }


}
