//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    private:
    void solve(int a[], int N, int idx, string output, vector<string>& ans, unordered_map<int, string>& mapping) {
        // Base case
        if(idx == N) {
            ans.push_back(output);
            return;
        }
        
        int current = a[idx];
        string value = mapping[current];
        
        for(int i=0; i<value.length(); i++) {
            output.push_back(value[i]);
            solve(a, N, idx+1, output, ans, mapping);
            // Backtracking
            output.pop_back();
        }
    }
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> ans;
        if(N == 0) return ans;
        int index = 0;
        string output;
        unordered_map<int, string> mapping;
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        
        solve(a, N, index, output, ans, mapping);
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends