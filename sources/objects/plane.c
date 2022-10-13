/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: plane
*/
#include "plane.h"

// Draw a plane
void drawPlane (struct s_plane plane, int clear, struct s_options options){
    // Change color to blue
    if(options.colors){
        changeCursorForegroundColor("blue");
    }
    // Draw plane
    drawXYImage(plane.image, plane.x, plane.y, clear);
    resetCursorColorsAndType();
}

// Update plane position
void updatePlanePosition (struct s_plane* plane){
    // Update plane position
    plane->x += plane->orientation * plane->speed;

    // Check if we need to decrement y 
    if(plane->x >= (SCREEN_WIDTH - 1 - plane->image.width) || plane->x <= 2){
        plane->y = plane->y + 2;
        flipImage(&plane->image);
        plane->orientation = -plane->orientation;
    }
}

struct s_plane initializePlane (struct s_options options, int level){
    struct s_plane plane;

    // Plane type
    if(options.planeType == 1){
        // Read image
        plane.image = readImage(PLANE1_FILE);
    }
    if(options.planeType == 2){
        // Read image
        plane.image = readImage(PLANE2_FILE);
    }

    // Init: flip image.
    flipImage(&plane.image);

    // Default pos & speed
    plane.x = PLANE_X;
    plane.y = PLANE_Y;
    plane.orientation = 1;
    plane.speed = 1.0 + (float)level / 2;


    return plane;
}