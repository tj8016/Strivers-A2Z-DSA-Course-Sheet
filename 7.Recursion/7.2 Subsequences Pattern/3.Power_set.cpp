//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    void solve(string s, int i, string str, vector<string>& ans) {
	        if(i == s.length()) {
	            if(str != "") {
	                ans.push_back(str);
	            }
	            return;
	        }
	        // include
	        str.push_back(s[i]);
	        solve(s, i+1, str, ans);
	        
	        // exclude
	        str.pop_back();
	        solve(s, i+1, str, ans);
	        
	        
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    string str;
		    solve(s, 0, str, ans);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends