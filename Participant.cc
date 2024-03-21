#include "Participant.h"

Participant::Participant(char ava, int row, int col) 
: avatar(ava), dead(false), pos(new Position(row,col)) {}

Participant::~Participant() { delete pos; }

bool Participant::collide(Participant* part) {
    return (pos->getCol() == part->getCol() && pos->getRow() == part->getRow()) ? true : false;
}

bool Participant::isSafe() {
    bool ret = (pos->getRow() == 1) ? true : false;
    if (ret){
        avatar = ' ';
    }
    return ret;
}

int Participant::getRow() { return pos->getRow(); }
int Participant::getCol() { return pos->getCol(); }
char Participant::getAvatar() { return avatar; }
bool Participant::isDead() { return dead; }