#include <iostream>
#include <list>
#include <string>

#include "Personne.h"
#include "PersonneUtility.h"

using namespace std;

int main(int argc, char** argv) {
    list<Personne*> personnes;
    ajoutnouveau(personnes, "Michel", "Michel", 2000);
    ajoutnouveau(personnes, "Jean", "Jean", 2000);
    ajoutnouveau(personnes, "Gino", "Gino", 2000);
    ajoutnouveau(personnes, "Tito", "Toti", 2000);

    afficherListe(personnes);
    std::cout << "--------------------------" << std::endl;
    Personne* debitor = trouver(personnes, "Tito", "Toti");
    Personne* creditor = trouver(personnes, "Gino", "Gino");
    if (debitor != NULL && creditor != NULL) {
        transaction(*debitor, *creditor, 500);
    }

    afficherListe(personnes);
    supprimUnNom(personnes, "Gino", "Gino");
    std::cout << "--------------------------" << std::endl;
    afficherListe(personnes);

    suppression(personnes);

    return 0;
}

