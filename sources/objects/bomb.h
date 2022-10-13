/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: Bomb
*/

#ifndef BOMB_H
#define BOMB_H

#include "../drawing/drawing.h"
#include "../utils/options.h"
#include "../includes.h"

struct s_bomb{
    float x;
    float y;
    float speed;
    int isPowerup;
    char character;
    int isActive;
};

struct s_bomb initializeBomb (int isPowerup, int x, int y, struct s_options options, int level);
void drawBomb (struct s_bomb bomb, int clear, struct s_options options);
void updateBombPosition (struct s_bomb* bomb);

#endif