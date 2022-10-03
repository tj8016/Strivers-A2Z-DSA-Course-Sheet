// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
private:
    void solve(vector<int> arr, int N, int idx, vector<int> path, vector<int>& ans) {
        if(idx == arr.size()) {
            int sum = 0;
            for(int i=0; i<path.size(); i++) {
                sum += path[i];
            }
            ans.push_back(sum);
            return;
        }
        
        // include
        path.push_back(arr[idx]);
        solve(arr, N, idx+1, path, ans);
        
        // exclude
        path.pop_back();
        solve(arr, N, idx+1, path, ans);
    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        vector<int> path;
        
        solve(arr, N, 0, path, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends