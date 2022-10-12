#include <bits/stdc++.h>
using namespace std;

// Recursion
int solveRec(int idx, vector<int>& heights, int k) {
    if(idx == 0) {
        return 0;
    }

    int minStep = INT_MAX;
    for(int i=1; i<=k; i++) {
        if(idx-i >= 0) {
            int jump = solveRec(idx-i, heights, k) + abs(heights[idx]-heights[idx-i]);
            minStep = min(minStep, jump);
        }
    }

    return minStep;
}

// Memoization approach
int solveMemo(int idx, vector<int>& heights, int k, vector<int>& dp) {
    if(idx == 0) {
        return 0;
    }
    if(dp[idx] != -1) {
        return dp[idx];
    }

    int minStep = INT_MAX;
    for(int i=1; i<=k; i++) {
        if(idx-i >= 0) {
            int jump = solveMemo(idx-i, heights, k, dp) + abs(heights[idx]-heights[idx-i]);
            minStep = min(minStep, jump);
        }
    }

    return dp[idx] = minStep;
}

// Tabulation
int solveTabu(int n, vector<int>& heights, int k, vector<int>& dp) {
    dp[0] = 0;

    for(int idx=1; idx<=n; idx++) {
        int minStep = INT_MAX;
        for(int i=1; i<=k; i++) {
            if(idx-i >= 0) {
                int jump = dp[idx-i] + abs(heights[idx] - heights[idx-i]);
                minStep = min(minStep, jump);
            }
        }
        dp[idx] = minStep;
    }

    return dp[n];
}



int main() {

    vector<int> height{30, 10, 60 ,10 , 60 , 50};
    int n=height.size();
    int k=2;
    // Recursion
    cout << "Ans using Recursion: " << solveRec(n-1, height, k) << endl;

    //Memoization
    vector<int> dp(n, -1);
    cout << "Ans using Memoization: " << solveMemo(n-1, height, k, dp) << endl;

    // Tabulation
    vector<int> dpt(n, -1);
    cout << "Ans using Tabulation: " << solveTabu(n-1, height, k, dpt) << endl;

}