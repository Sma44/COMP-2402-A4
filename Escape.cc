#include "Escape.h"

Escape::Escape()
{
  const char templateGrid[MAX_ROW+1][MAX_COL+1]={
      "-------------------------",
      "-             --        -",
      "-                      --",
      "-       --              -",
      "                  --    -",
      "--       -              -",
      "---                    --",
      "---       --          ---",
      "--                     --",
      "-            --        --",
      "---               --     ",
      "--        --    ---    --",
      "--  --                  -",
      "--        --       -     ",
      "--                  -    ",
      "--     --         --    -",
      "---                    --",
      "--       ---    --      -",
      "--                     --",
      "-------------------------"
  };

  srand( (unsigned)time( NULL ) );
  int randNum1 = random(20) + HERO_SPAWN;
  int randNum2 = random(20) + HERO_SPAWN;

  h1 = new Hero('T', MAX_ROW-2, randNum1, "Timmy");
  h2 = new Hero('H', MAX_ROW-2, randNum2, "Harold");

  arr.add(h1);
  arr.add(h2);

  pit = new Pit(templateGrid);
}

Escape::~Escape() {
  delete pit;
}

void Escape::runEscape() {
  while(!isOver()){
    usleep(200000);
    int spawn = random(SNORC_SPAWN + NO_SPAWN);
    if(spawn < 90){
      spawnSnorc();
    }

    moveParticipants();

    system("clear");
    pit->print(&arr, h1, h2);
  }
  printOutcome();
}

void Escape::printOutcome(){
  if (h1->isDead() && h2->isDead()){
    cout << "Both Heroes have died." << endl;
  }
  else if(h1->isDead() && h2->isSafe()){
    cout << "Only " << h2->getName() << " survived." << endl;
  }
  else if(h1->isSafe() && h2->isDead()){
    cout << "Only " << h1->getName() << " survived." << endl;
  }
  else{
    cout << "Both Heroes survived." << endl;
  }
  cout << setw(7) << left << h1->getName() << ": " << h1->getHealth() << endl;
  cout << setw(7) << left << h2->getName() << ": " << h2->getHealth() << endl;
}


bool Escape::isOver() {
  return ((h1->isDead() || h1->isSafe()) && (h2->isDead() || h2->isSafe())) ? true : false;
}

void Escape::spawnSnorc() {
  if (arr.getSize() == MAX_SNORCS + 2) { return; }

  int col = random(MAX_COL);
  int row = random(5) + SNORC_HEIGHT;
  int str = random(2) + MIN_STRENGTH;

  arr.add(new Snorc(row, col, str));
}

Participant* Escape::checkForCollision(Participant* p) {
  for (int i = 0; i < arr.getSize(); i++){
    if (arr.get(i)->getCol() == p->getCol() && arr.get(i)->getRow() == p->getRow()){
      return arr.get(i);
    }
  }
  return nullptr;
}

void Escape::moveParticipants() {
  for (int i = 0; i < arr.getSize(); i++){
    arr.get(i)->move(pit);
    Participant* temp = checkForCollision(arr.get(i));
    if (temp != nullptr){
      temp->incurDamage(arr.get(i));
      arr.get(i)->incurDamage(temp);
    }
  }
}