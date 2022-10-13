/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: image
*/

#ifndef IMAGE_H
#define IMAGE_H

#include "../utils/log.h"
#include "../includes.h"
#include "../drawing/drawing.h"

struct s_image
{
    int width;
    int height;
    char **data;
};

char mirrorChar(char c);
void flipImage(struct s_image *image);
void drawXYImage(struct s_image image, int x, int y, int empty);
struct s_image readImage(char* filename);
void deleteImage(struct s_image* image);

#endif