#include "Participant.h"

// TODO: might not work with this
Participant::Participant(char ava, int row, int col) 
: avatar(ava), pos(new Position(row,col)) {}

Participant::~Participant() { delete pos; }

bool Participant::collide(Participant* part) {
    return (pos->getCol() == part->getCol() && pos->getRow() == part->getRow()) ? true : false;
}

// TODO: might be row 0, or 1, not sure
bool Participant::isSafe() {
    return (pos->getRow() == 1) ? true : false;
}

int Participant::getRow() { return pos->getRow(); }
int Participant::getCol() { return pos->getCol(); }
char Participant::getAvatar() { return avatar; }
bool Participant::isDead() { return dead; }