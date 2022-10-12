#include<iostream>
#include<vector>
using namespace std;

// 1 : Recursion
int getFibo(int n) {
    // Base Case
    if(n <= 1) {
        return n;
    }
    // rec relation and return
    return getFibo(n-1) + getFibo(n-2);
}

// 2 : Recursion + Memoisation
// step1: create (n+1) DP array + pass the function
// step2: store the ans in DP array
// step3: check if DP array already have a ans , if yes, then return , just after the base cash
int solveMemo(int n, vector<int>& dp) {
    
    if(n <= 1) {
        return n;
    }
    // step 3
    if(dp[n] != -1) {
        return dp[n];
    }

    int ans = solveMemo(n-1, dp) + solveMemo(n-2, dp);
    // step 2
    return dp[n] = ans;
}

// Buttom up Approach
// step 1 : Dp array creation
// step 2 : Base case analysis of Recursion code update dp array accordingly
// step 3 : Find the range for the changing variable and copy paste the logic in rec code accordingly
int solveTab(int n) {
    // step 1:
    vector<int> dp(n+1, 0);
    
    // step 2:
    dp[0] = 0;
    dp[1] = 1;

    // step 3:
    for(int i=2; i<=n; i++) {
        int ans = dp[i-1] + dp[i-2];
        dp[i] = ans;
    } 
    return dp[n];
}

// Space Optimisation
int solveTaboSo(int n) {
    // step 1:
    int prev1 = 1;
    int prev2 = 0;
    int curr;

    for(int i=2; i<=n; i++) {
        int ans = prev1 + prev2;
        curr = ans;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr; 
}

int main() {
    int n;
    cout << "Enter the value of n :" << endl;
    cin >> n;
    // Recursion
    // int ans = getFibo(n);

    // Recursion + Memoisation
    // vector<int> dp(n+1, -1); // step 1
    // int ans = solveMemo(n, dp);

    // Buttom up 
    int ans = solveTab(n);

    cout << "The ans is -> " << ans << endl;
    return 0;
}