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
        
        int s=0,l=n-1,m=(s+l)/2;
        
        int start=-1;int last=-1;
        while(s<=l){
          if(arr[m]==x){
              if(start==-1){
                  
              if(m>0){
              if(arr[m-1]==x) l=m;
                   
              else {
                  start=m; s=m;l=n-1;
              }
              } else {start=m ; s=m;l=n-1;}
              }else{
                   if(m<n-1){
              if(arr[m+1]==x) s=m+1;
              else {
                  last=m; break;
              }
                   
              }else{ last=m; break;}
              }
          }
          else if(arr[m]>x){
              l=m-1;
          }
          else s=m+1;
           
          m=(s+l)/2;
        }
        // s=0;l=n-1,m=(s+l)/2;
        //   while(s<=l){
        //   if(arr[m]==x){
        //       if(m<n-1){
        //       if(arr[m+1]==x) s=m+1;
        //       else {
        //           last=m; break;
        //       }
                   
        //       }else{ last=m; break;}
        //   }
        //   else if(arr[m]>x){
        //       l=m;
        //   }
        //   else s=m+1;
           
        //   m=(s+l)/2;
        // }
       if(start!=-1 and last==-1) last=start;
        // if(start==-1 and last!=-1) start=last;
       return {start,last}; 
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