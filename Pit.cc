#include "Pit.h"
#include "PartArray.h"
#include "Hero.h"

Pit::Pit(const char l[MAX_ROW+1][MAX_COL+1]) {
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

bool Pit::underLedge(Position* p) {
    if (withinBounds(p->getRow()-1, p->getCol())){
        return (!validPos(p->getRow()-1, p->getCol()));
    }
    return false;
}

void Pit::print(PartArray* part, Hero* h1, Hero* h2) {
    char tempLayout[MAX_ROW+1][MAX_COL+1];

    for (int i = 0; i < MAX_ROW+1; i++){
        for (int j = 0; j < MAX_COL+1; j++){
           tempLayout[i][j] = layout[i][j];
        }
    }

    for (int i = 0; i < part->getSize(); i++){
        int r = part->get(i)->getRow();
        int c = part->get(i)->getCol();
        tempLayout[r][c] = part->get(i)->getAvatar();
    }

    for (int i = 0; i < MAX_ROW-2; i++){
        for (int j = 0; j < MAX_COL+1; j++){
           cout << tempLayout[i][j];
        }
        cout << endl;
    }

    for (int j = 0; j < MAX_COL+1; j++){
        cout << tempLayout[MAX_ROW-2][j];
    }

    cout << setw(5) << " " << setw(6) << left << h1->getName() << ":  "
         << h1->getHealth() << endl;

    for (int j = 0; j < MAX_COL+1; j++){
        cout << tempLayout[MAX_ROW-1][j];
    }

    cout << setw(5) << " " << setw(6) << left << h2->getName() << ":  "
         << h2->getHealth() << endl;

}