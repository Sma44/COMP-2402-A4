#ifndef SNORC_H
#define SNORC_H

#include "Participant.h"

class Snorc : public Participant {
  public:
    Snorc(int, int, int);
    void move(Pit*);
    void incurDamage(Participant*);
    int causeDamage();

  private:
    int strength;
};
#endif