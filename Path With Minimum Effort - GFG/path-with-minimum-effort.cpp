//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size();
         int m=heights[0].size();
        vector<vector<int>> diff(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        diff[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
           int difference=pq.top().first;
           int row=pq.top().second.first;
           int col=pq.top().second.second;
            pq.pop();
           int drow[]={-1,0,1,0};
           int dcol[]={0,1,0,-1};
           if(row==n-1 and col==m-1) return difference;
           for(int i=0;i<4;i++){
               int nrow=row+drow[i];
               int ncol=col+dcol[i];
              
               if(nrow>=0 and nrow<n and ncol>=0 and ncol<m){
                   int ndiff=max(abs(heights[row][col]-heights[nrow][ncol]),difference);
                   if(ndiff<diff[nrow][ncol]){
                       pq.push({ndiff,{nrow,ncol}});
                       diff[nrow][ncol]=ndiff;
                   }
               }
           }
        }
        return -1;
       
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends