/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: Plane
*/

#ifndef PLANE_H
#define PLANE_H

#include "../utils/options.h"
#include "../drawing/drawing.h"
#include "image.h"
#include "../utils/log.h"
#include "../includes.h"

struct s_plane{
    float x;
    float y;
    int orientation;
    float speed;
    struct s_image image;
};

void drawPlane (struct s_plane plane, int clear, struct s_options options);
void updatePlanePosition (struct s_plane* plane);
struct s_plane initializePlane (struct s_options options, int level);

#endif