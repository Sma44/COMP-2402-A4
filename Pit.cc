#include <iostream>
#include "Pit.h"
//#include "PartArray.h"
//#include "Hero.h"

Pit::Pit(char l[MAX_ROW+1][MAX_COL+1]) {
    for (int i = 0; i < MAX_ROW+1; i++){
        for (int j = 0; j < MAX_COL+1; j++){
            layout[i][j] = l[i][j];
        }
    }
}

bool Pit::withinBounds(int row, int col) {
    return (row < 0 || row > MAX_ROW || col < 0 || col > MAX_COL) ? false : true;
}

bool Pit::validPos(int row, int col) {
    if (withinBounds(row,col)){
        return (layout[row][col] == '-') ? false : true;
    }
    return false;
}

// since rows are stored top to bottom, -1 to row to see above pos
bool Pit::underLedge(Position* p) {
    if (withinBounds(p->getRow()-1, p->getCol())){
        return (!validPos(p->getRow()-1, p->getCol()));
    }
    return false;
}

// void Pit::print(PartArray* part, Hero* h1, hero* h2) {
//      char tempLayout[MAX_ROW+1][MAX_COL+1];
//      for (int i = 0; i < MAX_ROW+1; i++){
//          for (int j = 0; j < MAX_COL+1; j++){
//             tempLayout[i][j] = layout[i][j];
//          }
//      }
// }