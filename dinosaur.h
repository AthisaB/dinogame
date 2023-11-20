// Dinosaur.h
#ifndef DINOSAUR_H
#define DINOSAUR_H

#include <string>

class Dinosaur
{
public:
    Dinosaur(std::string name, int health, int attack);

    std::string getName() const;
    int getHealth() const;
    int getAttack() const;

    void takeDamage(int damage);
    // You can add more functions related to dinosaur behavior here

private:
    std::string name;
    int health;
    int attack;
    // Add more attributes as needed
};

#endif // DINOSAUR_H
