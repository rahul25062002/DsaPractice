//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        // code here
        if(K>N*N) return {-1}; 
        sort(A.begin(),A.end());
          sort(B.begin(),B.end());
          
        vector<int> ans;
        priority_queue<pair<int,pair<int,int>>> pq;
        
        pq.push({A[N-1]+B[N-1],{N-1,N-1}});
        
        set<pair<int,int>> st;
        st.insert({N-1,N-1});
        while(!pq.empty()){
            if(K<=0) break;
            auto it=pq.top();
           int sum=it.first;
           
           int x_ind=it.second.first;
           int y_ind=it.second.second;
           pq.pop();
           
           ans.push_back(sum);K--;
           if(y_ind-1>=0){
           int initSiz=st.size(); 
             st.insert({x_ind,y_ind-1});
             if(st.size()>initSiz){
                 
           int sum1=A[x_ind]+B[y_ind-1]; pq.push({sum1,{x_ind,y_ind-1}});
             }
           }
           if(x_ind-1>=0){
            int initSiz=st.size(); 
             st.insert({x_ind-1,y_ind}); 
             if(st.size()>initSiz){
                 
           int sum2=A[x_ind-1]+B[y_ind]; pq.push({sum2,{x_ind-1,y_ind}});
             }
           }
           
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends