/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: game handler
*/

#ifndef GAME_H
#define GAME_H

#include "../drawing/drawing.h"
#include "../objects/image.h"
#include "../objects/bomb.h"
#include "../objects/plane.h"
#include "../objects/histogram.h"
#include "../utils/log.h"
#include "../utils/options.h"
#include "../scores/scores.h"
#include "../includes.h"
#include <unistd.h>

int waitInput(int timeout);
void drawBackground(struct s_histogram histogram, struct s_options options, int level, int score);
int checkBombCrash (struct s_bomb* bomb, struct s_histogram histogram, struct s_options option);
int checkPlaneCrash(struct s_plane* plane, struct s_histogram histogram);
void runGame(struct s_options options);

#endif