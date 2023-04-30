//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int powerfullInteger(int n,vector<vector<int>> &intervals,int k){
        // Code here
       map<int,int> mp;
       for(auto it:intervals){
           mp[it[0]]++;
           mp[it[1]+1]--;
       }
       auto it=mp.begin();
       int temp=it->second;it++;
       while(it!=mp.end()){
           it->second+=temp;
           temp=it->second;
           it++;
       }
         int ans=-1;
         it=mp.begin();
         
       while(it!=mp.end()){
           if(it->second>=k){
               it++;
               ans=it->first;
           }else 
           it++;
       }
    //   cout<<ans<<endl;
    //   for(auto its:mp){
    //       cout<<its.first<<" "<<its.second<<endl;
    //   }
       if(ans!=-1){
           return --ans;
       }
      
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n;
        vector<vector<int>> intervals(n,vector<int>(2));
        for(int i=0;i<n;i++){
            cin>>intervals[i][0]>>intervals[i][1];
        }
        cin>>k;
        Solution ob;
        cout<<ob.powerfullInteger(n,intervals,k)<<endl;
    }
    return 0;
}
// } Driver Code Ends