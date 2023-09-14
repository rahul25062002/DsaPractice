//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mod=1e9+7;
    int ways(int arr[], int n, int sum,vector<vector<int>> &dp){
        
        if(n<0) return sum==0;
        
        if(dp[n][sum]!=-1) return dp[n][sum];
        int nottake=ways(arr,n-1,sum,dp)%mod;
        int take=0;
        if(sum>=arr[n]){
            take=ways(arr,n-1,sum-arr[n],dp)%mod;
        }
        
        return dp[n][sum]=(take+nottake)%mod;
        
        
    }

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return ways(arr,n-1,sum,dp);
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