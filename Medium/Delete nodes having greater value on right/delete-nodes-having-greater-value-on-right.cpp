//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{  
    Node *rever(Node *head){
    
    Node *dummy=NULL;
    
    while(head!=NULL){
        
        Node *newNode=head->next;
        head->next=dummy;
        dummy=head;
        head=newNode;
    }
    
    return dummy;
    }
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        
            Node *head2=rever(head);
            
            int maxtill=head2->data;
            
            Node *temp=head2;
            Node *pre=head2;
            temp=temp->next;
            while(temp!=NULL){
                
                if(temp->data>=maxtill){
                    maxtill=temp->data;
                    pre->next=temp;
                    
                    pre=temp;
                    temp=temp->next;
                }
                else{
                    temp=temp->next; 
                }
                
            }
            pre->next=NULL;
            
            
            
            
            
            
            return rever(head2);
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends