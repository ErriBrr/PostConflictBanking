#include "tab.h"

Tab::Tab():QTabWidget(){

  QLabel *blank = new QLabel("   ");

  // crea des pages :
  QWidget *page1 = new QWidget;
  QWidget *page2 = new QWidget;
  page3 = new QWidget;
  QWidget *page4 = new QWidget;

  // crea du contenu :

  // page 1
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
  page1->setLayout(vbox1);

  // page 2
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
  page2->setLayout(vbox2);

  // page 3
  //  page3->setPixmap(QPixmap("sketch.png", "PNG"));
  //  page3->setAlignment(Qt::AlignCenter);
  QLabel* title= new QLabel("Historique des transactions");
  title->setAlignment(Qt::AlignHCenter);
  separator= "---------------------------";
  vBoxP3 = new QVBoxLayout;
  vBoxP3->addWidget(title);
  vBoxP3->addWidget(new QLabel(separator));
  page3->setLayout(vBoxP3);

  // page 4
  QWebEngineView *pageWeb = new QWebEngineView;
  pageWeb->load(QUrl("https://github.com/ErriBrr/PostConflictBanking"));
  QVBoxLayout *vbox3 = new QVBoxLayout;
  vbox3->addWidget(pageWeb);
  page4->setLayout(vbox3);

  // // // //

  // inclusion :
  this->addTab(page1, "Information");
  this->addTab(page2, "Transaction");
  this->addTab(page3, "Historique");
  this->addTab(page4, "FAQ");

  // branchement :
  QObject::connect(bt3, SIGNAL(clicked()), this, SLOT(pay()));
  QObject::connect(spinr, SIGNAL(valueChanged(int)), this, SLOT(variationMoney(int)));
//  QObject::connect(bt4, SIGNAL(clicked()), this, SLOT(cliquageBt3()));
}

//void Tab::cliquageBt3(){
//  emit Tab::clicBt3();
//}

void Tab::pay(){
  nCrdt=nomCrdtr->text();
  pCrdt=prnCrdtr->text();
  don=spinr->value();
  emit Tab::paying();
  spinr->setValue(0);
  nomCrdtr->setText("");
  prnCrdtr->setText("");

  // edit historic :
  vBoxP3->addWidget(new QLabel(pCrdt +" "+ nCrdt +" : "+ QString::number(don) +"£"));
  vBoxP3->addWidget(new QLabel(separator));
  page3->setLayout(vBoxP3);
}

void Tab::variationMoney(int dollars){
    lcd->display(dollars);
    lmoney->setText("Vous avez : " + QString::number((money)-dollars) + " £");
}

void Tab::setNom(QString name){
    this->name=name;
    line->setText("Votre nom : " + this->name);
}

void Tab::setPrenom(QString firstname){
    this->firstname=firstname;
    l1->setText("Votre prénom : " + this->firstname);
}

void Tab::setMoney(int money){
    this->money=money;
    lmoney->setText("Vous avez : " + QString::number(money) + " £");
}

const QString Tab::getNCrdt() const{
    return nCrdt;
}

const QString Tab::getPCrdt() const{
    return pCrdt;
}

const int Tab::getDon() const{
    return don;
}
