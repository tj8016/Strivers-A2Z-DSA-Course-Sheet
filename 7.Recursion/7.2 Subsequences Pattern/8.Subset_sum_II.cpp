#include<bits/stdc++.h> 
using namespace std; 

class Solution {
private:
    void solve(vector<int>& nums, int idx, vector<int> output, vector<vector<int>>& ans) {
        ans.push_back(output);
        for(int j=idx; j<nums.size(); j++) {
            if(idx == j || nums[j] != nums[j-1]) {
                output.push_back(nums[j]);
                solve(nums, j+1, output, ans);
                output.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> output;

        solve(nums, 0, output, ans);
        return ans;
    }
};

int main() {
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
        vector<vector<int>> ans = ob.subsetsWithDup(arr);
        sort(ans.begin(),ans.end());
        for(int i=0; i<ans.size(); i++) {
            cout << "[";
            for(int j=0; j<ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << "]";
            cout << endl;
        }
        cout<<endl;
    }
    return 0;
}