//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        vector<int> res;
        int i=0,j=0;
        
        if(n==1 or m==1){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    res.push_back(matrix[i][j]);
                }
            }
            
            return res;
        }
        while(i<n){
            while(j<m){
               res.push_back(matrix[i][j]); 
               j++;
            }
            j--;i++;
            while(i<n){
                res.push_back(matrix[i][j]);
                i++;
            }
            i--;j--;
              while(j>=0){
               res.push_back(matrix[i][j]); 
               j--;
            }
            j++;
            i--;
              while(i>0){
                res.push_back(matrix[i][j]);
                i--;
            }
            break;
            
        }
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends