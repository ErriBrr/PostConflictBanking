#include <iostream>
#include <list>
#include <string>

#include "Personne.h"
#include "PersonneUtility.h"

using namespace std;

int main(int argc, char** argv) {
    list<Personne*> personnes;
    ajoutnouveau(personnes, "DO", "Do", 2000);
    ajoutnouveau(personnes, "RE", "Re", 2000);
    ajoutnouveau(personnes, "MI", "Mi", 2000);
    ajoutnouveau(personnes, "FA", "Fa", 2000);

    afficherListe(personnes);
    std::cout << "--------------------------" << std::endl;
    Personne* debitor = trouver(personnes, "DO", "Do");
    Personne* creditor = trouver(personnes, "FA", "Fa");
    if (debitor != NULL && creditor != NULL) {
        transaction(*debitor, *creditor, 500);
    }

    afficherListe(personnes);
    supprimUnNom(personnes, "RE", "Re");
    std::cout << "--------------------------" << std::endl;
    afficherListe(personnes);

    suppression(personnes);

    return 0;
}

