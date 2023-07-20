//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{   private: int fun(int index1,int index2, string &s1, string &s2, vector<vector<int>> &dp){
    if(index1<0 or index2<0) return 0;
    if( dp[index1][index2]!=-1) return  dp[index1][index2];
    if(s1[index1]==s2[index2]) return  dp[index1][index2]=1+fun(index1-1,index2-1,s1,s2,dp);
    return dp[index1][index2]=max(fun(index1-1,index2,s1,s2,dp),fun(index1,index2-1,s1,s2,dp));
}
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
       vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(n-1,m-1,s1,s2,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends