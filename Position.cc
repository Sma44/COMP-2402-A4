#include "Position.h"

Position::Position(int r, int c) : row(r), col(c) {}

bool Position::equals(Position* p) { 
    return (p->row != row || p->col != col) ? false : true; 
}

void Position::set(int r, int c) {
    row = r;
    col = c;
}

int Position::getCol() { return col; }
int Position::getRow() { return row; }