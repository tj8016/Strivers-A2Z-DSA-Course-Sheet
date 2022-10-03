//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
    private:
    void solve(vector<int>& candidates, int target, int idx, vector<int> path, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(path);
        }
        if(target < candidates[idx]) {
            return;
        }
        if(idx >= candidates.size()) {
            return;
        }
        unordered_set<int> check;
        for(int i=idx; i<candidates.size(); i++) {
            if(check.find(candidates[i]) == check.end()) {
                path.push_back(candidates[i]);
                solve(candidates, target-candidates[i], i, path, ans);
                path.pop_back();
            }
            check.insert(candidates[i]);
        }
    }
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(), A.end());
        vector<vector<int>> ans;
        vector<int> path;

        solve(A, B, 0, path, ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends