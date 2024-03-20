#ifndef POSITION_H
#define POSITION_H

// function using this must do validation
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