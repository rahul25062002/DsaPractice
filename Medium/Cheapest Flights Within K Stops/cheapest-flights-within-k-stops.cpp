//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dis(n,1e9);
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,src}});
        dis[src]=0;
        int min_price=1e9;
        while(!pq.empty()){
            auto pt=pq.top();
            pq.pop();
            int price=pt.second.first; 
            int node=pt.second.second;
            int stopage=pt.first; 
            // if(node==dst and stopage<=k+1){ min_price=min(min_price,price); continue;}
            // if(stopage>k+1) continue;
            for(auto it:adj[node]){
                int newnode=it.first;
                int lumpsum=it.second+price;
                if(lumpsum<=dis[newnode] and stopage<=k){
                    dis[newnode]=lumpsum;
                    pq.push({stopage+1,{lumpsum,newnode}});
                }
            }
        }
        
        if(dis[dst]==1e9)
        return -1;
        return dis[dst];
        
            
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends