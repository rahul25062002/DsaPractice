//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class node{
    
    public:
    int data;
    node *pre;
    
    node(int val):data(val),pre(NULL){};
};
class Solution {
     node * multiplyer(node * head,int n){
      int carry=0;
      node *retainHead=head;
      node *preNode=NULL;
      
      while(head!=NULL){
          
          int temp=head->data*n+carry;
          head->data=temp%10;
          carry=temp/10;
          preNode=head;
          head=head->pre;
          
      }
      while(carry){
          node * newNode=new node(carry%10);
          preNode->pre=newNode;
          preNode=newNode;
          carry=carry/10;
      }
      
      
         
       return retainHead;  
         
     }
    
public:
    vector<int> factorial(int n){
        // code here
        
        node *head=new node(1);
        
        for(int i=2;i<=n;i++){
            
            head=multiplyer(head,i);
        }
          
            
        
        vector<int> res;
        while(head!=NULL){
            res.push_back(head->data);
            head=head->pre;
        }
        
        reverse(res.begin(),res.end());
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends