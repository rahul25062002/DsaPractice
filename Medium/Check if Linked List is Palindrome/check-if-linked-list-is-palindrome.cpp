//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
    Node *reverseLinklist(Node *head){
        Node *pre=NULL;
        while(head!=NULL){
            Node* nexts=head->next;
            head->next=pre;
            pre=head;
            head=nexts;
        }
        return pre;
    }
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        long long int sum1=0,sum2=0;
        Node *temp=head;
      
        while(temp!=NULL){
            sum1+=temp->data;

            sum1*=10;
            temp=temp->next;
        }
          Node *head2=reverseLinklist(head);
         while(head2!=NULL){
            sum2+=head2->data;
            sum2*=10;
            head2=head2->next;
        }
        if(sum1==sum2) return 1;
      
        return 0;
        
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends