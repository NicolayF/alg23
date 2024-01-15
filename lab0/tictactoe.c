#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define BOARD_SIZE 4
#define CELL_MAX (BOARD_SIZE * BOARD_SIZE - 1)

void print_board(char board[BOARD_SIZE][BOARD_SIZE])
{
    int cell = 0;
    printf("\t ....................................................................\n");
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int column = 0; column < BOARD_SIZE; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        printf("\t ...............................................................\n");
    }
}

char get_winner(char board[BOARD_SIZE][BOARD_SIZE])
{
    char winner = '-';

    // IMPLEMENTAR
    //check rows and columns
    for (unsigned int i = 0; i < BOARD_SIZE; i++)
    {
        char row_winner = board[0][0];
        char col_winner = board[0][0];
        for (unsigned int j = 1; j < BOARD_SIZE; j++)
        {
            row_winner = (row_winner == board[i][j] && row_winner != '-') ? row_winner : '-';
            col_winner = (col_winner == board[j][i] && col_winner != '-') ? col_winner : '-';
        }
        if (row_winner != '-')
        {
            return row_winner;
        }
        if (col_winner != '-')
        {
            return col_winner;
        }
    }
    
    //check diagonal
    char main_diag = board[0][0];
    char anti_diag = board[0][BOARD_SIZE-1];

    for (unsigned int i = 1; i < BOARD_SIZE; i++) {
        main_diag = (main_diag == board[i][i] && main_diag != '-') ? main_diag : '-';
        anti_diag = (anti_diag == board[i][BOARD_SIZE - 1 - i] && anti_diag != '-') ? anti_diag : '-';
    }

    if (main_diag != '-')
    {
        return main_diag;
    }
    if (anti_diag != '-')
    {
        return anti_diag;
    }
    
    return winner;
}

bool has_free_cell(char board[BOARD_SIZE][BOARD_SIZE])
{
    
    for (unsigned int i = 0; i < BOARD_SIZE; i++)
    {
        for (unsigned int j = 0; j < BOARD_SIZE; j++)
        {
            if (board[i][j] == '-')
            {
                return true;
            }
        }
        
    }
    
    return false;
}

void add_dash (char board[BOARD_SIZE][BOARD_SIZE], unsigned int b_size) {
    for (unsigned int i = 0; i < b_size; i++) {
        for (unsigned int j = 0; j < b_size; j++) {
            board[i][j] = '-';
        }
    }
}

int main(void)
{
    printf("TicTacToe [InCoMpLeTo :'(]\n");

    char board[BOARD_SIZE][BOARD_SIZE];
    add_dash(board, BOARD_SIZE);
    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición: ",
               turn);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / BOARD_SIZE;
            int colum = cell % BOARD_SIZE;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}
