/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: Bomb
*/

#include "bomb.h"

// Default structure for bomb
// returns a bomb structure.
struct s_bomb initializeBomb (int isPowerup, int x, int y, struct s_options options, int level){
    // Create bomb structure
    struct s_bomb bomb;

    // Initialize bomb variables
    bomb.x = x;
    bomb.y = y;
    bomb.speed = 1.0 + ((float) level/2);
    bomb.isPowerup = isPowerup;
    if(isPowerup){
        bomb.character = '!';
    }
    else{
        bomb.character = '*';
    }

    bomb.isActive = 1;
    
    return bomb;
}

// Draw bomb
void drawBomb (struct s_bomb bomb, int clear, struct s_options options){
    char buffer[8];

    // Check bomb's active state
    if(!(bomb.isActive)){
        return;
    }
    // Check if we need to colorize the bomb.
    if(options.colors){
        changeCursorForegroundColor("blue");
    }

    // We draw the bomb
    sprintf(buffer, "%c\n", bomb.character);

    // Check if we need to clear the bomb.
    if(clear){
        drawXYText(" \n", bomb.x, bomb.y);
    }
    else{
        drawXYText(buffer, bomb.x, bomb.y);
    }
    resetCursorColorsAndType();
}

// Move bomb
void updateBombPosition (struct s_bomb* bomb){
    // Decrease bomb's y position
    bomb->y = bomb->y + 0.5*bomb->speed;

    // Check if bomb is out of screen
    if(bomb->y >= SCREEN_HEIGHT -1){
        bomb->isActive = 0;
    }
}