//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    bool isValid(vector<vector<char>>& board, string word, int idx, int r, int c) {
        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[idx] || board[r][c] == '@') {
            return false;
        }
        return true;;
    }
    bool solve(vector<vector<char>>& board, string word, int idx, int row, int col) {
        // Base case
        if(isValid(board, word, idx, row, col) == false) {
            return false;
        }
        if(idx == word.length()-1) {
            return true;
        }
        
        
        char ch = board[row][col];
        board[row][col] = '@';
        // you have 4 option D, L, R, U

        bool down = solve(board, word, idx+1, row+1, col);
        bool left = solve(board, word, idx+1, row, col-1);
        bool right = solve(board, word, idx+1, row, col+1);
        bool up = solve(board, word, idx+1, row-1, col);
        

        board[row][col] = ch;
        return down || left || right || up;
    }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j] == word[0]) {
                    bool ans = solve(board, word, 0, i, j);

                    if(ans == true) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "true\n";
		else cout << "false\n";
	}
	return 0;
}
// } Driver Code Ends