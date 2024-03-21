#ifndef POSITION_H
#define POSITION_H

class Position{
    public:
        Position(int=0, int=0);
        bool equals(Position*);
        void set(int,int); 
        int getRow();
        int getCol();

    private:
        int row;
        int col;
};
#endif