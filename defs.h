#ifndef DEFS_H
#define DEFS_H

#include <iostream>
#include <string>
#include <iomanip>
#include <unistd.h>
#include <time.h>
using namespace std;

#define MAX_ROW       20
#define MAX_COL       25
#define MAX_HEALTH    20
#define MAX_ARR      256

#define SNORC_SPAWN   90
#define MAX_SNORCS    12

int random(int);

#endif

// both heroes and snorcs dynamic allocation stored in the same collection, no order in collection
// game loops until both die or either escapes
// start with no snorcs. 90% chance a new snorc spawns, max 12. starts at random row in the bottom 5 rows and column
// random strenght between 2 and 4 inclusive

// on each itr, a new posiution is computed polymorphically based on random values, in 3.4, and position updated
// anything greater or less than bounds of board set to closest value.
// once postion updated, must check with every participant for collision. both occcupy same row and column.
// if occured deal with it polymophically, two heroes or two snorcs, nothing happens, else deal damage to health based on damage
// at end of itr, pit is printed. both health updated and printed
// once done, print both healths and names on screen, print outcome
 