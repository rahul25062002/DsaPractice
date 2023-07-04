//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    //tabulation methods 
	    
	    int pre=arr[0],pre2=0;
	    for(int i=1;i<n;i++){
	        int take=arr[i]+pre2; // decide  to take in that case sec.last will be add to give sum up to i index
	        int nottake=0+pre;   // decide not to take in that case last element will be take 
	        pre2=pre;
	        pre=max(take,nottake);  // max of takeand nottake give ans to current i ;
	        // now pre give the max sum that can be find till index i
	    }
	    
	    return pre;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends