#include "Escape.h"

Escape::Escape() {
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

  numSnorcs = 0;

  srand( (unsigned)time( NULL ) );
  int col1 = random(10) + LEFT_BOUND;
  int col2 = random(10) + LEFT_BOUND;
  while (col2 == col1){
    col2 = random(10) + LEFT_BOUND;
  }

  h1 = new Hero('T', MAX_ROW-2, col1, "Timmy");
  h2 = new Hero('H', MAX_ROW-2, col2, "Harold");

  arr.add(h1);
  arr.add(h2);

  pit = new Pit(templateGrid);
}

Escape::~Escape() {
  delete pit;
}

void Escape::runEscape() {
  bool flag = false;
  int spawn;
  while(!flag){
    usleep(200000);
    spawn = random(SNORC_SPAWN + NO_SPAWN);
    if(spawn < SNORC_SPAWN){
      spawnSnorc();
    }

    moveParticipants();
    flag = isOver();

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
  return ((h1->isDead() || h1->isSafe()) && (h2->isDead() || h2->isSafe()));
}

void Escape::spawnSnorc() {
  if (numSnorcs == MAX_SNORCS) { return; }

  int col = random(MAX_COL);
  int row = random(6) + MAX_HEIGHT;
  int str = random(3) + MIN_STRENGTH;

  arr.add(new Snorc(row, col, str));
  numSnorcs++;
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