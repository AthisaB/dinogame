// Dinosaur.cpp
#include "dinosaur.h"

Dinosaur::Dinosaur(std::string name, int health, int attack)
    : name(name), health(health), attack(attack)
{
}

std::string Dinosaur::getName() const
{
    return name;
}

int Dinosaur::getHealth() const
{
    return health;
}

int Dinosaur::getAttack() const
{
    return attack;
}

void Dinosaur::takeDamage(int damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0;
    }
    // Add logic for when dinosaur's health reaches 0, if needed
}
