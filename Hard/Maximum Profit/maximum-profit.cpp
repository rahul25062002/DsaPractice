//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    int fun(int i,int buy,int prices[], vector<vector<int>> &dp, int &n){
       if(buy==0) return 0;
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
      
         int profit=0;
        if(buy%2==0){
             profit=max(-prices[i]+fun(i+1,buy-1,prices,dp,n),fun(i+1,buy,prices,dp,n));
        }
        else {
            profit=max(prices[i]+fun(i+1,buy-1,prices,dp,n),fun(i+1,buy,prices,dp,n)); 
        }
        return dp[i][buy]= profit;
    }
  public:
    int maxProfit(int k, int n, int prices[]) {
        // code here
         vector<vector<int>> dp(n,vector<int>(2*k+1,-1));

        return fun(0,2*k,prices,dp,n); 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends