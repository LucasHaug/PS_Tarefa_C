#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>
// #include <string.h>

#define MAX_SPACES "                    "
#define MIN_SPACES "          "

#define INITIAL_ROBOT_LINES 6
#define INITIAL_ROZETA_COLUMNS 22

#define ROBOT_LINES 5
#define ROBOT_COLUMNS 19

#define DOJO_LINES (3*ROBOT_LINES)
#define DOJO_COLUMNS (3*ROBOT_COLUMNS)

struct timeval;

static float delay_time = 0.5;

char dojo[DOJO_LINES][DOJO_COLUMNS];

void set_robot_position(uint8_t position);

typedef enum robot {
    ROZETA,
    OPONENT,
} robot_t;

typedef enum orientation {
    UPWARD,
    DOWNWARD,
} orientation_t;

static orientation_t current_rozeta_orientation = UPWARD;
static orientation_t current_oponent_orientation = UPWARD;

void set_orientation(robot_t robot, orientation_t orientation);

char* initial_rozeta[] = {
"                   ",
"    1    2    3    ",
"    ___________    ",
"0  |___________|  4",
"   |     R     |   ",
"  [|___________|]  ",
};

static char* upwards_robot[] = {
"                   ",
"    ___________    ",
"   |___________|   ",
"   |           |   ",
"  [|___________|]  ", 
};

static char* downwards_robot[] = {
"                   ",
"    ___________    ",
"  [|           |]  ",
"   |___________|   ",
"   |___________|   ",
};

void delay(float extra_time);

void set_speed(float speed);

// void imprime_rozeta(robot_t robot, uint8_t dist_x, uint8_t dist_y);

void imprime_robo(robot_t robot, uint8_t dist_x, uint8_t dist_y);

void limpa_dojo();

void imprime_dojo();

static uint8_t rozeta_line = 0;
static uint8_t rozeta_column = 0; 

static uint8_t oponent_line = 0;
static uint8_t oponent_column = 0; 

int main() {
    int sensor_position = 1;

    limpa_dojo();

    printf("Digite a posição do robo: ");
    scanf("%d", &sensor_position);

    // set_robot_position(sensor_position);

    // set_speed(2);

    // int moves = 6;

    // char mov;
    // printf("Iniciar movimento [y/n]: ");
    // scanf(" %c", &mov);

    // switch (mov) {
    //     case 'y': {
    //         break;
    //     }
    //     case 'n':
    //     default: {
    //         printf("Bye bye");
    //         return 0;
    //     }
    // }

    // imprime_robo(ROZETA, UPWARD, 0, 0);
    // printf("\n\n\n");
    // imprime_robo(OPONENT, UPWARD, 0, 0);
    // printf("\n\n\n");
    // invert_orientation(ROZETA);
    set_robot_position(sensor_position);
    // set_orientation(OPONENT, DOWNWARD);
    // imprime_robo(OPONENT, 2, 0);
    // imprime_robo(ROZETA, ROBOT_LINES + 2, 0);
    // printf("\n\n\n");
    // imprime_robo(OPONENT, DOWNWARD, 0, 0);

    // for (int moves = 6; moves > -1; moves--) {
    //     limpa_dojo();
        
    //     for (int i = 0; i < ROBOT_LINES; i++) {
    //         for (int j = 0; j < ROBOT_COLUMNS; j++){
    //             dojo[i][j] = downwards_robot[i][j];
    //         }
    //     }

    //     for (int i = 0; i < ROBOT_LINES; i++) {
    //         for (int j = 0; j < ROBOT_COLUMNS; j++){
    //             dojo[i + ROBOT_LINES + moves][j] = upwards_robot[i][j];
    //         }
    //         // sprintf(dojo[i + ROBOT_LINES + moves], MAX_SPACES "%s", upwards_robot[i]);
    //     }

    //     imprime_dojo();

    //     delay(delay_time);
    // }
        
    // printf("\033[2J\033[H");

    imprime_dojo();

    return 0;
}

void delay(float extra_time) {
    struct timeval tval_before, tval_after, tval_result;
    float real_time;

    gettimeofday(&tval_before, NULL);

    do {
        gettimeofday(&tval_after, NULL);

        timersub(&tval_after, &tval_before, &tval_result);

        real_time = tval_result.tv_sec + tval_result.tv_usec/1000000.0;
    } while (real_time < extra_time);
    
}

void set_speed(float speed) {
    delay_time = 1/speed;
}

// void imprime_upwards_robot(robot_t robo, uint8_t dist_x, uint8_t dist_y) {
//     for (int i = 0; i < 6; i++){
//         printf("%s", upwards_robot[i]);
//         printf(MAX_SPACES); 
//     }
// }

void set_orientation(robot_t robot, orientation_t orientation) {
    switch (robot) {
        case ROZETA: {
            current_rozeta_orientation = orientation;
            break;
        }
        case OPONENT: {
            current_oponent_orientation = orientation;
            break;
        }
    }
}

void imprime_robo(robot_t robot, uint8_t dist_x, uint8_t dist_y) {
    char robot_apearence[ROBOT_LINES][ROBOT_COLUMNS];
    // char* robot_apearence[ROBOT_LINES];

    switch (robot) {
        case ROZETA: {
            switch (current_rozeta_orientation) {
                case UPWARD: {
                    for (int i = 0; i < ROBOT_LINES; i++) {
                        for (int j = 0; j < ROBOT_COLUMNS; j++) {
                           robot_apearence[i][j] = upwards_robot[i][j];
                        }
                     // strcpy(robot_apearence[i], upwards_robot[i]);
                    }
                     // *robot_apearence = &upwards_robot;
                    break;
                }
                case DOWNWARD: {
                    for (int i = 0; i < ROBOT_LINES; i++) {
                        for (int j = 0; j < ROBOT_COLUMNS; j++) {
                            robot_apearence[i][j] = downwards_robot[i][j];
                        }
                        // strcpy(robot_apearence[i], downwards_robot[i]);
                    }
                    // *robot_apearence = &downwards_robot;
                    break;
                }
            }
            robot_apearence[3][9] = 'R';
            break;
        } 
        case OPONENT: {
            switch (current_oponent_orientation) {
                case UPWARD: {
                    for (int i = 0; i < ROBOT_LINES; i++) {
                        for (int j = 0; j < ROBOT_COLUMNS; j++) {
                            robot_apearence[i][j] = upwards_robot[i][j];
                        }
                        // strcpy(robot_apearence[i], upwards_robot[i]);
                    }
                    // *robot_apearence = &upwards_robot;
                    robot_apearence[3][9] = ' ';
                    break;
                }
                case DOWNWARD: {
                    for (int i = 0; i < ROBOT_LINES; i++) {
                        for (int j = 0; j < ROBOT_COLUMNS; j++) {
                            robot_apearence[i][j] = downwards_robot[i][j];
                        }
                        // strcpy(robot_apearence[i], downwards_robot[i]);
                    }
                    // *robot_apearence = &downwards_robot;
                    robot_apearence[3][9] = '_';
                    break;
                }
            }
        }
    }

    for (int i = 0; i < ROBOT_LINES; i++) {
        for (int j = 0; j < ROBOT_COLUMNS; j++) {
            dojo[i + dist_x][j + dist_y] = robot_apearence[i][j];
        }
    }

    // for (int i = 0; i < ROBOT_LINES; i++) {
    //     for (int j = 0; j < ROBOT_COLUMNS; j++) {
    //         printf("%c", robot_apearence[i][j]);
    //     }
    //     printf("\n");
    // }

    // for (int i = 0; i < ROBOT_LINES; i++){
    //     sprintf(dojo[i], "%s", robot_apearence[i]);
    //     // printf(MAX_SPACES); 
    // }
}


void limpa_dojo() {
    for (int i = 0; i < DOJO_LINES; i++) {
        for (int j = 0; j < DOJO_COLUMNS; j++){
            dojo[i][j] = '.';
        }
    }
}

void imprime_dojo() {
    // printf("\033[2J\033[H"); /**< Limpa o terminal */

    // for (int i = 0; i < DOJO_LINES; i++) {
    //     printf("%s", dojo[i]);
    //     // printf("\n");
    // }

    for (int i = 0; i < DOJO_LINES; i++) {
        for (int j = 0; j < DOJO_COLUMNS; j++){
            printf("%c", dojo[i][j]);
        }
        printf("\n");
    }
}

void set_robot_position(uint8_t position) {
    if (position == 0) {
        // oponent_line = DOJO_LINES - ROBOT_LINES;
        oponent_line = ROBOT_LINES + 2;
        oponent_column = 0;

        rozeta_line = DOJO_LINES - ROBOT_LINES;
        rozeta_column = (DOJO_COLUMNS - ROBOT_COLUMNS)/2;
    } else if (position == 1) {
        oponent_line = 0;
        oponent_column = 0;
        
        rozeta_line = DOJO_LINES - ROBOT_LINES;
        rozeta_column = (DOJO_COLUMNS - ROBOT_COLUMNS)/2;
    } else if (position == 2) {
        oponent_line = 0;
        oponent_column = (DOJO_COLUMNS - ROBOT_COLUMNS)/2;
        
        rozeta_line = DOJO_LINES - ROBOT_LINES;
        rozeta_column = (DOJO_COLUMNS - ROBOT_COLUMNS)/2;
    } else if (position == 3) {
        oponent_line = 0;
        oponent_column = DOJO_COLUMNS - ROBOT_COLUMNS;
        
        rozeta_line = DOJO_LINES - ROBOT_LINES;
        rozeta_column = (DOJO_COLUMNS - ROBOT_COLUMNS)/2;
    } else /*if (position == 4)*/ {
        oponent_line = DOJO_LINES - ROBOT_LINES;
        oponent_column = DOJO_COLUMNS - ROBOT_COLUMNS;
        
        rozeta_line = DOJO_LINES - ROBOT_LINES;
        rozeta_column = (DOJO_COLUMNS - ROBOT_COLUMNS)/2;
    }

    // set_orientation(OPONENT, DOWNWARD);
    // imprime_robo(OPONENT, oponent_line, oponent_column);

    set_orientation(ROZETA, UPWARD);
    imprime_robo(ROZETA, rozeta_line, rozeta_column);
}