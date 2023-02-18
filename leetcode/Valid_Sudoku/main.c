#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[j][i] != '.')
                for (int n = i + 1; n < 9; n++)
                    if (board[j][i] == board[j][n])
                        return false;
            if (board[i][j] != '.')
                for (int n = i + 1; n < 9; n++)
                    if (board[i][j] == board[n][j])
                        return false;
            if(i % 3 == 0 && j % 3 == 0)
                for (int ind_row = j; ind_row < j + 3;ind_row++)
                    for (int ind_col = i; ind_col < i + 3;ind_col++)
                        if (board[ind_row][ind_col] != '.')
                            for (int ind_row_aft = j; ind_row_aft < j + 3; ind_row_aft++)
                                for(int ind_col_aft = i; ind_col_aft < i + 3; ind_col_aft++)
                                    if (board[ind_row][ind_col] == board[ind_row_aft][ind_col_aft] &&
                                        !(ind_row == ind_row_aft && ind_col == ind_col_aft))
                                        return false;
        }
    }
    return true;
}
