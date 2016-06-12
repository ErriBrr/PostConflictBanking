#include <QApplication>

#include "proto.h"

#include <list>
#include "personne.h"
#include "personneutility.h"

//using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Proto fenetre;
    fenetre.show();

    return app.exec();
}
