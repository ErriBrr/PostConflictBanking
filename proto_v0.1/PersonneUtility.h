#ifndef PERSONNEUTILITY_H
#define PERSONNEUTILITY_H

#include <list>
#include <string>

#include "Personne.h"

void supprimUnNom(std::list<Personne*>& personnes, const std::string name, const std::string firstname);
void suppression(std::list<Personne*>& personnes);
void afficherListe(std::list<Personne*>& personnes);
void ajoutnouveau(std::list<Personne*>& personnes, std::string name, std::string firstname, int money);
void transaction(Personne& debitor, Personne& creditor, int money);
Personne* trouver(std::list<Personne*>& personnes, std::string name, std::string firstname);

#endif /* PERSONNEUTILITY_H */

