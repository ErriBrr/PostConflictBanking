#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <iostream>

#include<QString>

class Personne {
public:
    Personne();
    Personne(QString name, QString firstname, int money);

    const QString& getFirstname() const;
    void setFirstname(QString firstname);
    const QString& getName() const;
    void setName(QString name);
    const int getMoney() const;
    void setMoney(int money);

    virtual ~Personne();

//private:
    // As friend
    //friend std::ostream & operator<<(std::ostream &os, const Personne& p);
private:
    QString name;
    QString firstname;
    int money;
};

//std::ostream & operator<<(std::ostream &os, const Personne& p);


#endif /* PERSONNE_H */
