#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<vector<int>>& board) {
    for (const auto & row : board) {
        for (int cell : row)
            cout << (cell ? "Q " : ". ");
        cout << endl;
    }
}

bool isSafe(const vector<vector<int>>& board, int row, int col) {
	
    int N = board.size();
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
    
}

bool solveNQUtil(vector<vector<int>>& board, int col) {
    int N = board.size();
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1))
                return true;
            board[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}

bool solveNQ(int N) {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQUtil(board, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(board);
    return true;
}

int main() {
    int N;
    cout << "Enter the size of the chessboard (N x N): ";
    cin >> N;

    if (N <= 0) {
        cout << "Invalid size. Please enter a positive integer." << endl;
        return 1;
    }

    solveNQ(N);
    return 0;
}
