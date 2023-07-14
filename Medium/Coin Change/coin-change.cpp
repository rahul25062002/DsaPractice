//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:  long long int ways(int ind, int target,int coins[], vector<vector< long long int>> &dp){
      //base case
      if(ind==0) return (target%coins[0]==0);
      if(dp[ind][target]!=-1) return dp[ind][target];
       long long int nottake=ways(ind-1,target,coins,dp);
        long long int take=0;
        if(coins[ind]<=target) take=ways(ind,target-coins[ind],coins,dp);
        return dp[ind][target]= take+nottake;
  }
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector< long long int>> dp(N,vector< long long int>(sum+1,-1));
        return ways(N-1,sum,coins,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends