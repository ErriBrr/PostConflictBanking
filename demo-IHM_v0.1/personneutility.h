#ifndef PERSONNEUTILITY_H
#define PERSONNEUTILITY_H

#include <list>
#include <string>

#include "personne.h"

void supprimUnNom(std::list<Personne*>& personnes, const QString name, const QString firstname);
void suppression(std::list<Personne*>& personnes);
//void afficherListe(std::list<Personne*>& personnes);
void ajoutnouveau(std::list<Personne*>& personnes, QString name, QString firstname);
void transaction(std::list<Personne*>& personnes, QString ndbtr, QString fndbtr, QString ncdtr, QString fncdtr, int money);
Personne* trouver(std::list<Personne*>& personnes, QString name, QString firstname);

#endif /* PERSONNEUTILITY_H */

