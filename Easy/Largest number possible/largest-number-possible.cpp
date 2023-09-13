//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        if(S>9*N) return "-1";
        if(S==0) {
            if(N==1) return "0";
            return "-1";
        }
        
         string req="";
        int temp=9;
        while(N--){
            // req=req*10;
            
            if(temp<S){
                req+= to_string(temp);
                S-=temp;
            }
            else {
                req+= to_string(S);
                S=0;
                
            }
            
        }
        
        return req;
              
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends