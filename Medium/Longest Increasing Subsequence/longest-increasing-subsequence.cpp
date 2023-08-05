//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{  
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int>vr;
        
        for(int i=0;i<n;i++)
        {
            auto it = lower_bound(vr.begin(),vr.end(),a[i]);
            if(it==vr.end())
            {
              vr.push_back(a[i]);   
            }
            else
            {
                vr[it-vr.begin()] = a[i];
            }
        }
        
        return (int)vr.size();
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends