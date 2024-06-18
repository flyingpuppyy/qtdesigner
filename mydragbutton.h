#ifndef MYDRAGBUTTON
#define MYDRAGBUTTON

#include <QPushButton>

class MyDragbutton  : public QPushButton
{
	Q_OBJECT

public:
    MyDragbutton(const QString& text, QWidget* parent = nullptr);
    ~MyDragbutton();


protected:
    void mousePressEvent(QMouseEvent* event) override; 

    void mouseMoveEvent(QMouseEvent* event) override;
    
    void mouseReleaseEvent(QMouseEvent* event) override; 


	
};


#endif // !MYDRAGBUTTON
