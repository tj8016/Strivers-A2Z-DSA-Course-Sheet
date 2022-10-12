//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
private:
    // Recursion --> T.C = O(2^N);
    int solveRec(int idx, int *arr) {
        // Base case
        if(idx < 0) {
            return 0;
        }
        if(idx == 0) {
            return arr[0];
        }
        
        int pick = 0;
        int notpick = 0;

        pick += arr[idx] + solveRec(idx-2, arr);
        notpick += 0 + solveRec(idx-1, arr);
        
        return max(pick, notpick);
    }

    // Memoisation --> T.C = O(N) and S.C = O(N) + O(N)
    int solveMemo(int ind, vector<int>& arr, vector<int>& dp) {
        if(dp[ind]!=-1) return dp[ind];
        
        if(ind==0) return arr[ind];
        if(ind<0)  return 0;
        
        int pick= arr[ind]+ solveMemo(ind-2, arr,dp);
        int nonPick = 0 + solveMemo(ind-1, arr, dp);
        
        return dp[ind]=max(pick, nonPick);
    }

    // Tabulation --> T.C = O(N) and S.C = O(N)
    int solveUtil(int n, vector<int>& arr, vector<int>& dp) {
        dp[0]= arr[0];
        
        for(int i=1 ;i<n; i++){
            int pick = arr[i];
            if(i>1)
                pick += dp[i-2];
            int nonPick = 0+ dp[i-1];
            
            dp[i]= max(pick, nonPick);
        }

        return dp[n-1];
    }

    // spaceOptimazation --> T.C = O(N) and S.C = O(1)
    int spaceOptimazation(int idx, int *arr) {
        int prev1 = arr[0];
        int prev2 = 0;
        
        for(int i=1; i<=idx; i++) {
            int pick = arr[i];
            int notpick = INT_MIN;
            
            pick += prev2;
            notpick = 0 + prev1;
            
            int curr = max(pick, notpick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    return spaceOptimazation(n-1, arr);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends