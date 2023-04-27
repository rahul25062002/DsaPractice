//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    //  NOTE----------Both travesal technique is use in both submission refer it on 
    void dfs(int n,int m,vector<vector<char>>& grid,vector<vector<int>> &visit){
        visit[n][m]=1;
        // queue<pair<int,int>> q;
        int t=grid.size();
        int s=grid[0].size();
        // q.push({n,m});
        // while(!q.empty()){     //-------------redere summision for bfs;
        //     int x=q.front().first;
        //     int y=q.front().second;
        //     q.pop();
            for(int i=-1;i<=1;i++ ){
                for(int j=-1;j<=1;j++){
                    int nx=n+i;
                    int ny=m+j;
                    if(nx>=0 and ny>=0 and nx<t and ny<s and grid[nx][ny]=='1' and visit[nx][ny]!=1){
                        visit[nx][ny]=1;
                       dfs(nx,ny,grid,visit);
                    }
                }
            }
        }
    
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visit(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<visit[i][j]<<" "<<grid[i][j]<<endl;
                if(!visit[i][j] and grid[i][j]=='1'){
                    count++;
                    dfs(i,j,grid,visit);
                }
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends