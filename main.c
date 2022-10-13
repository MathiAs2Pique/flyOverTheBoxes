// Project: FlyOverBoxes

// Includes
#include "sources/drawing/drawing.h"
#include "sources/objects/bomb.h"
#include "sources/objects/histogram.h"
#include "sources/objects/image.h"
#include "sources/objects/plane.h"
#include "sources/utils/log.h"
#include "sources/utils/options.h"
#include "sources/includes.h"
#include "sources/game/game.h"
#include "sources/menu/menu.h"

// Entry point.
int main ()
{
    struct s_options options;

    // initialize options
    options = getDefaultOptions ();

    // display menu
    do
    {
        displayMenu (&options);
        if (options.run){
            runGame (options);
        }
    }
    while (!options.quit);
    return EXIT_SUCCESS;
}