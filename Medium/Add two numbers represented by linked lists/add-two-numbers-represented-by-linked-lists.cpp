//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{   struct Node* reverselist(struct Node* head){
    Node * dummy=NULL;
    Node *nextnode=NULL;
    while(head!=NULL){
        nextnode=head->next;
        head->next=dummy;
        dummy=head;
        head=nextnode;
    }
     return dummy;
    
    
    
}
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reverselist(first);
        second=reverselist(second);
        Node *res=new Node(0);
        Node * head=res;
        

        int carry=0;
        while(first!=NULL || second!=NULL || carry){
            int sum=0;
            if(first!=NULL){
                sum+=first->data;
                first=first->next;
            }
            if(second!=NULL){
                 sum+=second->data;
                 second=second->next;
            }
            if(carry!=0){
                sum+=carry;
            }
            Node *newNode=new Node(sum%10);
            
            carry=sum/10;
             head->next=newNode;
             head=head->next;
        }
        
        
        
       res=res->next;
       
        
        return  reverselist(res) ;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends