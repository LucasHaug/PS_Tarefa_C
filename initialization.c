/**
 * @file initialization.c
 *
 * @brief Initialization functions.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 *
 * @date 03/2019
 */

#include "initialization.h"
#include "dojo.h"
#include "robot.h"
#include "movement.h"

/*****************************************
 * Public Functions Bodies Definitions
 *****************************************/

void initialization() {
    clean_dojo();

    set_orientation(ROZETA, UPWARD);
    print_robot(ROZETA, rozeta_line, rozeta_column);

    print_dojo();
}

void set_oponent_position(uint8_t position) {
    if (position == 0) {
        oponent_line = DOJO_LINES - ROBOT_LINES;
        oponent_column = 0;
    } else if (position == 1) {
        oponent_line = 0;
        oponent_column = 0;
    } else if (position == 2) {
        oponent_line = 0;
        oponent_column = (DOJO_COLUMNS - ROBOT_COLUMNS)/2;
    } else if (position == 3) {
        oponent_line = 0;
        oponent_column = DOJO_COLUMNS - ROBOT_COLUMNS;
    } else /*if (position == 4)*/ {
        oponent_line = DOJO_LINES - ROBOT_LINES;
        oponent_column = DOJO_COLUMNS - ROBOT_COLUMNS;
    }

    set_orientation(OPONENT, DOWNWARD);
    print_robot(OPONENT, oponent_line, oponent_column);
}
