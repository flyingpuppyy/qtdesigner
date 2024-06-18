#include "stdafx.h"
#include "mydragbox.h"

MyDragbox::MyDragbox(const QString& text, QWidget* parent) 
	: QPushButton(text, parent)
{
	setMouseTracking(true);
}


void MyDragbox::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {

        setCursor(Qt::ClosedHandCursor);
    }
    QPushButton::mousePressEvent(event);
}


void MyDragbox::mouseMoveEvent(QMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton) {

        QDrag* drag = new QDrag(this);
        QMimeData* mimeData = new QMimeData;
        mimeData->setText("Textbox");
        drag->setMimeData(mimeData);
        drag->exec(Qt::MoveAction);
    }
    QPushButton::mouseMoveEvent(event);
}

void MyDragbox::mouseReleaseEvent(QMouseEvent* event)

{

    setCursor(Qt::ArrowCursor);
    QPushButton::mouseReleaseEvent(event);
}

MyDragbox::~MyDragbox()
{}
