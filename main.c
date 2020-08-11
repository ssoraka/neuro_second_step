#include "header.h"

/*
 *
 * мне эта презентация кажется наиболее понятной
 * https://myslide.ru/presentation/520550_skachat-iskusstvennye-nejronnye-seti
 *
 * 1)нужно написать функции для активации слоя, поиска ошибки и изменения веса
 * 2)далее можно испытать другие функции активации
 * 3)далее можно попробовать другие тестовые данные
 */


// Функция активации
double f(double x)
{
	double e_x;
	e_x = exp(-x);
	if (-1 == e_x)
		return (0.0);
	return (1 / (1 + e_x));
}

// Производная от функции активации
double df_dx(double fx)
{
	return (fx * (1 - fx));
}

void init_layer(t_layer *layer) {
	int i;
	int j;

	// Инициализация связей между входом НС и скрытым слоем случайными значениями
	j = 0;
	while (j < layer->j_count) {
		i = 0;
		while (i < layer->i_count) {
			layer->w_ij[i][j] = ((double)rand()) / RAND_MAX;
			i++;
		}
		j++;
	}
}

double input[CASE_COUNT][N_INPUT] = {
		{1.0, 1.0, 0.0, 0.0},
		{0.0, 1.0, 1.0, 0.0},
		{0.0, 0.0, 1.0, 1.0},
		{1.0, 0.0, 0.0, 1.0},
};

double output[CASE_COUNT][N_INPUT] = {
		{1.0, 0.0, 0.0, 0.0},
		{0.0, 1.0, 0.0, 0.0},
		{0.0, 0.0, 1.0, 0.0},
		{0.0, 0.0, 0.0, 1.0},
};

///////////////////////////////////////////////
//эти функции надо сделать
//смотри статью
//по картинкам все понятно
void activate_layer(double *f_prev, t_layer *l) {

}

void calculate_out_error(double *answer, t_layer *l) {

}

void calculate_hidden_error(t_layer *curr, t_layer *next) {

}

void change_weight(double *f_prev, t_layer *l) {

}
//////////////////////////////////////////////////

void	print_arr_double(double *d, int size) {
	int i;

	i = 0;
	while (i < size) {
		printf("%.4lf ", d[i]);
		i++;
	}
	printf("\n");
}


int main() {

	t_layer l[2];

	srand(time(NULL));

	//инизиализация 1 слоя
	l[0].func = f;
	l[0].i_count = N_INPUT;
	l[0].j_count = 7; //на шару написал
	init_layer(l);

	//инизиализация 2 слоя
	l[1].func = f;
	l[1].i_count = l[0].j_count;
	l[1].j_count = N_OUTPUT;
	init_layer(l + 1);


	int ep;
	int example;

	ep = 0;
	while (ep < LAST_ERA) {
		example = 0;
		while (example < CASE_COUNT) {
			//1)активируем первый слой
			activate_layer(input[example], l);
			//2)активируем второй слой
			activate_layer(l[0].f, l + 1);
			//3)высчитываем значение ошибки для последнего слоя
			calculate_out_error(output[example], l + 1);
			//4)cчитаем ошибку для каждого нейрона скрытого слоя
			calculate_hidden_error(l, l + 1);
			//5)модификация весовых коэффициентов выходного слоя
			change_weight(l[0].f, l + 1);
			//6)модификация весовых коэффициентов скрытого слоя
			change_weight(input[example], l);

			print_arr_double(output[example], N_OUTPUT);
			print_arr_double(l[1].f, N_OUTPUT);
			example++;
		}
		ep++;
	}

	return 0;
}
