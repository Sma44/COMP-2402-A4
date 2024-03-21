#include "Hero.h"

Hero::Hero(char ava, int row, int col, string n) 
: Participant(ava, row, col), name(n), health(MAX_HEALTH) {}

void Hero::move(Pit* p) {
  if (isDead() || isSafe()){ return; }
  int ranNum = random(2);

  if (p->underLedge(pos)){
    if (ranNum == LEFT){
      if (p->validPos(pos->getRow(), pos->getCol()-1)){
        pos->set(pos->getRow(), pos->getCol()-1);
      }
      return;
    }
    else{
      if (p->validPos(pos->getRow(), pos->getCol()+1)){
        pos->set(pos->getRow(), pos->getCol()+1);
      }
    }
    return;
  }

  ranNum = random(10);
  int ranDir = random(5);
  int rowOffset = 0;
  int colOffset = 0;

  switch (ranNum) {
  case 0: case 1: case 2: case 3: case 4:
    rowOffset = -1;
    break;
  
  case 5:
    rowOffset = -2;
    break;
  
  case 6: case 7: case 8: case 9:
    rowOffset = 1;
    break;
  
  default:
    break;
  }

  switch (ranDir) {
  case 0:
    colOffset = -2;
    break;
  case 1:
    colOffset = -1;
    break;
  case 2:
    break;
  case 3:
    colOffset = 1;
    break;
  case 4:
    colOffset = 2;
    break;
  default:
    break;
  }

  if (p->validPos(pos->getRow() + rowOffset, pos->getCol() + colOffset)){
    pos->set(pos->getRow() + rowOffset, pos->getCol() + colOffset);
  }

} 

void Hero::incurDamage(Participant* p) {
  health -= p->causeDamage();
  if (health < 1){
    health = 0;
    avatar = '+';
    dead = true;
  }
}

int Hero::causeDamage() { return 0; }
int Hero::getHealth() { return health; }
string Hero::getName() { return name; }