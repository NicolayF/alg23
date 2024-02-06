#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "position.h"
int main()
{
    position_t pos;
    list_t lista = list_empty();
    pos = position_absolute(5,1,6);
    pos = position_left(pos);
    pos = position_right(pos);
    pos = position_up(pos);
    pos = position_down(pos);
    printf("Fila %u\n", position_row(pos));
    printf("Columna %u\n", position_column(pos));
    unsigned int **board = position_board(pos);
    lista = position_movements(pos);
    list_show(lista);
    for (unsigned int i = 0; i < 6; i++) {
        for (unsigned int j = 0; j < 6; j++) {
            printf("%u", *(&board[i][j]));
            printf("-");
        }
        printf("\n");
    }
    pos = position_destroy(pos);
    for (unsigned int  i= 0;  i< 6; i++) {
        free(board[i]);
    }
    free(board);
    lista = list_destroy(lista);
    return 0;
}