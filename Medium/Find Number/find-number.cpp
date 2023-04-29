//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long n){
        // Code here
        int arr[]={9,1,3,5,7};
        long long ans=0,cur=1;
        while(n!=0){
            ans=arr[n%5]*cur+ans;
            if(n%5==0){
                n=n/5-1;
            }
            else
            n/=5;
            cur*=10;
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends