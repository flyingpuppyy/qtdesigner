#ifndef MYLABEL
#define MYLABEL



#include <QLabel>

class MyLabel: public QLabel
{
	Q_OBJECT

public:
	MyLabel(QWidget* center, QWidget* parent = nullptr);
	~MyLabel();


protected:

    void contextMenuEvent(QContextMenuEvent* event);

    void mousePressEvent(QMouseEvent* event) override;

    void mouseMoveEvent(QMouseEvent* event) override;

    void mouseReleaseEvent(QMouseEvent* event) override;

    void changeColor() {
        QColor color = QColorDialog::getColor(this->palette().color(QPalette::Background), this, tr("Select Color"));
        if (color.isValid()) {
            QPalette palette = this->palette();
            palette.setColor(QPalette::Background, color);
            this->setPalette(palette);
        }
    }

    void changeFont() {
        bool fontOk;
        QFont font = QFontDialog::getFont(&fontOk, this->font(), this, tr("Select Font"));
        if (fontOk) {
            this->setFont(font);
        }
    }

    void changeSize() {
        bool sizeOk;
        int size = QInputDialog::getInt(this, tr("Change Size"), tr("Enter new size:"), this->font().pointSize(), 1, 100, 1, &sizeOk);
        if (sizeOk) {
            QFont font = this->font();
            font.setPointSize(size);
            this->setFont(font);
        }
    }


    void deleteLabel() {
        emit deleteLabelrequested(this);
    }

public slots:
    void beWhite()
    {  
        setStyleSheet("color:white;");
    }
    
    

    void beRed()
    {
    
        setStyleSheet("color:red;");
    }

signals:
    void deleteLabelrequested(MyLabel* button); 



private:
    QPoint startPos; 
    QPoint startWidgetPos; 

    QWidget* center;

};


#endif // !MYLABEL