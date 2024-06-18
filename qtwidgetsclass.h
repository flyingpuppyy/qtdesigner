#pragma once
#ifndef QTWIDGETSCLASS_H
#define QTWIDGETSCLASS_H



#include <QMainWindow>
#include "ui_qtwidgetsclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QtWidgetsClassClass; };
QT_END_NAMESPACE

class QtWidgetsClass : public QMainWindow
{
	Q_OBJECT

public:
	QtWidgetsClass(QWidget *parent = nullptr);
	~QtWidgetsClass();

private:
	Ui::QtWidgetsClassClass *ui;
};



#endif // !QTWIDGETSCLASS_H