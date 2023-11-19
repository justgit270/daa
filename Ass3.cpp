#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector <int> > &board, int row, int col, int N) {
    // Check for queens in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check for queens in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check for queens in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(vector<vector <int> > &board, int row, int N) {
    if (row == N) {
        // Print the solution
        cout << "Solution:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    bool res = false;
    for (int i = 0; i < N; i++) {
        if (isSafe(board, row, i, N)) {
            board[row][i] = 1;
            res = solveNQueensUtil(board, row + 1, N) || res;
            board[row][i] = 0; // backtrack
        }
    }
    return res;
}

void solveNQueens(int N) {
    vector<vector <int> > board(N, vector<int>(N, 0));
    if (!solveNQueensUtil(board, 0, N)) {
        cout << "Solution does not exist" << endl;
    }
}

int main() {
    int N;
    cout << "Enter the number of queens: ";
    cin >> N;
    solveNQueens(N);
    return 0;
}
