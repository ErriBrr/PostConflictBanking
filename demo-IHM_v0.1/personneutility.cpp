#include "personneutility.h"

using namespace std;

void supprimUnNom(std::list<Personne*>& personnes, const QString name, const QString firstname) {
    for (std::list<Personne*>::iterator it = personnes.begin(); it != personnes.end(); ++it) {
        if ((*it)->getName() == name && (*it)->getFirstname() == firstname) {
            delete *it; // delete Personne*
            it = personnes.erase(it);
        }
    }
}

void suppression(std::list<Personne*>& personnes) {
    while (!personnes.empty()) {
        delete personnes.front();
        personnes.pop_front();
    }
}
/*
void afficherListe(std::list<Personne*>& personnes) {
    for (list<Personne*>::iterator it = personnes.begin(); it != personnes.end(); ++it) {
        Personne p = *(*it);
        cout << "Personne: {name = " << p.getName() << ", " << p.getFirstname() << "}" << " Money: {" << p.getMoney() << "}"  << endl;
    }
}
*/
void ajoutnouveau(std::list<Personne*>& personnes, QString name, QString firstname) {
    Personne* nouveau = new Personne(name, firstname, 2000);
    personnes.push_back(nouveau);
}

Personne* trouver(std::list<Personne*>& personnes, QString name, QString firstname) {
    for (std::list<Personne*>::iterator it = personnes.begin(); it != personnes.end(); ++it) {
        if ((*it)->getName() == name && (*it)->getFirstname() == firstname) {
            return *it;
        }
    }
    return NULL;
}

void transaction(std::list<Personne*>& personnes, QString ndbtr, QString fndbtr, QString ncdtr, QString fncdtr, int money) {
    Personne* debitor = trouver(personnes, ndbtr, fndbtr);
    Personne* creditor = trouver(personnes, ncdtr, fncdtr);
    if (debitor != NULL && creditor != NULL) {
        Personne& debitr=*debitor;
        Personne& creditr=*creditor;
        debitr.setMoney(debitr.getMoney() - money);
        creditr.setMoney(creditr.getMoney() + money);
    }
    debitor=NULL;
    creditor=NULL;
}

