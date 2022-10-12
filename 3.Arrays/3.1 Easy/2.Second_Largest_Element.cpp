//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    int maxi = -1, second_maxi = -1;
	    
	    for(int i=0; i<n; i++) {
	        maxi = max(maxi, arr[i]);
	    }
	    
	    for(int i=0; i<n; i++) {
	        if(second_maxi < arr[i] && arr[i] != maxi) {
	            second_maxi = arr[i];
	        }
	    }
	    
	    return second_maxi;
	}

	int secondSmallest(int arr[],int n)
	{
		if(n<2)
			return -1;
		int small = INT_MAX;
		int second_small = INT_MAX;
		int i;
		for(i = 0; i < n; i++) 
		{
		if(arr[i] < small)
		{
			second_small = small;
			small = arr[i];
		}
		else if(arr[i] < second_small && arr[i] != small)
		{
			second_small = arr[i];
		}
		}
	return second_small;     
	}
	int secondLargest(int arr[],int n)
	{
		if(n<2)
		return -1;
		int large=INT_MIN,second_large=INT_MIN;
		int i;
		for (i = 0; i < n; i++) 
		{
			if (arr[i] > large) 
			{
				second_large = large;
				large = arr[i];
			}
	
			else if (arr[i] > second_large && arr[i] != large) 
			{
				second_large = arr[i];
			}
		}
		return second_large;                
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
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends