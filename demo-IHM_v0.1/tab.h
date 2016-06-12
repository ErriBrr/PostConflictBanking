#ifndef TAB_H
#define TAB_H

#include <QApplication>
#include <QWidget>
#include <QtWebEngineWidgets>

#include <QPushButton>
#include <QTabWidget>
#include <QGridLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QSpinBox>
#include <QLineEdit>
#include <QGroupBox>
#include <QFormLayout>

class Tab : public QTabWidget
{
    Q_OBJECT

public:
    Tab();

    void setNom(QString name);
    void setPrenom(QString firstname);
    void setMoney(int money);

    const QString getNCrdt() const;
    const QString getPCrdt() const;
    const int getDon() const;

public
  slots :
//    void cliquageBt3();
    void variationMoney(int dollars);
    void pay();
  signals :
//    void clicBt3();
    void paying();

private:
  QWidget *page3;
  QString separator;
  QVBoxLayout* vBoxP3;

  QString name;
  QString firstname;
  int money;

  QString nCrdt;
  QString pCrdt;
  int don;

  QLabel *line;
  QLabel *l1;
  QLCDNumber *lcd;
  QLabel *lmoney;

  QLineEdit *nomCrdtr;
  QLineEdit *prnCrdtr;
  QSpinBox *spinr;

  QPushButton *bt3;

};

#endif // TAB_H
