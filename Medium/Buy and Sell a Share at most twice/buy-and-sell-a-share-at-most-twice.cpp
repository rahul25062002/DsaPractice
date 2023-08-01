//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
  int fun(int i,int buy,vector<int>& prices, vector<vector<int>> &dp){
       if(buy==0) return 0;
        if(i==prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
      
         int profit=0;
        if(buy%2==0){
             profit=max(-prices[i]+fun(i+1,buy-1,prices,dp),fun(i+1,buy,prices,dp));
        }
        else {
            profit=max(prices[i]+fun(i+1,buy-1,prices,dp),fun(i+1,buy,prices,dp)); 
        }
        return dp[i][buy]= profit;
    }
int maxProfit(vector<int>&prices){
    //Write your code here..
     vector<vector<int>> dp(prices.size(),vector<int>(5,-1));

        return fun(0,4,prices,dp); 
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends