/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: Histrogram
*/

#include "histogram.h"

// Decrement bin by value
void decrementBin(int binNumber, int value, struct s_histogram* histogram){
    // Check if bin exists
    if(binNumber > histogram->numberOfBins){
        return;
    }
    else{
        // Check if bin is empty
        if(histogram->bins[binNumber] > 0){
            histogram->bins[binNumber] -= value;
        }
        else{
            return;
        }
    }
}

// Clear bin
void clearBin(int binNumber, struct s_histogram* histogram){
    // Check if bin exists
    if(binNumber > histogram->numberOfBins){
        return;
    }
    else{
        histogram->bins[binNumber] = 0;
    }
}

// Check if histogram is enty
int isEmpty(struct s_histogram histogram){
    int i;
    int isEmpty = 1;
    // For each bin, check if > 0. If yes, return 0 as it's not empty.
    for(i = 0; i < histogram.numberOfBins; i++){
        if(histogram.bins[i] > 0){
            isEmpty = 0;
        }
    }
    return isEmpty;
}

// Draw histogram
void drawXYHistogram(struct s_histogram histogram, int x, int y){
    int binSize;
    int bin;
    int element;

    // Search the bin size
    binSize = (SCREEN_WIDTH - 2) / (histogram.numberOfBins);

    // Draw each element of each bin.

    for (bin = 0; bin < histogram.numberOfBins; bin++){
        for(element = histogram.bins[bin]; element > 0; element--){
            // Draw rectangle.
            drawXYRectangle(binSize, BOX_HEIGHT, histogram.displayCharacter, x + binSize * bin, y - element * BOX_HEIGHT);
        }
    }
}

// generate histogram

struct s_histogram generateHistogram(int numberOfBins, int maxValue, char displayCharacter){
    // Initializing the histogram's values
    struct s_histogram histogram;
    histogram.numberOfBins = numberOfBins;
    histogram.bins = malloc(numberOfBins * sizeof(int));
    histogram.displayCharacter = displayCharacter;

    // For each bin, set its value.
    int i;
    // First bin = 0
    histogram.bins[0] = 0;
    for (i = 1; i < numberOfBins-1; i++){
        // random value between 0 and maxValue
        histogram.bins[i] = rand() % maxValue;
    }
    // Last bin = 0
    histogram.bins[numberOfBins-1] = 0;

    return histogram;
}

// Delete the histogram
void deleteHistogram(struct s_histogram histogram){
    free(histogram.bins);
    histogram.bins = NULL;
}

// Check if there's an intersection with the histogram
int XYIntersectHistogram (int x, int y, struct s_histogram histogram){
    int bin;
    int binSize;
    binSize = (SCREEN_WIDTH - 2) / histogram.numberOfBins;
    bin = (x - 2) / binSize;
    if ((SCREEN_HEIGHT - histogram.bins[bin]*BOX_HEIGHT) <= y){
        return bin;
    }
    else{
        return -1;
    }
}