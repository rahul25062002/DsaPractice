//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        // Code here
          int even=0,odd=0;
          int count2=0;
          int count=0;
          int mini=1e9+7;
          for(int i=0;i<n-1;i++){
              if(arr[i]%2==0) even++;
              else odd++;
              if(arr[i]==2)  count2++;
              if(arr[i]==arr[i+1]) count++;
              mini=min(mini,arr[i]);
              
              
          }
          if(arr[n-1]%2==0) even++;
              else odd++;
              if(arr[n-1]==2)  count2++;
              
              mini=min(mini,arr[n-1]);
              if(count==n-1) return arr[0];
              
          int modulo=1e9+7;
          for(int i=0;i<n;i++){
              int temp=arr[i]%mini;

              if(temp!=0 and temp<modulo) modulo=temp; 
          }
          
              
          
          
              
        
      if(odd>0) return 1;
      if(count2>0)return 2;
      if(modulo==1e9+7) return mini;
      return modulo;
        
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
        cout<<ob.minimumNumber(n,arr)<<endl;
    }
}
// } Driver Code Ends