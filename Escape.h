#ifndef ESCAPE_H
#define ESCAPE_H

#include "PartArray.h"
#include "Pit.h"
#include "Hero.h"
#include "Snorc.h"

class Escape
{
  public:
    Escape();
    ~Escape();
    void runEscape();

  private:
    int numSnorcs;
    PartArray arr;
    Pit* pit;
    Hero* h1;
    Hero* h2;
    void spawnSnorc();
    void moveParticipants();
    Participant* checkForCollision(Participant*);
    bool isOver();
    void printOutcome();
};
#endif

