#include "page1.h"

Page1::Page1():QWidget(){

  line = new QLabel("Votre nom : ...");
  l1 = new QLabel("Votre prénom : ...");
  QLabel *l2 = new QLabel("ID : ....");
  QLabel *ltest = new QLabel("- - - - - - - - - - - - - - - - - -");
  QLabel *l3 = new QLabel("... : ...");
  QLabel *l4 = new QLabel("... : ...");
  QLabel *l5 = new QLabel("... : ....");
  QVBoxLayout *vbox1 = new QVBoxLayout;
  vbox1->addWidget(line);
  vbox1->addWidget(l1);
  vbox1->addWidget(l2);
  vbox1->addWidget(ltest);
  vbox1->addWidget(l3);
  vbox1->addWidget(l4);
  vbox1->addWidget(l5);
  this->setLayout(vbox1);

}

void Page1::setNom(QString nom){
  line->setText("Votre nom : " + nom);
}

void Page1::setPrenom(QString prenom){
  l1->setText("Votre prenom : " + prenom);
}
