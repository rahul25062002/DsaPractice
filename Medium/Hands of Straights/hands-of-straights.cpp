//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int groupSize, vector<int> &hand) {
        // code here
        if(n%groupSize!=0) return 0;
        int j=n/groupSize;
        map<int,int> mp;
        //int,count
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        int cnt=0;
        while(!mp.empty()){
            
           auto it=mp.begin();
           int pt;
           for(int i=0;i<groupSize;i++){
              int x=it->first;
              int y=it->second;
              mp[x]--;
              if(mp[x]==0) mp.erase(mp.find(x));
              if(i!=0){
                if(x-pt>1) return 0;
                if(x-pt<1) return 0;
         
                it++;pt=x; 
               }
               else{
        
                 it++;pt=x;
                   
               }
               
           }
           cnt++;
        }  
        // cout<<cnt;
    if(cnt==j) return 1;return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends