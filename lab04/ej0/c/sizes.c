#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 35, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi.age), sizeof(messi.age), sizeof(messi.height),sizeof(data_t));

    //char name[30] ocupa 30,
    //age 4
    //height 4
    //total 38, entonces data_t debe alocar al menos 40.(multiplos de 4)
    return EXIT_SUCCESS;
}

