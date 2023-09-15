//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
     int totsum(int N,int arr[],int sum,int curr, vector<vector<int>> &dp){
         if(sum==0) return 1;
         if(curr<0)  return 0;

         
          // not take
          if(dp[curr][sum]!=-1) return dp[curr][sum];
          int nottake=totsum(N,arr,sum,curr-1,dp);
          
          int take=0;
          if(arr[curr]<=sum){
              take=totsum(N,arr,sum-arr[curr],curr-1,dp);
          }
          
          return  dp[curr][sum]= take || nottake;
     }
    
public:
    int equalPartition(int N, int arr[])
    {
        // code here
               long long tot=0;
               for(int i=0;i<N;i++){
                   tot+=arr[i];
               }
               if(tot%2==1) return 0;
               long long sum=tot/2;
              vector<vector<int>> dp(N,vector<int>(sum+1,-1));
             return totsum(N,arr,tot/2,N-1,dp);
            
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends