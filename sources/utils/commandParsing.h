/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: Command
*/

#ifndef COMMAND_H
#define COMMAND_H

#include "../includes.h"
#include "options.h"
#include "log.h"

int getNextWord (char* userCommand, char* word);
void replaceNewLineByEndLine (char* userCommand);
void parseUserCommand (char* userCommand, struct s_options* options);

#endif