#ifndef PAGE1_H
#define PAGE1_H

#include <QApplication>
#include <QWidget>

#include <QVBoxLayout>
#include <QLabel>

class Proto : public QWidget
{
    Q_OBJECT

public:
  Page1();
  void setNom(QString nom);
  void setPrenom(QString prenom);

private:
  QLabel line;
  QLabel l1;

};

#endif // PAGE1_H
