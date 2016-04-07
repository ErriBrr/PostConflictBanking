#include <iostream>
#include <list>
#include <string>

#include "Personne.h"

using namespace std;

void supprimUnNom(std::list<Personne*>& personnes, const std::string name, const std::string firstname);
void suppression(std::list<Personne*>& personnes);
void afficherListe(std::list<Personne*>& personnes);

int main(int argc, char** argv) {
    list<Personne*> personnes;
    Personne *michel = new Personne("Michel", "Michel");
    personnes.push_back(michel);
    Personne* jean = new Personne("Jean", "Jean");
    personnes.push_back(jean);

    afficherListe(personnes);
    supprimUnNom(personnes, "Jean", "Jean");
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

