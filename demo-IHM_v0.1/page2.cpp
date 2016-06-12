#include "page2.h"

Page2::Page2():QWidget(){

  lcd = new QLCDNumber();
  lcd->display(0);
  lmoney=new QLabel("0.00£");
  QGroupBox *creditorBox = new QGroupBox("Personne à créditer : ");

  // // // // / <grpbox>
  QFormLayout *layoutCrdtBX = new QFormLayout;
  nomCrdtr = new QLineEdit;
  prnCrdtr = new QLineEdit;
  layoutCrdtBX->addRow("Nom : ", nomCrdtr);
  layoutCrdtBX->addRow( blank);
  layoutCrdtBX->addRow("Prenom : ", prnCrdtr);
  creditorBox->setLayout(layoutCrdtBX);
  // // // // / </grpbox>

  spinr=new QSpinBox;
  spinr->setMaximum(2000);
  spinr->setMinimum(0);
  spinr->setAccelerated(true);
  bt3 = new QPushButton("Valider");

  QVBoxLayout *vbox2 = new QVBoxLayout;

  vbox2->addWidget(lmoney);
  vbox2->addWidget(creditorBox);
  vbox2->addWidget(lcd);
  vbox2->addWidget(spinr);
  vbox2->addWidget(bt3);

  this->setLayout(vbox2);

  // branchement :
  QObject::connect(bt3, SIGNAL(clicked()), this, SLOT(cliquageBt3()));
  QObject::connect(spinr, SIGNAL(valueChanged(int)), this, SLOT(variationMoney(int)));

}

void Tab::cliquageBt3(){
  emit Tab::clicBt3();
}

void Tab::variationMoney(int dollars){
    lcd->display(dollars);
    QString tMoney=QString::number((money)-(spinr->value()));
    lmoney->setText("Vous avez : " + tMoney + " £");
}
