//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{
private:
    bool fun(int index,int target,vector<int>arr, vector<vector<int>> &dp ){
        if(target==0) return true;
        if(index==0){
            if(arr[index]==target) return true;
            else return false;
            
        }
        if(dp[index][target]!=-1) return dp[index][target];
        bool nottake=fun(index-1,target,arr,dp);
        bool take=false;
        if(arr[index]<=target) take=fun(index-1,target-arr[index],arr,dp);
        return dp[index][target]= (take or nottake);
    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,-1));
        if(arr[0]<sum) dp[0][sum]=1;
        return fun(arr.size()-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends