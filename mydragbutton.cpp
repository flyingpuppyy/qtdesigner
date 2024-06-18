#include "stdafx.h"


#include "mydragbutton.h"
#include "qwidget.h"

MyDragbutton::MyDragbutton(const QString& text, QWidget* parent ) : 
	QPushButton(text, parent)
{
	setMouseTracking(true); 
	
}

void MyDragbutton::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {

        setCursor(Qt::ClosedHandCursor);
    }
    QPushButton::mousePressEvent(event);
}

void MyDragbutton::mouseMoveEvent(QMouseEvent* event){
    if (event->buttons() & Qt::LeftButton) {

        QDrag* drag = new QDrag(this);
        QMimeData* mimeData = new QMimeData;
        mimeData->setText("Button");
        drag->setMimeData(mimeData);
        drag->exec(Qt::MoveAction);
    }
    QPushButton::mouseMoveEvent(event);
}

void MyDragbutton::mouseReleaseEvent(QMouseEvent* event)

{
    // 恢复默认
    setCursor(Qt::ArrowCursor);
    QPushButton::mouseReleaseEvent(event);
}


MyDragbutton::~MyDragbutton()
{}
