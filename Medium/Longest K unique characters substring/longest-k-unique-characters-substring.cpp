//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    if(s.size()<k) return -1;
    int i=0,j=0;
    unordered_map<char,int> mp;
    int max_siz=0;
    for(int i=0;i<s.size();i++){
        
        mp[s[i]]++;
        if(mp.size()==k)max_siz=max(max_siz, i - j + 1);
        
        if(mp.size()>k){
            
            while(mp.size()>k){
       
                
            
           mp[s[j]]--;
           if(mp[s[j]]==0){ mp.erase(s[j]);
              
           }
           
           j++;
            }
                
        }
        
    }
    if(max_siz==0) return -1;
    return max_siz;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends