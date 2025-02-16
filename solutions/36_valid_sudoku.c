#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    if (boardSize != 9) {return false;}
    for (int i = 0; i < boardSize; i++) {
        if (boardColSize[i] != boardSize) {return false;}
    }
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j< boardColSize[i]; j++) {
            char c = board[i][j];
            if (c == '.') {
                continue;
            } else if (c < '0' || c > '9') {
                return false;
            }
            int k = (i/3)*3 + (j/3); //box index
            int num = c - '1';
            if ((rows[i] & (1<<num)) || (cols[j] & (1<<num)) || (boxes[k] & (1<<num))) {
                return false;
            }
            rows[i] |= (1 << num);
            cols[j] |= (1 << num);
            boxes[k] |= (1 << num);
        }
    }
    return true;
}
