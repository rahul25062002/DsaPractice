//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  private:
    int fun(int index,int left,int price[],int n,vector<vector<int>> &dp){
        //base case
        if(left==0) return 0;
        if(left<index+1) return 0;
        if(index>=n) return 0;
        if(dp[index][left]!=-1) return dp[index][left];
        int nottaken=fun(index+1,left,price,n,dp);
        int taken=0;
        if(left>=index+1) taken=price[index]+fun(index,left-index-1,price,n,dp);
        return dp[index][left]=max(taken,nottaken);
        
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return fun(0,n,price,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends