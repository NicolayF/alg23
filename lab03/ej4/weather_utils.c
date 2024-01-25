#include "weather_utils.h"



int historica_temp_min(WeatherTable a) {
    int hist = a[0][0][0]._min_temp;

    for (unsigned int i = 0; i < YEARS; i++) {
        for (unsigned int j = 0; j < MONTHS; j++) {
            for (unsigned int k = 0; k < DAYS; k++) {
                hist = (hist > a[i][j][k]._min_temp) ? a[i][j][k]._min_temp : hist;
            }
        }
    }
    return hist;
}

void año_temp_max(WeatherTable a, int output[YEARS]) {
    for (unsigned int i = 0; i < YEARS; i++) {
        int temp = a[0][0][0]._max_temp;
        for (unsigned int j = 0; j < MONTHS; j++) {
            for (unsigned int k = 0; k < DAYS; k++) {
                temp = (temp < a[i][j][k]._max_temp) ? a[i][j][k]._max_temp : temp;
            }
        }
        output[i] = temp;
    }
}

void mes_prec_max(WeatherTable a, unsigned int output[YEARS]) {
    month_t month = 0;
    for (unsigned int i = 0; i < YEARS; i++) {
        unsigned int rain = a[0][0][0]._rainfall;
        for (unsigned int j = 0; j < MONTHS; j++) {
            for (unsigned int k = 0; k < DAYS; k++) {
                if (rain < a[i][j][k]._rainfall) {
                    rain = a[i][j][k]._rainfall;
                    month = j;
                }
            }
        }
        output[i] = month;
    }
}