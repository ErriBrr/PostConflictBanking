#ifndef PAGE2_H
#define PAGE2_H

#include <QApplication>
#include <QWidget>

#include <QLCDNumber>
#include <QLabel>
#include <QGroupBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QPushButton>

class Proto : public QWidget
{
    Q_OBJECT

public:
  Page2();

private:
  QLCDNumber lcd;
  QLabel lmoney;
  QLineEdit nomCrdtr;
  QLineEdit prnCrdtr;
  QSpinBox spinr;
  QPushButton bt3;

};

#endif // PAGE2_H
