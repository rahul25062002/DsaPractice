//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   private:
    long long mod = 1e9+7;
  int fun(int i, vector<int> &dp){
    if(i==0) return 1;
    if(i==1) return 1;
    if(dp[i]!=-1) return dp[i];
     return dp[i]=( fun(i-1,dp)%mod+fun(i-2,dp)%mod)%mod;
}
    public:
    
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1,-1);
        return fun(n,dp);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends