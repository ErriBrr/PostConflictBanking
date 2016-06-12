#ifndef FRAME2_H
#define FRAME2_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>


class Frame2 : public QFrame
{
    Q_OBJECT

public:
    Frame2();
    //const QPushButton& getBtn3() const;
    const QString getName() const;
    const QString getFirstname() const;



public
  slots :
    void cliquageBtn3();
  signals :
    void clicBtn3();

private:

  QLineEdit *nomCo;
  QLineEdit *prenomCo;
  QLineEdit *id;
  QLineEdit *mdp;

  QPushButton *btn3;

};

#endif // FRAME2_H
