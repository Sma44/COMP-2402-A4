#include "Snorc.h"

Snorc::Snorc(int row, int col, int str)
: Participant('s',row,col), strength(str) {}

void Snorc::move(Pit* p) {
  int randNum = random(2);
  int randDir = random(3);
  int colOffset = 0;
  
  switch (randDir) {
  case 0:
    colOffset = -1;
    break;
  case 1:
    break;
  case 2:
    colOffset = 1;
    break;  
  default:
    break;
  }
  
  
  if (randNum == FORWARD){
    if (pos->getRow() > MAX_CLIMB) {
      if (p->withinBounds(pos->getRow()-1,pos->getCol())){
        pos->set(pos->getRow()-1,pos->getCol());
      }
    }
  }
  else{
    if (p->withinBounds(pos->getRow()+1,pos->getCol())){
      pos->set(pos->getRow()+1,pos->getCol());
    }
  }


  if (p->withinBounds(pos->getRow(),pos->getCol() + colOffset)){
    pos->set(pos->getRow(),pos->getCol() + colOffset);
  }
}

void Snorc::incurDamage(Participant* p) {}
int Snorc::causeDamage() { return strength; }

