/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: Drawing functions
*/

#ifndef DRAWING_H
#define DRAWING_H

#include "../objects/histogram.h"
#include "../objects/image.h"
#include "../utils/log.h"
#include "../includes.h"

// Functions declaration

void clearScreen();
void setCursorPosition(int x, int y);
void resetCursorPosition();
void resetCursorColorsAndType();
void changeCursorForegroundColor(char* color);
void changeCursorBackgroundColor(char* color);
void changeCursorType(char* type);
void drawXYRectangle(int width, int height, char symbol, int x, int y);
void drawText(char* text);
void drawXYText(char* text, int x, int y);
int getCenteredTextStart(char* text);
void drawCenteredText (char* text, int y);


#endif