#include "stdafx.h"
#include "mydraglabel.h"

MyDraglabel::MyDraglabel(const QString& text, QWidget* parent) :
	QPushButton(text, parent)
{
	setMouseTracking(true);
}


void MyDraglabel::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {

        setCursor(Qt::ClosedHandCursor);
    }
    QPushButton::mousePressEvent(event);
}


void MyDraglabel::mouseMoveEvent(QMouseEvent* event) {
    if (event->buttons() & Qt::LeftButton) {

        QDrag* drag = new QDrag(this);
        QMimeData* mimeData = new QMimeData;
        mimeData->setText("Label");
        drag->setMimeData(mimeData);
        drag->exec(Qt::MoveAction);
    }
    QPushButton::mouseMoveEvent(event);
}

void MyDraglabel::mouseReleaseEvent(QMouseEvent* event)

{
    setCursor(Qt::ArrowCursor);
    QPushButton::mouseReleaseEvent(event);
}


MyDraglabel::~MyDraglabel()
{}
