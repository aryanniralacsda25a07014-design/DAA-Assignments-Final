
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> board;

bool isSafe(int row, int col) {
    // Check the same column in previous rows
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper-left diagonal
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper-right diagonal
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

void solveNQueens(int row) {
    // All queens have been placed
    if (row == N) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << (board[i][j] ? "Q " : ". ");
            }
            cout << '\n';
        }
        cout << '\n';
        return;
    }

    // Try every column in the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            solveNQueens(row + 1);

            // Backtrack
            board[row][col] = 0;
        }
    }
}

int main() {
    cout << "Enter N: ";
    cin >> N;

    if (N < 1 || N > 15) {
        cout << "Enter N between 1 and 15.\n";
        return 0;
    }

    board.assign(N, vector<int>(N, 0));

    cout << "Solutions:\n";
    solveNQueens(0);

    return 0;
}
