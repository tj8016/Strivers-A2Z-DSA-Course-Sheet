//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool isSafe(vector<vector<int>> &m, int r, int c, int n, vector<vector<int>>& visited) {
        if(r >= 0 && r < n && c >= 0 && c < n && m[r][c] == 1 && visited[r][c] == 0) {
            return true;
        }
        return false;
    }
    
    void solve(vector<vector<int>> &m, int r, int c, int n, string output, vector<string>& ans, vector<vector<int>>& visited) {
        // Base case
        if(r == n-1 && c == n-1) {
            ans.push_back(output);
            return;
        }
        
        visited[r][c] = 1;
        
        // Down
        if(isSafe(m, r+1, c, n, visited)) {
            output.push_back('D');
            solve(m, r+1, c, n, output, ans, visited);
            output.pop_back();
        }
        
        // Left
        if(isSafe(m, r, c-1, n, visited)) {
            output.push_back('L');
            solve(m, r, c-1, n, output, ans, visited);
            output.pop_back();
        }
        
        // Right
        if(isSafe(m, r, c+1, n, visited)) {
            output.push_back('R');
            solve(m, r, c+1, n, output, ans, visited);
            output.pop_back();
        }
        
        // Up
        if(isSafe(m, r-1, c, n, visited)) {
            output.push_back('U');
            solve(m, r-1, c, n, output, ans, visited);
            output.pop_back();
        }
        
        visited[r][c] = 0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0] == 0) {
            return ans;
        }
        string output;
        vector<vector<int>> visited = m;
        
        for(int i=0; i<visited.size(); i++) {
            for(int j=0; j<visited[0].size(); j++) {
                visited[i][j] = 0;
            }
        }
        
        solve(m, 0, 0, n, output, ans, visited);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends