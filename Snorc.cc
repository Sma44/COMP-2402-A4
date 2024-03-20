#include "Snorc.h"
#include "random.cc"

#define MAX_CLIMB MAX_ROW - 7
#define FORWARD 1

Snorc::Snorc(int row, int col, int str)
: Participant('s',row,col), strength(str) {}

void Snorc::move(Pit* p) {
  int randNum = random(1);
  int randDir = random(2);
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
  
  if (pos->getRow() != MAX_CLIMB) {
    if (randNum == FORWARD){
      if (p->withinBounds(pos->getRow()-1,pos->getCol())){
        pos->set(pos->getRow()-1,pos->getCol());
      }
    }else{
      if (p->withinBounds(pos->getRow()+1,pos->getCol())){
        pos->set(pos->getRow()+1,pos->getCol());
      }
    }
  }

  if (p->withinBounds(pos->getRow(),pos->getCol() + colOffset)){
    pos->set(pos->getRow(),pos->getCol() + colOffset);
  }
}

void Snorc::incurDamage(Participant* p) {}
int Snorc::causeDamage() { return strength; }

