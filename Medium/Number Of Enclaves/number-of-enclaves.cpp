//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dummy(n,vector<int>(m,0));
        vector<vector<int>> grid2=grid;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(i==0 or j==0 or i==n-1 or j==m-1){
                if(grid2[i][j]==1){
                    q.push({i,j});
                    dummy[i][j]=1;
                    grid2[i][j]=-1;
                    
                }
            }
        }
    }
    
    while(!q.empty()){
        
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        int xdir[]={-1,0,1,0};
        int ydir[]={0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nx=x+xdir[i];
            int ny=y+ydir[i];
            
            if(nx>=0 and nx<n and ny>=0 and ny<m and grid2[nx][ny]==1 and  dummy[nx][ny]==0 ){
                grid2[nx][ny]=-1;
                dummy[nx][ny]=1;
                q.push({nx,ny});
                
            }
            
            
        }
        
        
    }
    
    int count=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            if(grid2[i][j]==1){
                count++;
            }
               
        }
        
       
    }
    
    
    return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends