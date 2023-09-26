//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    
    vector<vector<int>> twoSum(vector<int>& arr, int target, int idx) {
        int n = arr.size();
        int i = idx, j = n-1;
        vector<vector<int>> res;
        while(i < j) {
            int currSum = arr[i] + arr[j];
            if(currSum == target) {
                res.push_back({arr[i], arr[j]});
                i++, j--;
                while(arr[i] == arr[i-1] && i < j) i++;
                while(arr[j] == arr[j+1] && i < j) j--;
            } else if(currSum < target) {
                i++; 
            } else if(currSum > target) {
                j--;
            }
        }
        return res;
    }
    
    vector<vector<int>> kSum(vector<int>& arr, int target, int idx, int k) {
        if(k == 2) 
            return twoSum(arr, target, idx);
        int n = arr.size();
        vector<vector<int>> res;
        for(int i = idx; i < n; i++) {
            if(i != idx && arr[i] == arr[i-1]) continue;
            int curr = arr[i];
            vector<vector<int>> rem = kSum(arr, target - curr, i+1, k-1);
            for(auto v: rem) {
                vector<int> temp;
                temp.push_back(curr);
                for(auto it: v) temp.push_back(it);
                res.push_back(temp);
            }
        }
        return res;
    }
    
    vector<vector<int>> fourSum(vector<int> &arr, int k) {
        sort(arr.begin(), arr.end());
        return kSum(arr, k, 0, 4);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends