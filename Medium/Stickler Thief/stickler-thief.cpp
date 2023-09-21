//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int maximumSum(int arr[],int n,int i,int dp[]){
        if(i>=n) return 0;
        if(dp[i]!=0) return dp[i];
        int sum1=arr[i]+maximumSum(arr,n,i+2,dp);
        
        int sum2=maximumSum(arr,n,i+1,dp);
        return dp[i]= max(sum1,sum2);
        
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        int dp1[n+1]={0};
        int dp2[n+1]={0};
        int  sum1=arr[0]+maximumSum(arr,n,2,dp1);
        int sum2=arr[1]+maximumSum(arr,n,3,dp2);
        
        return max(sum1,sum2);
        
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends