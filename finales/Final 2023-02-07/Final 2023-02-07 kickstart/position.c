#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "position.h"

struct _position {
        unsigned int row;
        unsigned int column;
        unsigned int dimension;
};


position_t position_initial(unsigned int dimension)
{
        position_t table = malloc(sizeof(struct _position));
        table->row = 0;
        table->column = 0;
        table->dimension = dimension;
        return table;
}

position_t position_absolute(unsigned int row, unsigned int column,
                             unsigned int dimension)
{
        position_t q = position_initial(dimension);
        q->row = row;
        q->column = column;
        return q;
}

position_t position_left(position_t pos)
{
        if (pos->column == 0){
                pos->column = pos->dimension - 1;
        }
        else{
                pos->column--;
        }
        return pos;
}

position_t position_right(position_t pos)
{
        if (pos->column == pos->dimension-1){
                pos->column = 0;
        }
        else{
                pos->column++;
        }
        return pos;
}

position_t position_down(position_t pos)
{
        if (pos->row == pos->dimension-1){
                pos->row = 0;
        }
        else{
                pos->row++;
        }
        return pos;
}

position_t position_up(position_t pos)
{
        if (pos->row == 0){
                pos->row = pos->dimension - 1;
        }
        else{
                pos->row--;
        }
        return pos;
}

unsigned int position_row(position_t pos)
{
        return pos->row;
}

unsigned int position_column(position_t pos)
{
        return pos->column;
}

unsigned int **position_board(position_t pos)
{
        unsigned int **board = malloc(sizeof(unsigned int *) * pos->dimension);
        for (unsigned int i = 0; i < pos->dimension; i++) {
                board[i] = malloc(sizeof(unsigned int) * pos->dimension);
        }
        for (unsigned int i = 0; i < pos->dimension; i++)
        {
                for (unsigned int j = 0; j < pos->dimension; j++) {
                        board[i][j] = 0;
                }
        }
        board[pos->row][pos->column] = 1;
        return board;
}

list_t position_movements(position_t pos)
{
        list_t aux = list_empty();
        unsigned int i = 0;
        while(i < pos->row){
                aux = list_append(aux, DOWN);
                i++;
        }
        i = 0;
        while(i < pos->column){
                aux = list_append(aux, RIGHT);
                i++;
        }
        return aux;
}

position_t position_destroy(position_t pos)
{
        free(pos);
        return NULL;
}
