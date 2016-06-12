#include "personne.h"

Personne::Personne(){

}

Personne::Personne(QString name, QString firstname, int money)
: name(name), firstname(firstname), money(money) {
}

const QString& Personne::getFirstname() const {
    return firstname;
}

const QString& Personne::getName() const {
    return name;
}

const int Personne::getMoney() const {
    return money;
}

void Personne::setFirstname(QString firstname) {
    this->firstname = firstname;
}

void Personne::setName(QString name) {
    this->name = name;
}

void Personne::setMoney(int money) {
    this->money = money;
}

Personne::~Personne() {
}

// As friend
//std::ostream& operator<<(std::ostream& os, const Personne& p) {
//    os << "Personne: {name = " << p.name << ", " << p.firstname << "}";
//    return os;
//}
/*
std::ostream& operator<<(std::ostream& os, const Personne& p) {
    os << "Personne: {name = " << p.getName() << ", " << p.getFirstname() << "}" << " Money: {" << p.getMoney() << "}" ;
    return os;
}
*/
