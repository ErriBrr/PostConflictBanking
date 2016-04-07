#include "Personne.h"

Personne::Personne(std::string name, std::string firstname)
: name(name), firstname(firstname) {
}

const std::string& Personne::getFirstname() const {
    return firstname;
}

const std::string& Personne::getName() const {
    return name;
}

void Personne::setFirstname(std::string firstname) {
    this->firstname = firstname;
}

void Personne::setName(std::string name) {
    this->name = name;
}

Personne::~Personne() {
}

// As friend
//std::ostream& operator<<(std::ostream& os, const Personne& p) {
//    os << "Personne: {name = " << p.name << ", " << p.firstname << "}";
//    return os;
//}

std::ostream& operator<<(std::ostream& os, const Personne& p) {
    os << "Personne: {name = " << p.getName() << ", " << p.getFirstname() << "}";
    return os;
}