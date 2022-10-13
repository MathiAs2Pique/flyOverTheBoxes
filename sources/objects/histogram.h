/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: histrogram
*/

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "../utils/log.h"
#include "../includes.h"
#include "../drawing/drawing.h"

struct s_histogram{
    int numberOfBins;
    int *bins;
    char displayCharacter;
};

void decrementBin(int binNumber, int value, struct s_histogram* histogram);
void clearBin(int binNumber, struct s_histogram* histogram);
int isEmpty(struct s_histogram histogram);
void drawXYHistogram(struct s_histogram histogram, int x, int y);
struct s_histogram generateHistogram(int numberOfBins, int maxValue, char displayCharacter);
void deleteHistogram(struct s_histogram histogram);
int XYIntersectHistogram (int x, int y, struct s_histogram histogram);

#endif