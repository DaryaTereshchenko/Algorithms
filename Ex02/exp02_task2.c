#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N = 8;
int count = 0;

void printBoard(int board[N][N]) {
    printf("Solution %d:\n", count);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[N][N], int row, int col) {
    // Check row and column
    for (int i = 0; i < row; i++) {
        if (board[i][col])
            return 0;
    }

    // Check upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        printf("%d %d\n", i, j);
        if (board[i][j])
            return 0;
    }

    // Check upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        
        if (board[i][j])
            return 0;
    }

    return 1;
}

void solveNQueens(int board[N][N], int row) {
    if (row == N) {
        count++;
        // Uncomment the line below to print the board for each solution
        // printBoard(board);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            solveNQueens(board, row + 1);
            board[row][col] = 0; // Backtrack
        }
    }
}

int main() {
    int board[N][N];
    memset(board, 0, sizeof(board));

    solveNQueens(board, 0);

    printf("Total solutions: %d\n", count);

    return 0;
}
