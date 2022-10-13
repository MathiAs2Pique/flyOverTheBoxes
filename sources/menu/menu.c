/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: Menu
*/

#include "menu.h"

void displayDifficultyOption(int difficulty, int y){
    int x;

    // Set txt pos
    x = getCenteredTextStart("Difficulty: 1 - 2 - 3");
    setCursorPosition(x, y);

    // Display txt

    drawText("Difficulty: ");
    if(difficulty == 1) {
        changeCursorType("reverse");
        drawText("1");
        resetCursorColorsAndType();
        drawText(" - 2 - 3");
    }
    if(difficulty == 2) {
        drawText("1 - ");
        changeCursorType("reverse");
        drawText("2");
        resetCursorColorsAndType();
        drawText(" - 3");
    }
    if(difficulty == 3) {
        drawText("1 - 2 - ");
        changeCursorType("reverse");
        drawText("3");
        resetCursorColorsAndType();
    }

}


void displayPlaneTypeOption(int planeType, int y){
    int x;

    // Set txt pos
    x = getCenteredTextStart("Plane type: 1 - 2");
    setCursorPosition(x, y);

    // Display txt

    drawText("Plane type: ");
    switch(planeType){
        case 1:
            changeCursorType("reverse");
            drawText("1");
            resetCursorColorsAndType();
            drawText(" - 2");
            break;
        case 2:
            drawText("1 - ");
            changeCursorType("reverse");
            drawText("2");
            resetCursorColorsAndType();
            break;
    }
}

void displayPowerupOption (int powerup, int y){
    int x;
    x = getCenteredTextStart("Powerup: Yes - No");
    setCursorPosition(x, y);

    if(powerup){
        drawText("Powerup: ");
        changeCursorType("reverse");
        drawText("Yes");
        resetCursorColorsAndType();
        drawText(" - No");
    }
    else{
        drawText("Powerup: Yes - ");
        changeCursorType("reverse");
        drawText("No");
        resetCursorColorsAndType();
    }
}

void displayColorsOptions (int powerup, int y){
    int x;
    x = getCenteredTextStart("Colors: Yes - No");
    setCursorPosition(x, y);

    if(powerup){
        drawText("Colors: ");
        changeCursorType("reverse");
        drawText("Yes");
        resetCursorColorsAndType();
        drawText(" - No");
    }
    else{
        drawText("Colors: Yes - ");
        changeCursorType("reverse");
        drawText("No");
        resetCursorColorsAndType();
    }
}

void displayNameOption(char* name, int y){
    int x;
    char fullText[MAX_STRING_SIZE];

    sprintf(fullText, "Name: %s", name);
    x = getCenteredTextStart(fullText);
    setCursorPosition(x, y);

    // Display txt
    drawText(fullText);
}

void displayHelp(){

    // Just display help strings

    drawXYText("Help:", 2, SCREEN_HEIGHT +2);
    drawXYText("------:", 2, SCREEN_HEIGHT +3);
    drawXYText("set difficulty 1|2|3 -> change difficulty", 2, SCREEN_HEIGHT +4);
    drawXYText("set planetype 1|2 -> change plane type", 2, SCREEN_HEIGHT +5);
    drawXYText("set powerup|colors yes|no -> change the powerup/colors", 2, SCREEN_HEIGHT +6);
    drawXYText("set name your_name -> edit your name", 2, SCREEN_HEIGHT +7);
    drawXYText("run -> run the game", 2, SCREEN_HEIGHT +8);
    drawXYText("quit -> quit the game", 2, SCREEN_HEIGHT +9);
    drawXYText("help -> show/hide this menu", 2, SCREEN_HEIGHT +10);

}

void displayMenu(struct s_options* options){
    // Load logo image.
    struct s_image logo;
    logo = readImage(LOGO_FILE);

    // while no quit / run instruction
    while(!options->quit && !options->run){
        // Clear screen
        clearScreen();
        // Reset color / cursor type
        resetCursorColorsAndType();
        // Display rectangle around menu
        drawXYRectangle(SCREEN_WIDTH, SCREEN_HEIGHT, BORDER_CHAR, 1, 1);

        // Draw logo picture
        changeCursorType("blink");
        int logox = (SCREEN_WIDTH / 2 ) - (logo.width / 2);
        int logoy = 4;
        drawXYImage(logo, logox, logoy, 0);
        resetCursorColorsAndType();

        // Display difficulty, plane type, powerup, colors and Name
        displayDifficultyOption(options->difficulty, logo.height + 6);
        displayPlaneTypeOption(options->planeType, logo.height + 7);
        displayPowerupOption(options->powerup, logo.height + 8);
        displayColorsOptions(options->colors, logo.height + 9);
        displayNameOption(options->name, logo.height + 10);
        // Display help if needed
        if(options->help){
            displayHelp();
        }
        // Display prompt
        drawXYText("Enter a command >  ", 1, SCREEN_HEIGHT -1);
        // Get user input
        char userCommand[MAX_STRING_SIZE];
        fgets(userCommand, MAX_STRING_SIZE, stdin);
        // Parse user input
        parseUserCommand(userCommand, options);
    }
}