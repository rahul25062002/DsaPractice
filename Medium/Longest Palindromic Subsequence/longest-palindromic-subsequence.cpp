//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  private: int  commonsebsequence(int ind1,int ind2,string &a,string &b, vector<vector<int>> & dp){
      if(ind1<0 or ind2<0) return 0;
      if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
      //if match
      if(a[ind1]==b[ind2]) return 1+commonsebsequence(ind1-1,ind2-1,a,b,dp);
      // when not match
      return dp[ind1][ind2]=max(commonsebsequence(ind1-1,ind2,a,b,dp),commonsebsequence(ind1,ind2-1,a,b,dp));
  }
  public:
    int longestPalinSubseq(string a) {
        //code here
        string b;
        reverse_copy(a.begin(),a.end(),back_inserter(b));
        vector<vector<int>> dp(a.size(),vector<int>(a.size(),-1));
        return commonsebsequence(a.length()-1,b.length()-1,a,b,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends