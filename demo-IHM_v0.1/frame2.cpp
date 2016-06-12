#include "frame2.h"

Frame2::Frame2():QFrame() {

  QLabel *blank = new QLabel("   ");

  // éléments du second "frame" :
  QFormLayout *layout2 = new QFormLayout;
  nomCo = new QLineEdit;
  prenomCo = new QLineEdit;
  id = new QLineEdit;
  mdp = new QLineEdit;
  mdp->setEchoMode(QLineEdit::Password);
  btn3 = new QPushButton("envoyer");
  layout2->addRow( blank);
  layout2->addRow( blank);
  layout2->addRow( blank);
  layout2->addRow("Nom : ", nomCo);
  layout2->addRow("Prénom : ", prenomCo);
  layout2->addRow("ID : ", id);
  layout2->addRow("MdP : ", mdp);
  layout2->addRow(blank);
  layout2->addRow(btn3);
  layout2->addRow(blank);

  // inclusion :
  this->setLayout(layout2);

  // branchement :
  QObject::connect(btn3, SIGNAL(clicked()), this, SLOT(cliquageBtn3()));

}

void Frame2::cliquageBtn3(){
  emit Frame2::clicBtn3();
}

const QString Frame2::getName() const{
    return nomCo->text();
}

const QString Frame2::getFirstname() const{
    return prenomCo->text();
}
