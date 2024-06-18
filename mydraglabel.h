#ifndef MYDRAGLABEL
#define MYDRAGLABEL


#include <QPushButton>

class MyDraglabel  : public QPushButton
{
	Q_OBJECT

protected:
    void mousePressEvent(QMouseEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void mouseReleaseEvent(QMouseEvent* event) override;


public:
	MyDraglabel(const QString& text, QWidget* parent=nullptr);
	~MyDraglabel();
};


#endif // !MYDRAGLABEL
