#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include "Pit.h"

class Participant{
    public:
        Participant(char, int, int);
        virtual ~Participant();
        virtual void move(Pit*) = 0;
        virtual void incurDamage(Participant*) = 0;
        virtual int causeDamage() = 0;
        bool collide(Participant*);
        char getAvatar();
        int getRow();
        int getCol();
        bool isDead();
        bool isSafe();

    protected:
        char avatar;
        bool dead;
        Position* pos;
};
#endif