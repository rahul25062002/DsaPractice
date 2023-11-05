//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    int pathsum(int n,int m ,  vector<vector<int>> &grid ,vector<vector<int>> &dp){
        int mod=1e9+7;
        if(n==0 and m== 0) return 1;
        if(n<0) return 0;
        if(m<0) return 0;
        if(grid[n][m]==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int path1=pathsum(n,m-1,grid,dp);
        int path2=pathsum(n-1,m,grid,dp);
        
        return dp[n][m]= ((path1 % mod)+(path2 % mod)) % mod;
    }
    
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        int tol=0;
        if(grid[0][0]==0 || grid[n-1][m-1]==0) return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return pathsum(n-1,m-1,grid,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends