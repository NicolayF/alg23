#include "array_helpers.h"

/*Temperatura minima historica*/
int historica_temp_min(WeatherTable a);

/*Temperatura maxima de cada año*/
void año_temp_max(WeatherTable a, int output[YEARS]);

/*Mes de cada año con mas precipitaciones*/
void mes_prec_max(WeatherTable a, unsigned int output[YEARS]);
