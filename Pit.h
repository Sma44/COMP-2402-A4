#ifndef PIT_H
#define PIT_H

#include "defs.h"
#include "Position.h"

// forward references
class PartArray; 
class Hero;

class Pit{
    public:
        Pit(char[MAX_ROW+1][MAX_COL+1]); // maybe? donno if this works. the assignment operator cannot be used to copy entire arrays.
        bool validPos(int, int);
        bool withinBounds(int,int);
        bool underLedge(Position*);
        void print(PartArray*, Hero*, Hero*);

    private:
        char layout[MAX_ROW+1][MAX_COL+1];
        
};
#endif