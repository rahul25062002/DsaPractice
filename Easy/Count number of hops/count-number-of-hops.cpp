//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long Count(int n, vector<long long> &dp){
        
        if(n<0) return 0;
        if(n==0) return 1;
        
        // one step
        long long mod=1000000007;
        if(dp[n]!=-1) return dp[n];
        long long one=0,two=0,three=0;
        one=Count(n-1,dp)%mod;
        two=Count(n-2,dp)%mod;
        three=Count(n-3,dp)%mod;
        
        return  dp[n]=(one+two+three)%mod;
        
        
    }
    long long countWays(int n)
    {
        
        // your code here
        vector<long long> dp(n+1,-1);
        return Count(n,dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends