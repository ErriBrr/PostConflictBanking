#include "frame3.h"

Frame3::Frame3():QFrame() {

  QLabel *blank = new QLabel("   ");

  // 1ere sous-partie
  QFrame *frame4 = new QFrame;
  QFormLayout *layout3 = new QFormLayout;
  nomIn = new QLineEdit;
  prenomIn = new QLineEdit;
  addrs = new QLineEdit;
  layout3->addRow( blank);
  layout3->addRow( blank);
  layout3->addRow("Nom : ", nomIn);
  layout3->addRow("Prénom : ", prenomIn);
  layout3->addRow("Adresse : ", addrs);
  layout3->addRow( blank);
  frame4->setLayout(layout3);

  // 2eme sous-partie
  QGroupBox *box1 = new QGroupBox("Salarié");
  bool employ=1;
  box1->setCheckable(employ);
  QFormLayout *layout4 = new QFormLayout;
  firm = new QLineEdit;
  func = new QLineEdit;
  adrsE = new QLineEdit;
  layout4->addRow( blank);
  layout4->addRow("Entreprise : ", firm);
  layout4->addRow("Fonction : ", func);
  layout4->addRow("Adresse : ", adrsE);
  layout4->addRow( blank);
  box1->setLayout(layout4);

  // derniere sous-partie
  QFrame *frame5 = new QFrame;
  QGridLayout *layout5 = new QGridLayout;
  btn4 = new QPushButton("Envoyer");
  layout5->addWidget(blank, 0,0);
  layout5->addWidget(blank, 1,2);
  layout5->addWidget(btn4, 1,1);
  frame5->setLayout(layout5);

  // inclusion :
  QVBoxLayout *layout6 = new QVBoxLayout;
  layout6->addWidget(frame4);
  layout6->addWidget(box1);
  layout6->addWidget(frame5);
  this->setLayout(layout6);

  // branchement :
  QObject::connect(btn4, SIGNAL(clicked()), this, SLOT(cliquageBtn4()));

}

void Frame3::cliquageBtn4(){
  emit Frame3::clicBtn4();
}


const QString Frame3::getName() const{
    return nomIn->text();
}

const QString Frame3::getFirstname() const{
    return prenomIn->text();
}
