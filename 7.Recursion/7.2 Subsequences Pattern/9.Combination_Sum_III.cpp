#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void solve(int k, int n, int idx, vector<int> path, vector<vector<int>>& ans) {
        if(path.size() == k) {
            if(n==0) {
                ans.push_back(path);
            }
            return;
        }

        for(int i=idx; i<=9; i++) {
            if(n < i) break;

            path.push_back(i);
            solve(k, n-i, i+1, path, ans);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;

        solve(k, n, 1, path, ans);
        return ans;
    }
};

int main() {
    int k;
    int n;

    cin >> k >> n;

    Solution op;
    vector<vector<int>> ans = op.combinationSum3(k, n);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "complete" << endl;
    return 0;
}