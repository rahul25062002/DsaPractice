//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  bool  isPalindrome(string s){
      int st=0,ls=s.size()-1;
      while(ls>st){
          if(s[st]!=s[ls]) return 0;
          st++;ls--;
      }
      return 1;
  }
public:
    bool makePalindrome(int n,vector<string> &arr){
        // Code here
        unordered_set<string> st;
        for(int i=0;i<n;i++){
            string temp1=arr[i];
            string temp2=string(temp1.rbegin(), temp1.rend());
            if(st.find(temp1)==st.end() and st.find(temp2)==st.end()){
                st.insert(temp2);
            }
            else if(st.find(temp1)!=st.end() ){
                st.erase(st.find(temp1));
            }
            else{
                st.insert(temp2);
            }
            
        }
        if(st.size()==0) return 1;
        else if(st.size()==1) {
            string s=*st.begin();
            st.erase(st.begin());
           return  isPalindrome(s);
        }
        else return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends