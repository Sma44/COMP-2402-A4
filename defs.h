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

#define NO_SPAWN      10 
#define MAX_HEROES    2  
#define MAX_HEIGHT    14
#define MIN_STRENGTH  2 
#define LEFT          0
#define MAX_CLIMB     12
#define FORWARD       1
#define LEFT_BOUND    7

int random(int);

#endif

 