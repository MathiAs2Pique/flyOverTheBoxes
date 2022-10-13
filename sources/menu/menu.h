/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: Menu
*/

#ifndef MENU_H
#define MENU_H

#include "../drawing/drawing.h"
#include "../objects/image.h"
#include "../utils/log.h"
#include "../utils/options.h"
#include "../utils/commandParsing.h"
#include "../includes.h"

void displayDifficultyOption(int difficulty, int y);
void displayPlaneTypeOption(int planeType, int y);
void displayPowerupOption(int powerup, int y);
void displayColorsOption(int colors, int y);
void displayNameOption(char* name, int y);
void displayHelp();
void displayMenu(struct s_options* options);

#endif