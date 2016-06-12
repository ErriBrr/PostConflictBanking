#include "frame1.h"

Frame1::Frame1():QFrame() {

  QLabel *blank = new QLabel("   ");

  // éléments du premier "frame" :
  bjr = new QLabel("Bonjour !");
  bjr->setAlignment(Qt::AlignCenter);
  btn1 = new QPushButton("connection");
  btn2 = new QPushButton("inscription");
  QGridLayout *layout1 = new QGridLayout;
  layout1->addWidget(bjr, 1,1);
  layout1->addWidget(btn1, 3,1);
  layout1->addWidget(btn2, 4,1);
  layout1->addWidget(blank, 5,2);
  layout1->addWidget(blank,0,0);
  layout1->addWidget(blank,2,1);

  // inclusion :
  this->setLayout(layout1);

  // branchements :
  QObject::connect(btn1, SIGNAL(clicked()), this, SLOT(cliquageBtn1()));
  QObject::connect(btn2, SIGNAL(clicked()), this, SLOT(cliquageBtn2()));

}

void Frame1::cliquageBtn1(){
  emit clicBtn1();
}

void Frame1::cliquageBtn2(){
  emit clicBtn2();
}
