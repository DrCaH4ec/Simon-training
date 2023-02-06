#include <stdbool.h>

#define GET_BIT(x, y) ((x) & (1<<(y)))
#define SET_BIT(x, y) ((x) | (1<<(y)))


bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int row[9] = {0}, col[9] = {0}, square[9] = {0}; 
    int i, j;

    for (i = 0; i < boardSize; i++) {
        for (j = 0; j < boardColSize[i]; j++) {
            if (board[i][j] == '.')
                continue;
            int val = board[i][j] - '0';

            if (GET_BIT(row[i], val) > 0 ||
                GET_BIT(col[j], val) >  0 ||
                GET_BIT(square[(i/3)*3 + (j/3)%3], val) >  0)
            {
                return false;
            }
            row[i] = SET_BIT(row[i], val);
            col[j] = SET_BIT(col[j], val);
            square[(i/3)*3 + (j/3)%3] = SET_BIT(square[(i/3)*3 + (j/3)%3], val);
        }
    }

    return true;
}