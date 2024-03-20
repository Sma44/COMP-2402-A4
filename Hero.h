#ifndef HERO_H
#define HERO_H

#include "Participant.h"

class Hero : public Participant {
  public:
    Hero(char, int, int, string);
    void move(Pit*);
    void incurDamage(Participant*);
    int causeDamage();
    int getHealth();
    string getName();

  private:
    string name;
    int health;
};
#endif