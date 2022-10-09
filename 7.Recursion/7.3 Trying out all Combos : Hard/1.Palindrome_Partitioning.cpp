#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isPalindrome(string s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    void solve(string s, int start, vector<string> path, vector<vector<string>>& ans) {
        if(start >= s.length()) {
            ans.push_back(path);
            return;
        }
        for(int i=start; i<s.length(); i++) {
            if(isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i-start+1));
                solve(s, i+1, path, ans);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        
        solve(s, 0, path, ans);
        return ans;
    }
};

int main() {
    string s = "aabb";
    Solution obj;
    vector < vector < string >> ans = obj.partition(s);
    int n = ans.size();
    cout << "The Palindromic partitions are :-" << endl;
    cout << " [ ";
    for (auto i: ans) {
        cout << "[ ";
        for (auto j: i) {
        cout << j << " ";
        }
        cout << "] ";
    }
    cout << "]";

  return 0;
}