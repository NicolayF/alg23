#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

int main(void) {
    char user_input[MAX_LENGTH];

    printf("Ingrese su nombre y apellido: ");
    fgets(user_input, sizeof(user_input), stdin);
    size_t len = strlen(user_input);
    if(len > 0 && user_input[len-1] == '\n'){
        user_input[len-1] = '\0';
    }

    printf("Te damos la bienvenida %s a este maravilloso programa!\n", user_input);

    return EXIT_SUCCESS;
}

