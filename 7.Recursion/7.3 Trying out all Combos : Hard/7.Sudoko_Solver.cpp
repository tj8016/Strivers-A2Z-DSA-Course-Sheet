#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool isSafe(int row, int col, vector<vector<char>>& board, char val) {
        for(int i=0; i<board.size(); i++) {
            // check col
            if(board[row][i] == val) {
                return false;
            }

            // check row
            if(board[i][col] == val) {
                return false;
            }

            // 3*3 check
            if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == val) {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();

        for(int row=0; row<n; row++) {
            for(int col=0; col<n; col++) {
                if(board[row][col] == '.') {
                    for(int i='1'; i<='9'; i++) {
                        if(isSafe(row, col, board, i)) {
                            board[row][col] = i;

                            bool nextPossible = solve(board);
                            if(nextPossible) {
                                return true;
                            }
                            else {
                                // Backtracking
                                board[row][col] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

int main() {
    
    return 0;
}