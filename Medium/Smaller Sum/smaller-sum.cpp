//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        unordered_map<int,int> mp;
       vector<int> v=arr;
       sort(v.begin(),v.end());
       vector<long long> presum;
       presum.push_back(0);
       long long sum=presum[0];
       for(int i=0;i<n-1;i++){
           sum+=v[i];
           presum.push_back(sum);
       }
       
       for(int i=0;i<n;i++){
           if(mp.find(v[i])==mp.end())
           mp[v[i]]=i;
       }
    //   cout<<mp[5]<<"*"<<endl;
       vector<long long> result;
       for(int i=0;i<n;i++){
           result.push_back(presum[mp[arr[i]]]);
       }
       
       return result;
           
           
           
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends