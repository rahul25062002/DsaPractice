//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int fun(vector<int>& height,int i, vector<int> &dp){
        if(i==0) return 0;
        if(i==1) return abs(height[i]-height[0]);
        if(dp[i]!=-1) return dp[i];
        int fir=fun(height,i-1,dp) + abs(height[i]-height[i-1]);
        int sec=INT_MAX;
        if(i>1)
         sec=fun(height,i-2,dp)+abs(height[i]-height[i-2]);
         return  dp[i]=min(fir,sec);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n,-1);
        return fun(height,n-1,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends