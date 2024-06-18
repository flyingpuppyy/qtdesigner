#ifndef MYTEXTBOX_H
#define MYTEXTBOX_H


#include <QTextEdit>

class MyTextbox  : public QTextEdit
{
	Q_OBJECT

public:
	MyTextbox(QWidget* center,QWidget *parent=nullptr);
	~MyTextbox();

    void contextMenuEvent(QContextMenuEvent* event) override;

    void mousePressEvent(QMouseEvent* event) override;


    void mouseMoveEvent(QMouseEvent* event) override; 

    void mouseReleaseEvent(QMouseEvent* event) override;

    void changeColor() {
        QColor color = QColorDialog::getColor(this->palette().color(QPalette::Button), this, tr("Select Color"));
        if (color.isValid()) 
        {
            setStyleSheet(QString("background-color: %1;").arg(color.name()));
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


    void deleteBox() {
        emit deleteTextBox(this);
    }

signals:
    void deleteTextBox(MyTextbox* box);



private:
    QPoint startPos; 
    QPoint startWidgetPos;

    QWidget* center;

};


#endif // !MYTEXTBOX_H
