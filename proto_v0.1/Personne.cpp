#include "Personne.h"

Personne::Personne(std::string name, std::string firstname, int money)
: name(name), firstname(firstname), money(money) {
}

const std::string& Personne::getFirstname() const {
    return firstname;
}

const std::string& Personne::getName() const {
    return name;
}

const int& Personne::getMoney() const {
    return money;
}

void Personne::setFirstname(std::string firstname) {
    this->firstname = firstname;
}

void Personne::setName(std::string name) {
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

std::ostream& operator<<(std::ostream& os, const Personne& p) {
    os << "Personne: {name = " << p.getName() << ", " << p.getFirstname() << "}" << " Money: {" << p.getMoney() << "}" ;
    return os;
}
