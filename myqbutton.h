#pragma once

#ifndef MYQBUTTON_H
#define MYQBUTTON_H


#include <QPushButton>
#include "qfontdialog.h"

class MyQbutton  : public QPushButton
{
	Q_OBJECT

public:
    MyQbutton(QWidget* center,QWidget* parent = nullptr);
	~MyQbutton();

protected:

    void contextMenuEvent(QContextMenuEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void mouseReleaseEvent(QMouseEvent* event) override;

    void changeColor();

    void changeFont();

    void changeSize();


    void deleteButton();
    
signals:
    void deleteRequested(MyQbutton* button); 

private:
    QPoint startPos; 
    QPoint startWidgetPos; 

    QWidget* center;

};
#endif //MYQBUTTON_H