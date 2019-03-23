/**
 * @file strategies.c
 *
 * @brief Strategies functions.
 *
 * @author Lucas Haug <lucas.haug@thunderatz.org>
 *
 * @date 03/2019
 */

#include "strategies.h"
#include "movement.h"

/*****************************************
 * Public Variables Definitions
 *****************************************/

int sensor_position = 0;

/*****************************************
 * Public Functions Bodies Definitions
 *****************************************/

void strategie_one() {
    set_speed(3);
    if (sensor_position == 2) {
        while(rozeta_line - 1 > oponent_line){
            move_up();
        }
    }
}