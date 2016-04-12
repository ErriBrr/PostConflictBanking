#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <iostream>

class Personne {
public:
    Personne(std::string name, std::string firstname, int money);

    const std::string& getFirstname() const;
    void setFirstname(std::string firstname);
    const std::string& getName() const;
    void setName(std::string name);
    int getMoney() const;
    void setMoney(int money);

    virtual ~Personne();

private:
    // As friend
    //friend std::ostream & operator<<(std::ostream &os, const Personne& p);
private:
    std::string name;
    std::string firstname;
    int money;
};

std::ostream & operator<<(std::ostream &os, const Personne& p);


#endif /* PERSONNE_H */

