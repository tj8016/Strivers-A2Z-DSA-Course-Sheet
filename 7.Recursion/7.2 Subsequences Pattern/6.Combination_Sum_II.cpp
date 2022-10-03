#include <bits/stdc++.h>
using namespace std;


class Solution {
private:
    void solve(vector<int>& candidates, int target, int idx, vector<int> path, vector<vector<int>>& ans) {
        if(target == 0) {
            ans.push_back(path);
            return;
        }

        for(int i=idx; i<candidates.size(); i++) {
            if(i != idx && candidates[i] == candidates[i-1]) {
                continue;
            }
            if(target < candidates[i]) break;

            path.push_back(candidates[i]);
            solve(candidates, target-candidates[i], i+1, path, ans);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> output;

        solve(candidates, target, 0, output, ans);
        return ans;
    }
};

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
        vector<vector<int>> result = ob.combinationSum2(A, sum);
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
    return 0;
}