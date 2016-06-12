#ifndef PROTO_H
#define PROTO_H

#include <QApplication>
#include <QWidget>
#include <QStackedLayout>
#include <QMessageBox>
#include <QCloseEvent>

#include <list>

#include "personne.h"
#include "personneutility.h"

#include "frame1.h"
#include "frame2.h"
#include "frame3.h"
#include "tab.h"

class Proto : public QWidget
{
    Q_OBJECT

public:
    Proto();

private:
    void closeEvent(QCloseEvent *event);

public slots:
    void openFrm2();
    void openFrm3();
    void opentab();
    void ok();
//    void suppression_pointeurs();
    void transactionSlot();

private:
    std::list<Personne*> personnes;
    Personne* pers;
    Personne* tpers;

    QStackedLayout *stack;
    Frame1 *frame1;
    Frame2 *frame2;
    Frame3 *frame3;
    Tab *tab;
};

#endif // PROTO_H
