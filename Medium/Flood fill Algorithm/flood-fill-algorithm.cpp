//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    //     // Code here 
    //     int n=image.size();
    //     int m=image[0].size();
    //     vector<vector<int>> ans = image;
    //     vector<vector<int>>vis(n,vector<int>(m,0));
    //     queue<pair<int,int>>q;
    //     q.push({sr,sc});
    //     vis[sr][sc] =1;
    //     int prevColor= image[sr][sc];
    //     while(!q.empty()){
    //         int row = q.front().first;
    //         int col = q.front().second;
    //         q.pop();
    //         ans[row][col] = newColor;
    //         int delr[] ={-1,0,+1,0};
    //         int delc[] ={0,+1,0,-1};
            
    //         for(int i=0;i<4;i++){
    //             int nrow = row+delr[i];
    //             int ncol = col+delc[i];
    //             if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]==prevColor
    //             and !vis[nrow][ncol]){
    //                 vis[nrow][ncol]=1;
    //                 q.push({nrow,ncol});
    //             }
    //         }
    //     }
    //     return ans;
        
    // }
    
    void dfs(vector<vector<int>>& image,int sr, int sc, int newColor,int prevColor,vector<vector<int>> &vis,vector<vector<int>> & ans){
         vis[sr][sc]=1;
        int n=image.size();
        int m=image[0].size();
           
            ans[sr][sc] = newColor;
            int delr[] ={-1,0,+1,0};
            int delc[] ={0,+1,0,-1};
         for(int i=0;i<4;i++){
                int nrow = sr+delr[i];
                int ncol = sc+delc[i];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and image[nrow][ncol]==prevColor
                and !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                   dfs(image,nrow,ncol,newColor, prevColor,vis,ans);
                }
        
    }}
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>> ans = image;
        vector<vector<int>>vis(n,vector<int>(m,0));
       
        vis[sr][sc] =1;
        int prevColor= image[sr][sc];
        dfs(image,sr,sc,newColor, prevColor,vis,ans);
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends