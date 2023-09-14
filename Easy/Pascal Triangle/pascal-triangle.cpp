//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        int mod=1e9+7;
        vector<ll> res;
        
        // res.push_back(0);
        res.push_back(1);
        // res.push_back(0);
            vector<ll> temp;
        for(int j=1;j<n;j++){
            
            temp.push_back(1);
            for(int i=1;i<j;i++){
                temp.push_back((res[i-1]+res[i])%mod);
            }
            temp.push_back(1);
            res=temp;
            temp.clear();
        }
        //  vector<ll> ret;
        //  for(int i=1;i<res.size()-1;i++){
        //      ret.push_back(res[i]);
        //  }
    
        return res;
        // code here
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends