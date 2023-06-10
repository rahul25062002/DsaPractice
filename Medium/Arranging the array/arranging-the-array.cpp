//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends
class Solution
{     
    public:
      void merge(int i, int j, int a[]) {
            int mid = (i + j)/2;
            int tempi = i, tempj = mid + 1;
            while(tempi<=mid and a[tempi]<0) {
                tempi++;
            }
            while(tempj<=j and a[tempj]<0) {
                tempj++;
            }
            reverse(a + tempi, a + mid + 1);
            reverse(a + mid + 1, a + tempj);
            reverse(a + tempi, a + tempj);
            return;
        }
        void fun(int i, int j, int a[]) {
            if(i>=j) return;
            int mid = (i + j)/2;
            fun(i, mid, a);
            fun(mid + 1, j, a);
            merge(i,j,a);
            return;
        }
        void Rearrange(int a[], int n)
        {
            // Your code goes here
              fun(0,n - 1,a);
           return;
        }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends