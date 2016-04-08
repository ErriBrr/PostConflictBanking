#include <iostream>
#include <list>
#include <string>

#include "Personne.h"

using namespace std;

void supprimUnNom(std::list<Personne*>& personnes, const std::string name, const std::string firstname);
void suppression(std::list<Personne*>& personnes);
void afficherListe(std::list<Personne*>& personnes);
void ajoutnouveau(std::list<Personne*>& personnes, std::string name, std::string firstname, int money);
void transaction(std::list<Personne*>& personnes, std::string ndebitor, std::string fndebitor, std::string ncreditor, std::string fncreditor, int money);

int main(int argc, char** argv) {
    list<Personne*> personnes;
//    Personne *michel = new Personne("Michel", "Michel", 2000);
//    personnes.push_back(michel);
//    Personne* jean = new Personne("Jean", "Jean", 2000);
//    personnes.push_back(jean);
    ajoutnouveau(personnes, "Michel", "Michel", 2000);
    ajoutnouveau(personnes, "Jean", "Jean", 2000);
    ajoutnouveau(personnes, "Gino", "Gino", 2000);
    ajoutnouveau(personnes, "Tito", "Toti", 2000);

    transaction(personnes, "Tito", "Toti", "Gino", "Gino", 500);

    afficherListe(personnes);
    supprimUnNom(personnes, "Gino", "Gino");
    std::cout << "--------------------------" << std::endl;
    afficherListe(personnes);

    suppression(personnes);

    return 0;
}

void supprimUnNom(std::list<Personne*>& personnes, const std::string name, const std::string firstname) {
    for (std::list<Personne*>::iterator it = personnes.begin(); it != personnes.end(); ++it) {
        if ((*it)->getName() == name && (*it)->getFirstname() == firstname) {
            delete  *it; // delete Personne*
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

void transaction(std::list<Personne*>& personnes, std::string ndebitor, std::string fndebitor, std::string ncreditor, std::string fncreditor, int money){
    int value;
    for (std::list<Personne*>::iterator it = personnes.begin(); it != personnes.end(); ++it) {
        if ((*it)->getName() == ndebitor && (*it)->getFirstname() == fndebitor) {
            value=(*it)->getMoney();
            value=value-money;
            (*it)->setMoney(value);
        }
    }
    for (std::list<Personne*>::iterator it = personnes.begin(); it != personnes.end(); ++it) {
        if ((*it)->getName() == ncreditor && (*it)->getFirstname() == fncreditor) {
            value=(*it)->getMoney();
            value=value+money;
            (*it)->setMoney(value);
        }
    }
}
