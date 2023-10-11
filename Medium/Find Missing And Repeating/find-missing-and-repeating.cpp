//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        //x is missing y is repeated
        
        //sum of first n no.
        long long s=((long long)n*(long long)(n+1))/2;
          //sum of squere of first n no.
        long long s2=((long long)n*(long long)(n+1)*(long long)(2*n+1))/6;
        
        long long sum1=0,sum2=0;
        
        for(int i=0;i<n;i++){
            sum1+=arr[i];
            sum2+=(long long)arr[i]*(long long)arr[i];
        }
        
        long long val1=sum1-s;    //y-x
        long long val2=sum2-s2;    //y2-x2
        
        
        val2=val2/val1;  //y+x
        
      long long y=abs((val1+val2)/2);
      
      long long x=abs(y-val1);
      
      int cnt=0;
      for(int i=0;i<n;i++){
          if(arr[i]==y) cnt++;
          
      }
        if(cnt==2) return {(int)y,(int)x};
        
        return  {(int)x,(int)y};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends