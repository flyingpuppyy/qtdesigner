#ifndef MYDRAGBOX
#define MYDRAGBOX

#include <QPushbutton>

class MyDragbox  : public QPushButton
{
	Q_OBJECT


protected:
	void mousePressEvent(QMouseEvent* event) override;

	void mouseMoveEvent(QMouseEvent* event) override;

	void mouseReleaseEvent(QMouseEvent* event) override;


public:
	MyDragbox(const QString& text, QWidget* parent=nullptr);
	~MyDragbox();
};


#endif // !MYDRAGBOX