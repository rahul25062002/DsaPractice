//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        if(n==1) return 1;
        long long postsum[n];
        postsum[n-1]={a[n-1]};
        
        long long presum[n]={a[0]};
        
        for(int i=1;i<n;i++){
            presum[i]=a[i]+presum[i-1];
        }
         for(int i=n-2;i>=0;i--){
            postsum[i]=a[i]+postsum[i+1];
        }
        
        for(int i=0;i<n;i++){
            if(presum[i]-a[i]==postsum[i]-a[i]) return i+1;
        }
        
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends