/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: options
*/
#include "options.h"

// ========= Functions


// Get default options.
struct s_options getDefaultOptions () {
    struct s_options options;

    // Init options
    options.difficulty = DEFAULT_DIFFICULTY;
    options.planeType = DEFAULT_PLANETYPE;
    options.powerup = DEFAULT_POWERUP;
    options.colors = DEFAULT_COLORS;
    strcpy(options.name, DEFAULT_NAME);
    options.run = 0;
    options.quit = 0;
    options.help = DEFAULT_HELP;

    return options;
}