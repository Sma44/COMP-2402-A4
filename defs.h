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

#define HERO_SPAWN    2
#define SNORC_HEIGHT  12
#define MIN_STRENGTH  2
#define NO_SPAWN      9
#define LEFT          0
#define RIGHT         3
#define SLOW_CLIMB    5
#define FAST_CLIMB    6
#define MAX_CLIMB (MAX_ROW - 7)
#define FORWARD 1

int random(int);

#endif

 