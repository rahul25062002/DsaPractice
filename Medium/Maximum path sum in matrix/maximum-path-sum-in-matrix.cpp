//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int dp[N][N];
        for(int i=0;i<N;i++){
            dp[0][i]=Matrix[0][i];
        }
        int mini=-1e9;
        for(int i=1;i<N;i++){
            for(int j=0;j<N;j++){
                int up=dp[i-1][j]+Matrix[i][j];
                int ld=mini;
                if(j>0) ld=dp[i-1][j-1]+Matrix[i][j];
                int rd=mini;
                if(j<N-1) rd=dp[i-1][j+1]+Matrix[i][j];
                
                dp[i][j]=max(up,max(ld,rd));
            }
        }
        
        int maxi=dp[N-1][0];
        for(int i=1;i<N;i++){
            maxi=max(maxi,dp[N-1][i]);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends