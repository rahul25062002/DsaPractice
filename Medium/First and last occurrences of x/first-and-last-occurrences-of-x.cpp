//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        // code here  
        vector<int>ans;
        if(arr[0] == x) ans.push_back(0);
        for(int i = 1;i<n-1;i++){
            if(arr[i] == x)
            if(arr[i - 1] != arr[i] || arr[i] != arr[i+1]){
                ans.push_back(i);
            }
        }
        if(arr[n - 1] == x) ans.push_back(n - 1);
        if(ans.size() == 1) ans.push_back(ans[0]);
        if(ans.size() == 0)
        return {-1,-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends