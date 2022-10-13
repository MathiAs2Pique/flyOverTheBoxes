/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: Drawing functions
*/

#include "drawing.h"

// ========== Functions

// Clear screen
void clearScreen(){
    printf("\x1b[2J");
}

// Set cursor position
void setCursorPosition(int x, int y){
    printf("\x1b[%d;%dH", y, x);
}

// Reset cursor position
void resetCursorPosition(){
    setCursorPosition(0, 0);
}

// Reset cursor colors and type
void resetCursorColorsAndType(){
    changeCursorType("reset");
    changeCursorForegroundColor("white");
    changeCursorBackgroundColor("black");
}

// Change cursor foreground color
void changeCursorForegroundColor(char* color){
    int colorCode = -1;
    
    // Check color param
    if(strcmp(color, "black") == 0){
        colorCode = 30;
    }
    else if(strcmp(color, "red") == 0){
        colorCode = 31;
    }
    else if(strcmp(color, "green") == 0){
        colorCode = 32;
    }
    else if(strcmp(color, "yellow") == 0){
        colorCode = 33;
    }
    else if(strcmp(color, "blue") == 0){
        colorCode = 34;
    }
    else if(strcmp(color, "magenta") == 0){
        colorCode = 35;
    }
    else if(strcmp(color, "cyan") == 0){
        colorCode = 36;
    }
    else if(strcmp(color, "white") == 0){
        colorCode = 37;
    }

    // If color is valid
    if(colorCode != -1){
        // Set the foreground color.
        printf("\x1b[%dm", colorCode);
    }
}

// Change cursor background color
void changeCursorBackgroundColor(char* color){
    int colorCode = -1;
    
    // Check color param
    if(strcmp(color, "black") == 0){
        colorCode = 40;
    }
    else if(strcmp(color, "red") == 0){
        colorCode = 41;
    }
    else if(strcmp(color, "green") == 0){
        colorCode = 42;
    }
    else if(strcmp(color, "yellow") == 0){
        colorCode = 43;
    }
    else if(strcmp(color, "blue") == 0){
        colorCode = 44;
    }
    else if(strcmp(color, "magenta") == 0){
        colorCode = 45;
    }
    else if(strcmp(color, "cyan") == 0){
        colorCode = 46;
    }
    else if(strcmp(color, "white") == 0){
        colorCode = 47;
    }

    // If color is valid
    if(colorCode != -1){
        // Set the background color.
        printf("\x1b[%dm", colorCode);
    }
}

// Change cursor type
void changeCursorType(char* type){
    int typeCode = -1;
    
    // Check type param
    if(strcmp(type, "reset") == 0){
        typeCode = 0;
    }
    else if(strcmp(type, "bright") == 0){
        typeCode = 1;
    }
    else if(strcmp(type, "dim") == 0){
        typeCode = 2;
    }
    else if(strcmp(type, "underscore") == 0){
        typeCode = 4;
    }
    else if(strcmp(type, "blink") == 0){
        typeCode = 5;
    }
    else if(strcmp(type, "reverse") == 0){
        typeCode = 7;
    }
    else if(strcmp(type, "hidden") == 0){
        typeCode = 8;
    }
    // If type is valid
    if(typeCode != -1){
        // Set the type.
        printf("\x1b[%dm", typeCode);
    }
}

// Draw a 2D rectangle
void drawXYRectangle (int width, int height, char symbol, int x, int y){

    int h;
    int w;
    // We draw the top line.
    setCursorPosition (x, y);

    for (w = 0; w < width; w++)
        printf ("%c", symbol);

    // We draw the left and right lines.
    for (h = 1; h <= height - 2; h++)
    {
        setCursorPosition (x, y + h);
        printf ("%c", symbol);
        for (w = 2; w <= width - 1; w++)
            printf (" ");
        printf ("%c\n", symbol);
    }

    // We draw the bottom line.
    setCursorPosition (x, y + height - 1);
    for (w = 0; w < width; w++)
        printf ("%c", symbol);

}

// Draw text (impressionnant!)
void drawText(char* text){
    printf("%s", text);
}

// Draw text to a specific position
void drawXYText(char* text, int x, int y){
    setCursorPosition(x, y);
    drawText(text);
}
// Get x coord of a text to center it.
int getCenteredTextStart(char* text){
    return ( SCREEN_WIDTH  - strlen(text)) / 2;
}

// Draw a centered (x) text.
void drawCenteredText (char* text, int y){
    // Get x coord
    int x = getCenteredTextStart(text);
    // Draw text
    drawXYText(text, x, y);
}