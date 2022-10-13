/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: Options
*/

#ifndef OPTIONS_H
#define OPTIONS_H

#include "log.h"
#include <stdlib.h>
#include "../includes.h"

struct s_options{
    int difficulty;
    int planeType;
    int powerup;
    int colors;
    char name[MAX_STRING_SIZE];
    int run;
    int quit;
    int help;
};


// Functions declaration
struct s_options getDefaultOptions ();



#endif