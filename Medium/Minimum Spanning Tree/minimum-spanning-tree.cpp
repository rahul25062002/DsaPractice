//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet{
    vector<int> siz,parent;
    public :
    // constructor 
    DisjointSet(int n){
        siz.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int node){
        if(parent[node]==node){
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void UnionBySize(int u,int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(siz[ulp_u]>siz[ulp_v]){
            parent[ulp_v]=ulp_u;
            siz[ulp_u]+=siz[ulp_v];
        }
        else{
            parent[ulp_u]=ulp_v;
            siz[ulp_v]+=siz[ulp_u];
        }
        return;

    }

};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {    DisjointSet ds(V);
        vector<pair<int,pair<int,int>>> list;
        for(int i=0;i<V;i++){
            int node=i;
            for(int j=0;j<adj[i].size();j++)
            list.push_back({adj[i][j][1],{adj[i][j][0],node}});
        }
        sort(list.begin(),list.end());
        int mst=0;
        for(int i=0;i<list.size();i++){
            int wt=list[i].first;
            int pt1=list[i].second.first;
            int pt2=list[i].second.second;
            
            if(ds.findUPar(pt1)!=ds.findUPar(pt2)){
                mst+=wt;
                ds.UnionBySize(pt1,pt2);
            }
        }
           return mst;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends