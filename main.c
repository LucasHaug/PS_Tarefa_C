#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <sys/time.h>

#define MAX_SPACES "                    "
#define MIN_SPACES "          "

#define INITIAL_ROZETA_LINES 6
#define INITIAL_ROZETA_COLUMNS 22

#define ROBOT_LINES 5
#define ROBOT_COLUMNS 20

#define MAX_LINES (5*ROBOT_LINES)
#define MAX_COLUMNS (3*ROBOT_COLUMNS)

struct timeval;

static float delay_time = 0.5;

char dojo[MAX_LINES][MAX_COLUMNS];

typedef enum robo {
    ROZETA,
    OPONENTE,
} robo_t;

const char* initial_rozeta[] = {
"                    \n",
"    2    3    4     \n",
"    ___________     \n",
"1  |___________|  5 \n",
"   |     R     |    \n",
"  [|___________|]   \n" 
};

const char* rozeta[] = {
"                  \n",
"    ___________   \n",
"   |___________|  \n",
"   |     R     |  \n",
"  [|___________|] \n" 
};

const char* oponente[] = {
"                  \n",
"    ___________   \n",
"  [|           |] \n",
"   |___________|  \n",
"   |___________|  \n",
};

void delay(float extra_time);

void set_speed(float speed);

void imprime_rozeta(robo_t robo, uint8_t dist_x, uint8_t dist_y);

void imprime_robo(robo_t robo, uint8_t dist_x, uint8_t dist_y);

void limpa_dojo();

void imprime_dojo();


int main() {
    int sensor_position = 1;

    static int line = 0;
    static int column = 0; 

    printf("Digite a posição do robo: ");
    scanf("%d", &sensor_position);

    set_speed(2);

    // int moves = 6;

    char mov;
    printf("Iniciar movimento [y/n]: ");
    scanf(" %c", &mov);

    switch (mov) {
        case 'y': {
            break;
        }
        case 'n':
        default: {
            printf("Bye bye");
            return 0;
        }
    }

    for (int moves = 6; moves > -1; moves--) {
        limpa_dojo();
        
        for (int i = 0; i < ROBOT_LINES; i++) {
            for (int j = 0; j < ROBOT_COLUMNS; j++){
                dojo[i][j] = oponente[i][j];
            }
        }

        for (int i = 0; i < ROBOT_LINES; i++) {
            for (int j = 0; j < ROBOT_COLUMNS; j++){
                dojo[i + ROBOT_LINES + moves][j] = rozeta[i][j];
            }
            // sprintf(dojo[i + ROBOT_LINES + moves], MAX_SPACES "%s", rozeta[i]);
        }

        imprime_dojo();

        delay(delay_time);
    }
        
    // printf("\033[2J\033[H");

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

void imprime_rozeta(robo_t robo, uint8_t dist_x, uint8_t dist_y) {
    for (int i = 0; i < 6; i++){
        printf("%s", rozeta[i]);
        printf(MAX_SPACES); 
    }
}

void imprime_robo(robo_t robo, uint8_t dist_x, uint8_t dist_y) {
    for (int i = 0; i < 4; i++){
        printf("%s", oponente[i]);
        // printf(MAX_SPACES); 
    }
}


void limpa_dojo() {
    for (int i = 0; i < MAX_LINES; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++){
            dojo[i][j] = ' ';
        }
    }
}

void imprime_dojo() {
    printf("\033[2J\033[H"); /**< Limpa o terminal */

    for (int i = 0; i < MAX_LINES; i++) {
        printf("%s", dojo[i]);
    }
}