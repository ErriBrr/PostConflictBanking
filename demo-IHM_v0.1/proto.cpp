#include "proto.h"

Proto::Proto():QWidget()
{
    ajoutnouveau(personnes, "DO", "Do");
    ajoutnouveau(personnes, "RE", "Ré");
    ajoutnouveau(personnes, "MI", "Mi");
    ajoutnouveau(personnes, "FA", "Fa");
    //pers = new Personne();
    //suppression(personnes);

    //this->setWindowIcon(QIcon("logo.png"));
    this->setWindowTitle("P-C Bnkng");
    this->setFixedSize(300, 350);

// // ------------------------------- // //


    frame1 = new Frame1();
    frame2 = new Frame2();
    frame3 = new Frame3();
    tab = new Tab();


    stack = new QStackedLayout(this);
    stack->addWidget(frame1);
    stack->addWidget(frame2);
    stack->addWidget(frame3);
    stack->addWidget(tab);

    QObject::connect(frame1, SIGNAL(clicBtn1()), this, SLOT(openFrm2()));
    QObject::connect(frame1, SIGNAL(clicBtn2()), this, SLOT(openFrm3()));
    QObject::connect(frame2, SIGNAL(clicBtn3()), this, SLOT(opentab()));
    QObject::connect(frame3, SIGNAL(clicBtn4()), this, SLOT(ok()));
//    QObject::connect(tab, SIGNAL(clicBt3()), this, SLOT(suppression_pointeurs()));
    QObject::connect(tab, SIGNAL(paying()), this, SLOT(transactionSlot()));
}

void Proto::openFrm2(){
    stack->setCurrentWidget(frame2);
}

void Proto::openFrm3(){
    stack->setCurrentWidget(frame3);
}

void Proto::opentab(){
    pers = new Personne();
    pers = trouver(personnes, frame2->getName(), frame2->getFirstname());
    if(pers!=NULL){
        stack->setCurrentWidget(tab);
        tab->setNom(pers->getName());
        tab->setPrenom(pers->getFirstname());
        tab->setMoney(pers->getMoney());
    }
    else{
        stack->setCurrentWidget(frame1);
    }
}

void Proto::ok(){
    QString name=frame3->getName();
    QString firstname=frame3->getFirstname();
    QMessageBox::information(this, "Bjr Mr " + name, "Bien envoyé !");
    ajoutnouveau(personnes, name, firstname);
    stack->setCurrentWidget(frame1);
}

//void Proto::suppression_pointeurs(){
//    suppression(personnes);
//    stack->setCurrentWidget(frame1);
//    //delete pers;
//    //pers = NULL;
//}

void Proto::transactionSlot(){
    tpers = new Personne;
    tpers = trouver(personnes, tab->getNCrdt(), tab->getPCrdt());
    if (tpers != NULL){
        transaction(personnes, pers->getName(), pers->getFirstname(), tab->getNCrdt(), tab->getPCrdt(), tab->getDon());
    }
    tab->setMoney(pers->getMoney());
    //delete tpers;
    //tpers=NULL;

}

void Proto::closeEvent(QCloseEvent *event){
    suppression(personnes);
    //delete pers;
    event->accept();
    //event->ignore();
}
