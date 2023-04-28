//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        vector<vector<int>> dis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(c[i][j]=='W'){
                    q.push({1,{i,j}});
                }
            }
        }
        
         while(!q.empty()){
             int value=q.front().first;
             int x=q.front().second.first;
             int y=q.front().second.second;
             q.pop();
             int dr[]={-1,0,1,0};
             int dc[]={0,1,0,-1};
             for(int i=0;i<4;i++){
                 int nrow=x+dr[i];
                 int ncol=y+dc[i];
                 if(nrow>=0 and nrow<n and ncol>=0 and ncol<m   and dis[nrow][ncol]==0 ){
                     if( c[nrow][ncol]=='H'){
                     dis[nrow][ncol]=2*value;
                     q.push({value+1,{nrow,ncol}});
                     }
                     else if(c[nrow][ncol]=='.'){
                        q.push({value+1,{nrow,ncol}}); 
                        dis[nrow][ncol]=-2;
                     }
                         
                 }
             }

         }
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dis[i][j]==0 and c[i][j]=='H') dis[i][j]=-1;
                if(dis[i][j]==-2) dis[i][j]=0;
            }
        }
        return dis;
         
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<char>> c(n,vector<char>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>c[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> res=ob.chefAndWells(n,m,c);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<res[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
// } Driver Code Ends