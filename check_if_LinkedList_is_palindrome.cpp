//c++ code fpr checkinh if a given Linked List is Palindrome or not.
//return 1 if palindrome else return 0
//time complexity -> O[n]
//space complexity(excluding linked list size) ->O[1]

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
	Node(int x){
		data=x;
		next=NULL;
	}
};

Node* reverse(Node* head)
{
    Node *curr=head,*prev=NULL,*next=NULL;
    while(curr)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

bool isPalindrome(Node *head)
{
    if(!head)
    return 1;
    Node* slow=head,*fast=head;
    
    //finding the mid from where we will reverse the list(slow pointer)
    while(fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    
    slow=reverse(slow);
    Node *temp=slow;        //storing the head of reversed list(last node),so that if later we want to obtain original LL we can again reverse it 
    fast=head;
    while(slow)
    {
        if(slow->data!=fast->data)
        return 0;
        slow=slow->next;
        fast=fast->next;
    }
    
    
    reverse(temp);     //reversing the prev reversed LL to obtain original LL
    
    return true;
}

int main(){
	int T,i,n,l,firstdata;
	cin>>T;
	while(T--)
	{
		struct Node* head=NULL,*tail=NULL;
		cin>>n;

		cin>>firstdata;
		head=new Node(firstdata);
		tail=head;

		for(i=1;i<n;i++)
		{
			cin>>l;
			tail->next=new Node(l);
			tail=tail->next;
		}
		cout<<isPalindrome(head)<<endl;
	}
	return 0;
}
