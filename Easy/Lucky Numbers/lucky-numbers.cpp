//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
    /// here no. itself is not important but its position is important which is 
    //updatae after each operation and decrease by n=n-n/cnt; and all no (which is position
    //of any no) which is divisible by cnt will deleted
    bool checkLucky(int n,int count){
        if(n<count) return 1;
        if(n%count==0) return 0;
        
        n=n-n/count;
        return checkLucky(n,count+1);
        
    }
public:
    bool isLucky(int n) {
        // code here
        return checkLucky(n,2);
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends