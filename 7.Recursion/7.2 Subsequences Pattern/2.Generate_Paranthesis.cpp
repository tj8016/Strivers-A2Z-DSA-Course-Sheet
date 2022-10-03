//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    private:
    void solve(int open, int close, string output, vector<string>& ans) {
        // Base case
        if(open == 0 && close == 0) {
            ans.push_back(output);
            return;
        }
        
        if(open > 0) {
            solve(open-1, close, output+"(", ans);
        }
        if(open < close) {
            solve(open, close-1, output+")", ans);
        }
    }
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        string output;
        solve(n, n, output, ans);
        return ans;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code 