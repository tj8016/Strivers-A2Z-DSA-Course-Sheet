//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    private:
    void solve(int idx, int arr[], int n, int sum, vector<int> output, int& count) {
        if(idx == n) {
            int checksum = 0;
            for(int i=0; i<output.size(); i++) {
                checksum += output[i];
            }
            if(checksum == sum) {
                count++;
            }
            return;
        }
        
        // include
        output.push_back(arr[idx]);
        solve(idx+1, arr, n, sum, output, count);
        
        // exclude
        output.pop_back();
        solve(idx+1, arr, n, sum, output, count);
    }
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<int> output;
        int count = 0;
        
        solve(0, arr, n, sum, output, count);
        return count;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends