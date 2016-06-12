#ifndef FRAME3_H
#define FRAME3_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QGroupBox>

class Frame3 : public QFrame
{
    Q_OBJECT

public:
    Frame3();
    const QString getName() const;
    const QString getFirstname() const;

public
  slots :
    void cliquageBtn4();
  signals :
    void clicBtn4();

private:

  QLineEdit *nomIn;
  QLineEdit *prenomIn;
  QLineEdit *addrs;

  QLineEdit *firm;
  QLineEdit *func;
  QLineEdit *adrsE;

  QPushButton *btn4;

};

#endif // FRAME3_H
