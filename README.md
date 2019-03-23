# Tarefa de  C

Nesta tarefa exitem dois robôs feitos somente com caracteres, o robô 'rozeta' e o robô 'oponent'. O objetivo do rozeta é encontrar seu oponente, algo semelhante ao que acontece em partidas de sumôs.

Para isso, devem ser programadas estratégias para que o rozeta encotre o oponente. Essas estratégias devem ser programadas no arquivo `strategies.c` e os protótipos de suas funções devem ser adicionadas em seu respectivo arquivo `.h`.

Para fazer essas estratégias, devem ser utilizadas as seguintes funções dos arquivos `movement.h/movement.c`, a primeira para definir a velocidade do robô e as outras quatro para movê-lo:

``` C
/**
 * @brief Movement related functions and variables.
 *
 * @param speed robot speed in line/second.
 */
void set_speed(float speed);

void move_up();

void move_down();

void move_right();

void move_left();
```

Além disso, pode ser utilizada a seguinte função dos arquivos `robot.h/robot.c` para definir a orientação do robô no dojo, uma vez que o rozeta deve sempre encontrar o seu oponente com a sua parte da frente:

``` C
void set_orientation(robot_t robot, orientation_t orientation);
```

Utilizando todas essas funções, devem ser feitas as estratégias de forma que o rozeta encontre o oponente para cada uma das posições iniciais do adversário. Existe um exemplo de uma estratégia no arquivo `strategies.c` que considera somente o caso onde a posição inicial do robô é a 2, a qual é a estratégia que está inicialmente na `main`.

## Extra

Para a tarefa extra, deve-se inicializar a posição do robô adversário randomicamente e deve ser feita uma função que retorna essa posição inicial do oponente, para então se escolher o que o robô fará.