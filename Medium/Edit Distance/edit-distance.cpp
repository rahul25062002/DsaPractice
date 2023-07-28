//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
 private: int fun(int i,int j,string &s, string &t, vector<vector<int>> &dp){
     //base case
     if(i<0 and j<0) return 0;   // when both grt match then they move to -1 in both case so it will handle that case
     if(i<0) return 1+j;   // when t reft at that case we have to push remaning t into s
     //one by one so total will be i+1 steos
     if(j<0) return 1+i;  // whwn s left over 
     if(dp[i][j]!=-1) return dp[i][j];
     if(s[i]==t[j])return dp[i][j]=fun(i-1,j-1,s,t,dp);
     else {
         int insertion1=1+fun(i,j-1,s,t,dp);      
         int deletion1= 1+fun(i-1,j,s,t,dp);         
         int replacement1=1+fun(i-1,j-1,s,t,dp);
         
         return dp[i][j]= min(insertion1, min(deletion1, replacement1));}
 }
  public:
    int editDistance(string s, string t) {
        // Code here
       
        int n=s.size();
        int m=t.size();
         vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(n-1,m-1,s,t,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends