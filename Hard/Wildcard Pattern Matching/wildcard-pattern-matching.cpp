//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
 private: int fun(int i,int j,string &s,string &t,vector<vector<int>> &dp){
    //  if(i<0 and j<0) return 1;
    //  if(i<0 and j>=0) {
    //      if(s[0]=='*' or s[0]=='?')
    //      return 1;
    //      else return 0;
         
    //  };
    //  if(i>=0 and j<0){
    //      if(s[0]=='*')
    //      return 1;
    //      else return 0;
         
    //  };
    if(i==0 and j==0 ){
        if(s[i]=='*' or s[i]=='?' or s[i]==t[j]) return 1;
        else return 0;
         
    }
    if(j<0){
       for(int t=0;t<=i;t++){
           if(s[t]!='*') return 0;
           else return 1;
       }
    }
    if(i<0) return 0;
    
     if(dp[i][j]!=-1) return dp[i][j];
     if(s[i]==t[j] or s[i]=='?') return dp[i][j]= fun(i-1,j-1,s,t,dp);
     else if(s[i]=='*'){
     int way1= fun(i-1,j,s,t,dp);
     int way2=fun(i,j-1,s,t,dp);
    return dp[i][j]=(way1 or way2);
     }
     else return 0;
         
 }
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {   
        int n=pattern.size();
        int m=str.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(n-1,m-1,pattern,str,dp);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends