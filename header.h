//
// Created by ssoraka on 11.08.2020.
//

#ifndef NEURO_SECOND_HEADER_H
#define NEURO_SECOND_HEADER_H

#include <string.h>
#include <stdio.h>
#include <time.h>
#include "math.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

typedef int t_bool;

#define CASE_COUNT 4
#define N_INPUT 4
#define N_OUTPUT 4
#define LAST_ERA (1000)

//структура слоя
typedef struct		s_layer
{
	//функция активации нейрона
	double			(*func)(double);
	//массив выходов нейронов (зарезервировал 100 на просто для удобства)
	double			f[100];
	//массив ошибок для нейронов слоя
	double			error[100];
	//количество нейронов в этом слое
	int				j_count;
	// количество нейронов в предыдущем слое
	int				i_count;
	// массив связей размером i_count * j_count (зарезервировал 10000 на просто для удобства)
	double			w_ij[100][100];
}					t_layer;

#endif //NEURO_SECOND_HEADER_H
