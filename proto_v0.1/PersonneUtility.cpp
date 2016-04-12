#include "PersonneUtility.h"

using namespace std;

void supprimUnNom(std::list<Personne*>& personnes, const std::string name, const std::string firstname) {
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

void afficherListe(std::list<Personne*>& personnes) {
    for (list<Personne*>::iterator it = personnes.begin(); it != personnes.end(); ++it) {
        cout << *(*it) << endl;
    }
}

void ajoutnouveau(std::list<Personne*>& personnes, std::string name, std::string firstname, int money) {
    Personne* nouveau = new Personne(name, firstname, money);
    personnes.push_back(nouveau);
}

Personne* trouver(std::list<Personne*>& personnes, std::string name, std::string firstname) {
    for (std::list<Personne*>::iterator it = personnes.begin(); it != personnes.end(); ++it) {
        if ((*it)->getName() == name && (*it)->getFirstname() == firstname) {
            return *it;
        }
    }
    return NULL;
}

void transaction(Personne& debitor, Personne& creditor, int money) {
    debitor.setMoney(debitor.getMoney() - money);
    creditor.setMoney(creditor.getMoney() + money);
}

