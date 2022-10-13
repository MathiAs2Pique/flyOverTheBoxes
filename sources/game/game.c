/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: game handler
*/

#include "game.h"


int waitInput(int timeout){
    struct timeval waitingTime;
    fd_set descriptorSet;
    int input = 0;

    // Setup input param and timeout
    FD_ZERO(&descriptorSet);
    FD_SET(0, &descriptorSet);
    waitingTime.tv_sec = 0;
    waitingTime.tv_usec = timeout;

    // Wait for user input

    if(select(1, &descriptorSet, NULL, NULL, &waitingTime) != 0){
        fgetc(stdin);
        input = 1;
    }

    // Wait remaining time (if input)
    usleep(waitingTime.tv_usec);

    return input;
}

void drawBackground(struct s_histogram histogram, struct s_options options, int level, int score){
    // Init: reset cursor and clean screen.
    resetCursorColorsAndType();
    clearScreen();

    // Draw frame border.
    if(options.colors){
        changeCursorForegroundColor("blue");
    }
    drawXYRectangle(SCREEN_WIDTH, SCREEN_HEIGHT, BORDER_CHAR, 1, 1);
    resetCursorColorsAndType();

    // Draw histogram
    if(options.colors){
        changeCursorForegroundColor("magenta");
    }
    drawXYHistogram(histogram, 2, SCREEN_HEIGHT);
    resetCursorColorsAndType();

    // Draw name
    if(options.colors){
        changeCursorForegroundColor("red");
    }
    drawXYText(options.name, 3, 2);
    resetCursorColorsAndType();

    // Draw score
    char *text_s = malloc(sizeof(char[MAX_STRING_SIZE]));
    sprintf(text_s, "%d\n", score);
    int text_sx = SCREEN_WIDTH - strlen(text_s);
    int text_sy = 2;
    drawXYText(text_s, text_sx, text_sy);

    // Draw level
    char *text_l = malloc(sizeof(char[MAX_STRING_SIZE]));
    sprintf(text_l, "level %d\n", level);
    int text_lx = SCREEN_WIDTH - strlen(text_l);
    int text_ly = 3;
    drawXYText(text_l, text_lx, text_ly);
}

int checkBombCrash (struct s_bomb* bomb, struct s_histogram histogram, struct s_options option){
    if(!bomb->isActive){
        return 0;
    }

    // Check if bomb touch histogram.
    int binNumber =  XYIntersectHistogram(bomb->x, bomb->y, histogram);
    if(binNumber == -1){
        return 0;
    }
    // else
    if(bomb->isPowerup){
        // Powerup : delete the whole bin
        histogram.bins[binNumber] = 0;
    }
    else{
        // Else : delete one block
        decrementBin(binNumber, 1, &histogram);
    }
    bomb->isActive = 0;

    return 1;
}

int checkPlaneCrash(struct s_plane* plane, struct s_histogram histogram){
    if(plane->orientation){
        if(XYIntersectHistogram(plane->x, plane->y + plane->image.height, histogram) != -1){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        if(XYIntersectHistogram(plane->x + 1, plane->y + plane->image.height, histogram) != -1){
            return 1;
        }
        else{
            return 0;
        }
    }
}


// Fatos
int runLevel(int level, struct s_options options, int* score){
    // Generate histogram
    struct s_histogram histogram;
    if(options.difficulty == 1){
        histogram = generateHistogram(WIDTH_LEVEL1, HEIGHT_LEVEL123, 'I');
    }
    else if(options.difficulty == 2){
        histogram = generateHistogram(WIDTH_LEVEL2,  HEIGHT_LEVEL123, 'I');
    }
    else{
        histogram = generateHistogram(WIDTH_LEVEL3,  HEIGHT_LEVEL123, 'I');
    }

    // Init new plane
    struct s_plane plane;
    plane = initializePlane(options, level);

    // Init bomb
    struct s_bomb bomb;
    bomb.isActive = 0;
    bomb.isPowerup = 0;

    if(options.powerup && (rand()%5) == 1){
        bomb.isPowerup = 1;
    }
    else{
        bomb.isPowerup = 0;
    }

    // Display background
    drawBackground(histogram, options, level, *score);

    // Game loop
    while(1){
        // Display plane
        drawPlane(plane, 0, options);
        drawBomb(bomb, 0, options);

        int timeout = 40000;

        // If bomb is active / requested, display it
        if(waitInput(timeout) == 1 && !bomb.isActive){
            bomb = initializeBomb(bomb.isPowerup, plane.x + plane.image.width/2, plane.y + plane.image.height, options, level);
        }
        // Set the duration beteween 2 frames the same
        else if(bomb.isActive){
            usleep(timeout);
        }

        // Check for collisions
        if(checkBombCrash(&bomb, histogram, options)){
            *score = *score + options.difficulty * (level+1) * BASE_SCORE;
            drawBackground(histogram, options, level, *score);
            if(bomb.isPowerup){
                drawXYText("POWERUP\n", getCenteredTextStart("POWERUP\n"), 3);
            }
        }

        if(checkPlaneCrash(&plane, histogram)){
            return 1;
        }

        if(isEmpty(histogram)){
            return 0;
        }

        // Bomb and plane pos (Clear before update!)

        drawPlane(plane, 1, options);
        updatePlanePosition(&plane);

        if(bomb.isActive){
            drawBomb(bomb, 1, options);
            updateBombPosition(&bomb);
        }

    }
}

void runGame(struct s_options options){
    int score = 0;
    int level = 0;
    int stop;

    while(stop != 1){
        stop = runLevel(level, options, &score);
        level++;
    }
    options.run = 0;
    clearScreen();
    resetCursorPosition();
    printf("GAME OVER\nScore: %d\nLose at level: %d\n", score, level);
    exit(1);
}