//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            //code here.
             reverse(s.begin(), s.end());
              int i = 0;
              while (i < s.length())
  {
             if (s[i] >= '0' && s[i] <= '9')
    {
                int j = i;
      while (i < s.length() && s[i] >= '0' && s[i] <= '9')
        i++;
      reverse(s.begin() + j, s.begin() + i);
    }
    else
      i++;
  }
  return s;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends