#ifndef FRAME1_H
#define FRAME1_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QGridLayout>
#include <QLabel>


class Frame1 : public QFrame
{
    Q_OBJECT

public:
    Frame1();

public
  slots :
    void cliquageBtn1();
    void cliquageBtn2();
  signals :
    void clicBtn1();
    void clicBtn2();

private :

    QLabel *bjr;

    QPushButton *btn1;
    QPushButton *btn2;

};

#endif // FRAME1_H
