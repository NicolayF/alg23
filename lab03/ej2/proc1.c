#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if(x >= 0) {
        y = x;
    }
    else {
        y = -x;
    }
}

int main(void) {
    int a=0, res=0;
    a = -1;
    absolute(a, res);
    printf("%d,%d", a,res);
    printf("\n");   

    return EXIT_SUCCESS;
}

//absolute solo modifica 'y' dentro de la funcion pero no modifica una variable global.